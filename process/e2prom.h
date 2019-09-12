/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 14:45:42
 */
#ifndef __E2PROM_H__
#define __E2PROM_H__

struct WIFI_CONFIG
{
    String SSID;
    String PASS_WORD;
};

struct HTTP_CONFIG
{
    String HOST;
    uint16_t PROT;
};

struct MQTT_CONFIG
{
    String HOST;
    uint16_t PASS_WORD;
    String CLIENT_ID;
    String USER_NAME;
    String PASS_WORD;
};

template <class T>
void write_config(uint16_t,T const &);
template <class T>
void read_config(uint16_t,T const &);
#endif