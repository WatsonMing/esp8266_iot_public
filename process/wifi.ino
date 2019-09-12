/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 15:38:52
 */
#include <ESP8266WiFi.h>

/**
 * @name: wifi开启连接
 * @msg: 
 * @param {type} 
 * @return: 
 */
void wifi_start(String ssid, String passWord)
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, passWord);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}