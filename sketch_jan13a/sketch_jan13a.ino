#include <Arduino_FreeRTOS.h>
#include <semphr.h>

void vTaskMain(void *pvParameters);

const char *t1_arg = "| \n";
const char *t2_arg = " |\n";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  //  xTaskCreate(t1_main, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  //  xTaskCreate(t2_main, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);

  xTaskCreate(t_main, NULL, configMINIMAL_STACK_SIZE, (void *)t1_arg, 1, NULL);
  xTaskCreate(t_main, NULL, configMINIMAL_STACK_SIZE, (void *)t2_arg, 2, NULL);

  vTaskStartScheduler();
  while (true);
}

void t_main(void *arg) {
  const char * t_arg = (const char *)arg;
  while (true) {
    noInterrupts();
    Serial.print(t_arg);
    interrupts();

    vTaskDelay(250 / portTICK_PERIOD_MS); // 0.25 second delay, time delay function: vTaskDelay
    //portTICK_PERIOD_MS : 16 milliseconds -> 250 / 16 = 15 ticks (15.625) -> 240milliseconds delay
  }
}

void t1_main(void *arg) {
  while (true) {
    noInterrupts();
    Serial.println("| ");
    interrupts();
  }
}

void t2_main(void *arg) {
  while (true) {
    noInterrupts();
    Serial.println(" |");
    interrupts();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
