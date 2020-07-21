#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
const char* ssid = "somu";
const char* password = "9611426563";
float val;
float resolution = 3.3/1023;
int tempPin = A0;

WiFiClient client;
unsigned long myChannelNumber = 808049;
const char * myWriteAPIKey = "MENPEYVOHNVUXDQZ";
void setup() {
Serial.begin(115200);
delay(10);

WiFi.begin(ssid, password);
// Connect to WiFi network
ThingSpeak.begin(client);
}

void loop() {
val = (analogRead(tempPin)* resolution) *100;
Serial.print("TEMPRATURE = ");l
Serial.print(val);
Serial.print("*C");
Serial.println();
delay(1000);
ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);

delay(20000); 
}
