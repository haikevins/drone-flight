#include "common/parameters.h"

float ax = 0.0f;
float ay = 0.0f;
float az = 0.0f;

float gx = 0.0f;
float gy = 0.0f;
float gz = 0.0f;

float g_motor_throttle_base = 1200.0f;

attitude_data_packet_t g_espnow_attitude_data = 
{
    0.0f,
    0.0f,
    0.0f
};

command_data_packet_t g_espnow_command_data = 
{
    false
};

uint32_t g_espnow_trans_last_time = 0;