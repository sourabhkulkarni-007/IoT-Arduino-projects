#include <ESP8266WiFi.h>
#define trigPin D3  // These lines assign names to values
#define echoPin D4  // so they can be easily identified.
#define buzzer D0  // These are set before the code

const char ssid[20] = "HomeSer";
const char password[20] = "mynameisthere";


WiFiServer server(80);

void setup() {
   Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(buzzer, OUTPUT);


    Serial.begin(115200);
    delay(10);
    
     pinMode(D5, OUTPUT);
   pinMode(D6, OUTPUT);
    pinMode(D1, OUTPUT);
    Serial.println("");
    Serial.println("Server-------------------------------");
    Serial.print("Configuring access point");
    WiFi.mode(WIFI_AP);           
    WiFi.softAP(ssid, password);
    //WiFi.begin(ssid, password);

    Serial.println("");
    Serial.print("Hotspot Created : ");
    Serial.println(WiFi.softAPIP());

  // Start the server
    server.begin();
    Serial.println("Server started");
    Serial.println("-------------------------------------");
    Serial.println("");
}
void loop() {
   long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
    Serial.println(" cm");
// Check if a client has connected
    WiFiClient client = server.available();
    if (!client) {
      return;
    }
// Wait until the client sends some data
    Serial.println("new client");
    while(!client.available()){
      delay(1);
    }
// Read the first line of the request
    String request = client.readStringUntil('\r');
    Serial.print("Request: ");
    Serial.println(request);
    client.flush();
    
// Match the request
if (distance > 31 and distance < 40) { 
    tone(buzzer,100,80);  // Intermitten beeps
       digitalWrite(D5, HIGH);
      digitalWrite(D6, LOW);
      digitalWrite(D1, HIGH);
      value = LOW;
    }
     if (distance > 21 and distance < 30) { 
    tone(buzzer,100,50); // Long solid beep
      digitalWrite(D1, LOW);
      digitalWrite(D5, HIGH);
      digitalWrite(D6, HIGH);
      value = LOW;
  }
   if (distance > 11 and distance < 20) { 
    tone(buzzer,100,20); // Long solid beep
      digitalWrite(D5, LOW);
      digitalWrite(D6, LOW);
      digitalWrite(D1, LOW);
      value = LOW;
  }
    if (distance > 0 and distance < 10) { 
    tone(buzzer,100);
     digitalWrite(D5, LOW);
      digitalWrite(D6, HIGH);
      digitalWrite(D1, HIGH);
      value = HIGH;
  }
  else {
    }
  delay (500);
    
v
