
#include <WiFi.h>

#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

void reconnectmqttserver() {
while (!client.connected()) {
Serial.print("Attempting MQTT connection...");
String clientId = "ESP32Client-";
 clientId += String(random(0xffff), HEX);
if (client.connect(clientId.c_str())) {
Serial.println("connected");
  client.subscribe("motion");
} else {
Serial.print("failed, rc=");
Serial.print(client.state());
Serial.println(" try again in 5 seconds");
delay(5000);
}
}
}

void callback(char* topic, byte* payload, unsigned int length) {
  String MQTT_DATA = "";
  for (int i=0;i<length;i++) {
   MQTT_DATA += (char)payload[i];}
  if (MQTT_DATA == "stop") {
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);

  }
  if (MQTT_DATA == "front") {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);

  }
  if (MQTT_DATA == "back") {
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);

  }
  if (MQTT_DATA == "right") {
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);

  }
  if (MQTT_DATA == "left") {
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);

  }

}

void setup()
{
Serial.begin(9600);

  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("Airtel_dhruv_7474","air65896");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
  client.setServer("192.168.1.7", 1883);
  client.setCallback(callback);

pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}


void loop()
{

    if (!client.connected()) {
    reconnectmqttserver();
    }
    client.loop();

}
