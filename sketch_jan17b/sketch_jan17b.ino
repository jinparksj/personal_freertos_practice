#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Synology";
const char* passwd = "Goecoli321";

const int HTTP_PORT = 80;
ESP8266WebServer webServer(HTTP_PORT);

uint8_t ledESP12 = D0; //16
uint8_t ledNodeMCU = D4; //12

const int LED_ON = LOW;
const int LEF_OFF = HIGH;
bool ledESP12_ON = false;
bool ledNodeMCU_ON = false;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  while (!Serial);
  pinMode(ledESP12, OUTPUT);
  pinMode(ledNodeMCU, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, passwd);

  Serial.print("\nConnection to ");
  Serial.println(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.println();
  Serial.print("connected!, address=");
  Serial.println(WiFi.localIP()); //address=10.1.14.81

  //HTTP Request Function
  webServer.on("/", handle_OnConnect);
}

void loop() {
  // put your main code here, to run repeatedly:

}
