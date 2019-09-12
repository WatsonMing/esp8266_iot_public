/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 21:48:20
 */
#ifndef __FLASH_CONTROL_H__
#define __FLASH_CONTROL_H__

struct WIFI_CONFIG
{
    char *SSID;      //15
    char *PASS_WORD; //15
};

struct HTTP_CONFIG
{
    char *HOST; //16
    short PORT; //2
};

struct MQTT_CONFIG
{
    char *HOST;      //16
    short PORT;      //2
    char *CLIENT_ID; //11
    char *USER_NAME; //16
    char *PASS_WORD; //16
};

template <class T>
void write_config(short, T);
template <class T>
void read_config(short, T);

#endif