/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 17:04:20
 */
#include "network.h"
#include <e2prom.h>

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
void read()
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
    read();//读取配置文件
    WiFi.mode(WIFI_STA);
    WiFi.begin(wifi_config.SSID, wifi_config.PASS_WORD);
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

void wifi_connect()
{
    client.setServer(mqtt_config.HOST, mqtt_config.PORT);
    client.setCallback(callback);
    reconnect();
}

// function called when a MQTT message arrived
void callback(char *p_topic, byte *p_payload, unsigned int p_length)
{
    // concat the payload into a string
    String payload;
    Serial.println("INFO:callback...");
    for (uint8_t i = 0; i < p_length; i++)
    {
        payload.concat((char)p_payload[i]);
    }

    // handle message topic
    // if (String(MQTT_LASOR_COMMAND_TOPIC).equals(p_topic))
    // {
    //     if (payload.equals(String(DEVICE_ON)))
    //     {
    //         lightSstate = true;
    //     }
    //     else if (payload.equals(String(DEVICE_OFF)))
    //     {
    //         lightSstate = false;
    //     }
    //     setLasorState();
    //     publishLasorState();
    // }
    // else if (String(MQTT_FAN_COMMAND_TOPIC).equals(p_topic))
    // {
    //     if (payload.equals(String(DEVICE_ON)))
    //     {
    //         fanState = true;
    //     }
    //     else if (payload.equals(String(DEVICE_OFF)))
    //     {
    //         fanState = false;
    //     }
    //     setFanState();
    //     publishFanState();
    // }
}

void reconnect()
{
    // Loop until we're reconnected
    while (!client.connected())
    {
        Serial.print("INFO: Attempting MQTT connection...");
        // Attempt to connect
        if (client.connect(mqtt_config.CLIENT_ID, mqtt_config.USER_NAME, mqtt_config.PASS_WORD))
        {
            Serial.println("INFO: connected");
            // Once connected, publish an announcement...
            // publishLasorState();
            // publishFanState();
            // ... and resubscribe
            // client.subscribe(MQTT_LASOR_COMMAND_TOPIC);
            // client.subscribe(MQTT_FAN_COMMAND_TOPIC);
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
