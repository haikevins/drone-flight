#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <Arduino.h>
#include "communication/espnow_protocol.h"

extern float ax;
extern float ay;
extern float az;

extern float gx;
extern float gy;
extern float gz;

extern float g_motor_throttle_base;

extern attitude_data_packet_t g_espnow_attitude_data;
extern command_data_packet_t g_espnow_command_data;

extern uint32_t g_espnow_trans_last_time;

static constexpr float target_roll_angle = 0.0f;
static constexpr float target_pitch_angle = 0.0f;
static constexpr float target_yaw_angle = 0.0f;

static constexpr uint8_t g_imu_pin_sck = 4u;
static constexpr uint8_t g_imu_pin_miso = 5u;
static constexpr uint8_t g_imu_pin_mosi = 6u;
static constexpr uint8_t g_imu_pin_ncs = 7u;

static constexpr float g_imu_read_default_hz = 1000.0f;

static constexpr float g_imu_gyro_lpf_alpha = 0.22f;
static constexpr float g_imu_accel_lpf_alpha = 0.10f;

static constexpr float g_espnow_trans_period_ms = 1000.0f;

#endif