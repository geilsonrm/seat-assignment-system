#include <WiFi.h>
#include <SoftwareSerial.h>
#include "Arduino.h"

extern SoftwareSerial wifiSerial;
extern int seatStatus;
extern byte UIDStored[4];
extern int timeRemained;

void uploadData() {
  //  wifiSerial.begin(9600);
  //  Serial.begin(9600);
  //  while (!Serial);
  wifiSerial.println("AT+CIPSTART=\"TCP\",\"140.112.94.163\",9488");
  delay(1000);
  //strcpy((char *)UIDStored, "0123");
  String UID = String((char *)UIDStored);
  String data = "{\"id\":";
  data += UID;
  data += ",\"status\":";
  data += seatStatus;
  data += ",\"time\":";
  data += String(timeRemained);
  data += "}";

  String cmd = "GET /?tmp=2736 HTTP/1.0\r\n\r\n";
  wifiSerial.print("AT+CIPSEND=");
  wifiSerial.println(data.length());
  delay(1000);
  wifiSerial.print(data);
}

