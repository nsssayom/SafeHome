#include "gsm.hpp"
#define SerialMon Serial

void Gsm::init_gsm() {
    this->SerialAT.begin(9600);
    delay (1000);
    
    SerialMon.println("Initializing modem...");
    this->modem.restart();

    String modemInfo = modem.getModemInfo();
    SerialMon.print("Modem: ");
    SerialMon.println(modemInfo);

    // Unlock your SIM card with a PIN if needed
    if (strlen(simPIN) && modem.getSimStatus() != 3) {
        this->modem.simUnlock(simPIN);
    }

    SerialMon.println("Waiting for network...");
    if (!this->modem.waitForNetwork(240000L)) {
        SerialMon.println("Failed to connect to network");
        delay(10000);
        return;
    }

    if (this->modem.isNetworkConnected()) {
        SerialMon.println("Network connected");
    }
}

bool Gsm::send_sms(const String& sms_to, const String& sms_body){
    if (this->modem.sendSMS(sms_to, sms_body)){
        SerialMon.println("SMS sent successfully to " + sms_to);
        return true;
    }
    SerialMon.println("Failed to send SMS to " + sms_to);
    return false;
}
