void handle_OnConnect() {
  if (ledESP12_ON) {
    Serial.print("GPIO16 Status : On | ");
  }
  else {
    Serial.print("GPIO16 Status : Off |");
  }

  if (ledNodeMCU_ON) {
    Serial.print("GPIO2 Status : On");
  }
  else {
    Serial.print("GPIO2 Status : Off");
  }
  Serial.println();

  String html = SendHTML(ledESP12_ON, ledNodeMCU_ON);
  webServer.send(200,  "text/html", html);

}

void handle_led1on() {
  ledESP12_ON = true;
  Serial.println("GPIO16 Status: ON");

  String html = SendHTML(ledESP12_ON, ledNodeMCU_ON);
  webServer.send(200, "text/html", html);
}


void handle_led1off() {
  ledESP12_ON = false;
  Serial.println("GPIO16 Status: OFF");

  String html = SendHTML(ledESP12_ON, ledNodeMCU_ON);
  webServer.send(200, "text/html", html);
}


void handle_led2on() {
  ledNodeMCU_ON = true;
  Serial.println("GPIO2 Status: ON");

  String html = SendHTML(ledESP12_ON, ledNodeMCU_ON);
  webServer.send(200, "text/html", html);
}


void handle_led2off() {
  ledNodeMCU_ON = false;
  Serial.println("GPIO2 Status: OFF");

  String html = SendHTML(ledESP12_ON, ledNodeMCU_ON);
  webServer.send(200, "text/html", html);
}


void handle_NotFound() {
  webServer.send(404, "text/plain", "Not Found");
}
String SendHTML(bool led1_on, bool led2_on) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name\"viewport\" ";
  ptr += "content=\"width=device-width, ";
  ptr += "initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control</title>\n";
  ptr += "<style>html { font-family: Helvetica; ";
  ptr += "display: inline-block; margin: 0px auto; ";
  ptr += "text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;";
  ptr += "margin: 50px auto 30px;} h3 {color: #444444;";
  ptr += "margin-bottom: 50px;}\n";
  ptr += ".button {display: block; width: 80px;";
  ptr += "background-color: #1abc9c;border: none;";
  ptr += "color: white; padding:13px 30px;";
  ptr += "text-decoration: none; font-size: 25px;";
  ptr += "margin: 0px auto 35px;cursor: pointer;";
  ptr += "border-radius: 4px;}\n";
  ptr += ".button-on {background-color: #1abc9c;}\n";
  ptr += ".button-on:active {background-color: #16a085;}\n";
  ptr += ".button-off {background-color: #34495e;}\n";
  ptr += ".button-off:active {background-color: #2c3e50;}\n";
  ptr += "p {font-size: 14px; color: #888;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h1>NodeMCU Web Server</h1>\n";

  if (led1_on) {
    ptr += "<p>LED1 Status: On</p>";
    ptr += "<a class=\"button button-off\"";
    ptr += "href=\"/led1off\">OFF</a>\n";
  }
  else {
    ptr += "<p>LED1 Status: OFF</p>";
    ptr += "<a class=\"button button-on\"";
    ptr += "href=\"/led1on\">ON</a>\n";
  }

  if (led2_on) {
    ptr += "<p>LED2 Status: On</p>";
    ptr += "<a class=\"button button-off\"";
    ptr += "href=\"/led2off\">OFF</a>\n";
  }
  else {
    ptr += "<p>LED2 Status: OFF</p>";
    ptr += "<a class=\"button button-on\"";
    ptr += "href=\"/led2on\">ON</a>\n";
  }

  ptr += "</body>\n";
  ptr += "</html>\n";

  return ptr;

}
