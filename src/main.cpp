#include "global_config.hpp"

// function prototypes
void print_sensor_values(int mq5_value, int ir_value, int vib_value);

// global variable to count sms delaye
int sms_delay_count = 0;

void setup()
{
	sms_delay_count = 0;

	SerialMon.begin(115200);
	SerialMon.println("Booting up device");
	delay(1000);

	gsm_module.init_gsm();
	gsm_module.send_sms(owner_number, "Your device has turned on.");

	SerialMon.println("Initializing Sensors...");
	// Initializing input pin modes
	pinMode(mq5, INPUT);
	pinMode(ir, INPUT);
	pinMode(vib, INPUT);

	// Initializing buzzer pin modes
	pinMode(buzzer, OUTPUT);
}

void loop()
{
	int mq5_value = !digitalRead(mq5);
	int ir_value = !digitalRead(ir);
	int vib_value = !digitalRead(vib);

	// Printing digital sensor values to Serial Monitor
	print_sensor_values(mq5_value, ir_value, vib_value);

	if (mq5_value || ir_value || vib_value){		
		// Check if predefined sms delay has passed
		if (sms_delay_count >= SMS_delay){
			
			// Constructing SMS body
			String SMS_body = "Hazard Alert!!! \r\nSensors:";
			
			// Concating sensor information to the SMS body
			if (mq5_value){
				SMS_body += " Gas ";
			}

			if (ir_value){
				SMS_body += " Fire ";
			}

			if (vib_value){
				SMS_body += " Vibration ";
			}
			SMS_body += "\r\n";
			SMS_body += "Please call 999.";

			// Send sms to the owner
			if (gsm_module.send_sms(owner_number, SMS_body)){
				// Reset sms delay counter
				sms_delay_count = 0;
			}
		}
	}

	// Delaying sensor reading 
	delay(sensor_delay);

	// Incrementing sensor delay count
	sms_delay_count += 	sensor_delay;
}

// Function to print sensor values to Serial Monitor 
void print_sensor_values(int mq5_value, int ir_value, int vib_value)
{
	SerialMon.print("MQ Sensor: ");
	SerialMon.print(mq5_value);
	SerialMon.print("\t");

	SerialMon.print("IR Sensor: ");
	SerialMon.print(ir_value);
	SerialMon.print("\t");

	SerialMon.print("Vibration Sensor: ");
	SerialMon.println(vib_value);
}