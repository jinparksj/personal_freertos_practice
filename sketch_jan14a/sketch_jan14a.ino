#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#define BUF_SIZE 16
int buf[BUF_SIZE] = {0, };
int front = 0;
int reat = 0;
int how_many = 0;
SemaphoreHandle_t button_pressed = NULL;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  
}

void loop() {
  // put your main code here, to run repeatedly:

}
