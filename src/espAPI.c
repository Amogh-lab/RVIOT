#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Your_SSID";        
const char* password = "Your_PASSWORD"; 

const int relayPin = 2;  

WebServer server(80);
void setCORSHeaders() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "POST");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
}
void setup() {
  
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP()); 
  
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  
 
  server.on("/on", HTTP_POST, []() {
    setCORSHeaders();
    digitalWrite(relayPin, HIGH);  
    Serial.println("Light Turned ON");
    server.send(200, "text/plain", "Light ON");
  });

  
  server.on("/off", HTTP_POST, []() {
    setCORSHeaders();
    digitalWrite(relayPin, LOW);  
    Serial.println("Light Turned OFF");
    server.send(200, "text/plain", "Light OFF");
  });
  
  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient();
}
