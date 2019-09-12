/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 16:20:31
 */
#ifndef __NETWORK_H__
#define __NETWORK_H__

#include <config.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <PubSubClientTools.h>

#include <Thread.h>
#include <ThreadController.h>

extern WiFiClient wifiClient;
extern PubSubClient client(wifiClient);

#endif