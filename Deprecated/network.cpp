/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 20:45:29
 */
#include "network.h"


WiFiClient wifiClient;
PubSubClient client(wifiClient);
WIFI_CONFIG wifi_config;
MQTT_CONFIG mqtt_config;
/**
 * @name: 读取配置文件
 * @msg: 
 * @param {type} 
 * @return: 
 */
void read_all()
{
    read_config(EEPROM_WIFI,wifi_config);
    read_config(EEPROM_MQTT,mqtt_config);
}
/**
 * @name: wifi开启连接
 * @msg: 
 * @param {type} 
 * @return: 
 */
void wifi_start()
{
    read_all();//读取配置文件
    WiFi.mode(WIFI_STA);
    WiFi.begin((char *)(wifi_config.SSID), (char *)(wifi_config.PASS_WORD));
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

void mqtt_connect()
{
    client.setServer((char *)(mqtt_config.HOST), (uint16_t)(mqtt_config.PORT));
    client.setCallback(callback);
    reconnect();
}

// function called when a MQTT message arrived
void callback((char *)p_topic, byte *p_payload,uint16_t p_length)
{
    // concat the payload into a string
    uint8_t i;
    String payload;
    Serial.println("INFO:callback...");
    for (i = 0; i < p_length; i++)
    {
        payload.concat((char)p_payload[i]);
    }
    // handle message topic
    if (String(MQTT_SUBSCRIBE).equals(p_topic))
    {
        Serial.println("server>>");
        Serial.println(payload);
    }
}

void reconnect()
{
    // Loop until we're reconnected
    while (!client.connect((char *)(mqtt_config.CLIENT_ID), (char *)(mqtt_config.USER_NAME), (char *)(mqtt_config.PASS_WORD)))
    {
        Serial.print("INFO: Attempting MQTT connection...");
        // Attempt to connect
        if (client.connect((char *)(mqtt_config.CLIENT_ID), (char *)(mqtt_config.USER_NAME), (char *)(mqtt_config.PASS_WORD)))
        {
            Serial.println("INFO: connected");
            // Once connected, publish an announcement...
            client.subscribe((char *)(MQTT_SUBSCRIBE));
            client.publish((char *)(MQTT_PUBLISH),"hello server",strlen("hello server"),false);
        }
        else
        {
            Serial.print("ERROR: failed, rc=");
            Serial.print(client.state());
            Serial.println("DEBUG: try again in 3 seconds");
            // Wait 3 seconds before retrying
            delay(3000);
        }
    }
}
