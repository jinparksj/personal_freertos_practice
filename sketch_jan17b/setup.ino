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

String SendHTML(bool led1_on, bool led2_on) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name\"viewport\" ";
  ptr += "content=\"width=device-width, ";
  ptr += "initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control<\title>\n";
  ptr += "<style>html { font-family: Helvetica; ";
  ptr += "display: inline-block; margin: 0px auto; ";
  ptr += "text-aligh: center;}\n";
  ptr += "body{margin-top";
  ptr += "";
  ptr += "";
  ptr += "";
  ptr += "";
  ptr += "";
  ptr += "";
  ptr += "";
  ptr += "";
  ptr += "";
  ptr += "";
  
  ptr += "";
  
  
}
