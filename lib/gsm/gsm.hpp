#include "gsm_config.h"
#include <Arduino.h>
#include <TinyGsmClient.h>
#include <SoftwareSerial.h>

class Gsm
{
private:
    SoftwareSerial SerialAT = SoftwareSerial(10, 11);
    TinyGsm modem = TinyGsm(SerialAT);

public:
    Gsm(){};
    void init_gsm();
    bool send_sms(const String &sms_to, const String &sms_body);
};