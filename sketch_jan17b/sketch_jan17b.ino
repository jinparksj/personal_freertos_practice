#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "TP-LINK_4CEF";//"Synology";
const char* passwd = "25529029";//"Goecoli321";

const int HTTP_PORT = 80;
ESP8266WebServer webServer(HTTP_PORT);

uint8_t ledESP12 = D0; //16
uint8_t ledNodeMCU = D4; //12

const int LED_ON = LOW;
const int LED_OFF = HIGH;
bool ledESP12_ON = false;
bool ledNodeMCU_ON = false;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  //while (!Serial || (millis() < 10000));
  Serial.println("Serial Done");
  
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
  webServer.on("/led1on", handle_led1on);
  webServer.on("/led1off", handle_led1off);
  webServer.on("/led2on", handle_led2on);
  webServer.on("/led2off", handle_led2off);
  webServer.onNotFound(handle_NotFound);

  webServer.begin();

  Serial.print("HTTP server ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println(" ' to connect");

}

void loop() {
  // put your main code here, to run repeatedly:
  webServer.handleClient();

  if (ledESP12_ON) {
    digitalWrite(ledESP12, LED_ON);
  }
  else {
    digitalWrite(ledESP12, LED_OFF);
  }

  if (ledNodeMCU_ON) {
    digitalWrite(ledNodeMCU, LED_ON);
  }
  else {
    digitalWrite(ledNodeMCU, LED_OFF);
  }
}
