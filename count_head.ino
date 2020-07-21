
/*
 * Interface InfraRed Sensor Using NodeMCU
 * By TheCircuit
 * Red :     5V
 * Brown: Sensor output
 * Black : Ground
*/

 // choose pin for the LED
int inputPin = 13;
int inputPin1 = 2;// choose input pin (for Infrared sensor) 
int val = 0;
int val1 = 0;// variable for reading the pin status 
int count = 1;
int count1 = 1;

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// Replace with your network credentials
const char* ssid = "somu";
const char* password = "9611426563";

ESP8266WebServer server(80);   //instantiate server at port 80 (http port)

String page = "";
double data; 
void setup() 
{ 
   
    // declare LED as output 
   pinMode(inputPin, INPUT);
   pinMode(inputPin1, INPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", [](){
    page = "<h1>Sensor to Node MCU Web Server</h1><h3>Total Heads:</h3> <h4>"+String(count-count1)+"</h4><br><h3>Entered Heads:</h3> <h4>"+String(count)+"</h4><br><h3>Exit Heads:</h3><h4>"+String(count1)+"</h4><br>";
    server.send(200, "text/html", page);
  });
  
  server.begin();
  Serial.println("Web server started!"); // declare Infrared sensor as input
} 
void loop()
{ 
   val = digitalRead(inputPin);
   val1 = digitalRead(inputPin1);// read input value 
   if (val != HIGH)
   { // check if the input is HIGH
      Serial.print("Entry: ");
      Serial.println(count);
      count = count +1;// turn LED OFF   
   }
   if (val1 != HIGH)
   { // check if the input is HIGH
      Serial.print("Exit: ");
      Serial.println(count1);
      count1 = count1 +1;// turn LED OFF   
   }
  server.handleClient();
   delay(1000);
}
