#include <WiFi.h>        
#include <WebServer.h> 

#define RELAY_PIN 5     

const char* ssid = "Your_SSID";        
const char* password = "Your_PASSWORD"; 

WebServer server(80);  
bool relayState = false; 


void toggleRelay() {
  relayState = !relayState;
  digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);  
  server.send(200, "text/html", getHtml());
}


String getHtml() {
  String stateText = relayState ? "ON" : "OFF";
  String buttonText = relayState ? "Turn OFF" : "Turn ON";

  return String(
    "<!DOCTYPE html><html><head><title>Relay Control</title></head><body>"
    "<h1>Relay Control</h1>"
    "<p>Current State: <b>" + stateText + "</b></p>"
    "<button onclick=\"toggleRelay()\">" + buttonText + "</button>"
    "<script>"
    "function toggleRelay() {"
    " fetch('/toggle');"
    " setTimeout(() => location.reload(), 500);"
    "}"
    "</script>"
    "</body></html>"
  );
}

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT); 
  digitalWrite(RELAY_PIN, LOW); 

  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
  Serial.println(WiFi.localIP()); 


  server.on("/", []() { server.send(200, "text/html", getHtml()); });
  server.on("/toggle", toggleRelay);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient(); 
}
