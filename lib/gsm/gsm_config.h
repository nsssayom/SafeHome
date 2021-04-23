// Configure TinyGSM library
#define TINY_GSM_MODEM_SIM800	// Modem is SIM800
#define TINY_GSM_RX_BUFFER 1024 // Set RX buffer to 1Kb

// Define the serial console for debug prints, if needed
//#define TINY_GSM_DEBUG SerialMon
//#define DUMP_AT_COMMANDS

// Define how you're planning to connect to the internet
#define TINY_GSM_USE_GPRS true
#define TINY_GSM_USE_WIFI false

// Uncomment if SSL is necessary
// #define USE_SSL

// GPRS credentials
const char apn[] = "";		// Your APN
const char gprsUser[] = ""; // User
const char gprsPass[] = ""; // Password
const char simPIN[] = "";	// SIM card PIN code, if any

// Server details
const char hostname[] = "vsh.pp.ua";