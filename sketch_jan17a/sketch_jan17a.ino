const int ledESP12 = D0; //16
const int ledNodeMCU = D4; //2
const int LED_ON = LOW;
const int LED_OFF = HIGH;
const int buttonFLASH = D3; //0


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial);

  //  pinMode(ledESP12, OUTPUT);
  //  pinMode(ledNodeMCU, OUTPUT);

  pinMode(buttonFLASH, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello");
  delay(1000);
  //  digitalWrite(ledESP12, LED_ON);
  //  digitalWrite(ledNodeMCU, LED_ON);
  //  delay(1000);
  //  digitalWrite(ledESP12, LED_OFF);
  //  digitalWrite(ledNodeMCU, LED_OFF);
  //  delay(1000);

  //  for (int fadeValue = 1023; fadeValue >= 0; fadeValue--) {
  //    analogWrite(ledESP12, fadeValue);
  //    analogWrite(ledNodeMCU, fadeValue);
  //    delay(1);
  //  }

  int buttonValue = digitalRead(buttonFLASH);
  Serial.println(buttonValue);
}
