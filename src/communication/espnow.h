#ifndef ESPNOW_H
#define ESPNOW_H

#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>

class ESPNow
{
    public:
        ESPNow();
        
        bool begin();
        bool send(const uint8_t* data, size_t len);

        void register_recv_callback(esp_now_recv_cb_t callback);
        void register_send_callback(esp_now_send_cb_t callback);

        static void on_data_sent(const uint8_t *mac_addr, esp_now_send_status_t status);
        static void on_data_recv(const uint8_t *mac_addr, const uint8_t *data, int data_len);

        bool register_peer();

    private:
        // REPLACE WITH YOUR RECEIVER MAC Address
        uint8_t broadcast_address[6] = {0xAC, 0xA7, 0x04, 0xBB, 0x6D, 0x64};

        bool add_peer(const esp_now_peer_info_t* peerInfo);
};

#endif /* ESPNOW_H */