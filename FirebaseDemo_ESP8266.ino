//https://github.com/mobizt/Firebase-ESP8266

#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "iot-trial-3a43d.firebaseio.com"
#define FIREBASE_AUTH "iczp9LuT7xz0I1wGi7KjpS87ilNXROqYFvyZbcRa"
#define WIFI_SSID "kim"
#define WIFI_PASSWORD "kimsang23"

FirebaseData firebaseData;

int fireStatus;
int led = D3;
void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);      
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);          
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt(firebaseData, "led", 0);
}

void loop() {
  if(Firebase.getInt(firebaseData, "/led"))
  {
    fireStatus = firebaseData.intData();
    if (fireStatus == 1) {
      Serial.println("Led Turned ON");                         
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(led, HIGH);
    } 
    else if (fireStatus == 0) {
      Serial.println("Led Turned OFF");
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(led, LOW);
    }
    else {
      Serial.println("Wrong Credential! Please send ON/OFF");
    }
  }
}
