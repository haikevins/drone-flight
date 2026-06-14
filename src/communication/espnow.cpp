#include "communication/espnow.h"

ESPNow::ESPNow()
{
}

bool ESPNow::begin()
{
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK)
    {
        Serial.println("Error initializing ESP-NOW");
        return false;
    }
    return true;
}

bool ESPNow::send(const uint8_t* data, size_t len)
{
    return esp_now_send(broadcast_address, data, len) == ESP_OK;
}

void ESPNow::register_recv_callback(esp_now_recv_cb_t callback)
{
    esp_now_register_recv_cb(callback);
}

void ESPNow::register_send_callback(esp_now_send_cb_t callback)
{
    esp_now_register_send_cb(callback);
}

void ESPNow::on_data_sent(const uint8_t *mac_addr, esp_now_send_status_t status)
{
    Serial.print("\r\nLast Packet Send Status:\t");

    if (status == ESP_NOW_SEND_SUCCESS) 
    {
        Serial.println("Delivery Success");
    } 
    else 
    {
        Serial.println("Delivery Fail");
    }
}

void ESPNow::on_data_recv(const uint8_t *mac_addr, const uint8_t *data, int data_len)
{
    // This function can be used to handle received data if needed
}

bool ESPNow::register_peer()
{
    esp_now_peer_info_t peerInfo;
    memcpy(peerInfo.peer_addr, broadcast_address, 6);

    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    const bool success = add_peer(&peerInfo);

    return success;
    
}

bool ESPNow::add_peer(const esp_now_peer_info_t* peerInfo)
{
    if (esp_now_add_peer(peerInfo) != ESP_OK)
    {
        return false;
    }

    return true;
}