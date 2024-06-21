#define BLYNK_TEMPLATE_ID "TMPL3ED18bvfY"
#define BLYNK_TEMPLATE_NAME "iNeubytes"
#define BLYNK_AUTH_TOKEN "EKHT0kl3_5Ongk-lUGo5CNmr-I2aCnad"

#include <DHTesp.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

#define DHTPIN 15
#define LED_PIN 21
#define SERVO_PIN 14

DHTesp dht;
Servo myservo;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;
bool manualMode = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  dht.setup(DHTPIN, DHTesp::DHT22); // Initialize DHT sensor
  Blynk.begin(auth, ssid, pass);
  myservo.attach(SERVO_PIN);
  timer.setInterval(2000L, sendDHTData); // Send DHT data every 2 seconds
}

BLYNK_WRITE(V1) {
  manualMode = param.asInt();
  if (manualMode) {
    Blynk.setProperty(V2, "enabled", true); // Enable LED control
    Blynk.setProperty(V3, "enabled", true); // Enable Servo control
  } else {
    Blynk.setProperty(V2, "enabled", false); // Disable LED control
    Blynk.setProperty(V3, "enabled", false); // Disable Servo control
    digitalWrite(LED_PIN, LOW); // Ensure LED is off in automatic mode
    myservo.write(0); // Ensure servo is in default position in automatic mode
  }
}

BLYNK_WRITE(V2) {
  if (manualMode) {
    int ledState = param.asInt();
    digitalWrite(LED_PIN, ledState);
  }
}

BLYNK_WRITE(V3) {
  if (manualMode) {
    int motorState = param.asInt();
    if (motorState == 1) {
      myservo.write(90); // Example position, you can adjust as needed
    } else {
      myservo.write(0); // Example position, you can adjust as needed
    }
  }
}

void sendDHTData() {
  float t = dht.getTemperature();
  float h = dht.getHumidity();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (!manualMode) {
    if (t > 35 || t < 12 || h > 70 || h < 40) {
      digitalWrite(LED_PIN, HIGH);
      myservo.write(90); // Example position, you can adjust as needed
    } else {
      digitalWrite(LED_PIN, LOW);
      myservo.write(0); // Example position, you can adjust as needed
    }
  }

  Blynk.virtualWrite(V4, t); // Update to V4 for temperature
  Blynk.virtualWrite(V5, h); // Update to V5 for humidity

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" °C");
}

void loop() {
  Blynk.run();
  timer.run();
}
