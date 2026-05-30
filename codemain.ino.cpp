/*
 * 智忆药盒 - AI语音陪伴式智能用药助手
 * 硬件平台：ESP32-S3
 * 开源协议：MIT License
 */

#include <Arduino.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <PubSubClient.h>

// WiFi配置（请修改为你的WiFi）
const char* ssid = "你的WiFi名称";
const char* password = "你的WiFi密码";

// 引脚定义
#define PIN_BUZZER  12
#define PIN_LED     13
#define PIN_SERVO1  15

Servo servo1;
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  Serial.println("智忆药盒启动中");
  
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  servo1.attach(PIN_SERVO1);
  servo1.write(0);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi已连接");
  
  tone(PIN_BUZZER, 1000, 500);
  delay(500);
  noTone(PIN_BUZZER);
}

void loop() {
  // 模拟语音指令（实际需接入语音识别）
  if (Serial.available()) {
    String cmd = Serial.readString();
    cmd.trim();
    if (cmd == "remind") {
      Serial.println("【语音播报】早上8点，请吃降压药");
      servo1.write(90);
      digitalWrite(PIN_LED, HIGH);
      delay(5000);
      servo1.write(0);
      digitalWrite(PIN_LED, LOW);
    }
  }
  delay(100);
}