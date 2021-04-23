#include <Arduino.h>
#include "gsm.hpp"
#include <Wire.h>

// Pin declarations
#define mq5 A0
#define ir A1
#define vib A2
#define buzzer A3

const String owner_number = "01751194974";

// Sensor delay in ms
const int sensor_delay = 1000;

// Send SMS delay in ms
const int SMS_delay = 60000;

#define SerialMon Serial

// Instantiate global gsm_module object
Gsm gsm_module;