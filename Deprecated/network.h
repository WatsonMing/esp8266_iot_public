/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 20:18:04
 */
#ifndef __NETWORK_H__
#define __NETWORK_H__


#include <ESP8266WiFi.h>
#include <PubSubClient.h>
// #include <PubSubClientTools.h>
#include "config.h"
#include "flash_control.h"
// #include <Thread.h>
// #include <ThreadController.h>

// extern WiFiClient wifiClient;
// extern PubSubClient client(wifiClient);
void callback(char *, byte *, uint16_t);
void wifi_start();
void mqtt_connect();


#endif