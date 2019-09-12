/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 22:25:39
 */
// #include "network.h"
#include "ESP8266MQTT.h"


void onConnectionEstablished();

ESP8266MQTT client(
  "lhj",             // Wifi ssid
  "lhj407407",             // Wifi password
  "39.98.252.81",    // MQTT broker ip
  1883,               // MQTT broker port
  "donmine",              // MQTT username
  "lhj407407",         // MQTT password
  "sn0001",            // Client name
  onConnectionEstablished, // Connection established callback
  true,               // Enable web updater
  true                // Enable debug messages
);

void setup()
{
    Serial.begin(9600); // 设置串口波特率为9600
    while (!Serial)
        ; // 如果串口没有打开，则死循环下去不进行下面的操作
    //wifi_start();
    //mqtt_connect();
}
void loop()
{
    // char incomedate;
    // if (Serial.available() > 0) //串口接收到数据
    // {
    //     incomedate = Serial.read(); //获取串口接收到的数据
    //     if (incomedate == 'H')
    //     {
    //         Serial.println("Good Job!");
    //     }
    // }
    client.loop();
}
void onConnectionEstablished()
{
  // 订阅主题并且将该主题内收到的消息通过串口发送
  client.subscribe("mytopic/test", [](const String &payload) {
    Serial.println(payload);//此处可以编写一个函数来代替
  });

  // 向某个主题发送消息
  client.publish("mytopic/test", "This is a message");

}