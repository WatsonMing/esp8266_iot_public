#ifndef __E2PROM_H__
#define __E2PROM_H__

struct WIFI_CONFIG
{
    String SSID;      //15
    String PASS_WORD; //15
};

struct HTTP_CONFIG
{
    String HOST;   //16
    uint16_t PORT; //2
};

struct MQTT_CONFIG
{
    String HOST;        //16
    uint16_t PORT; //2
    String CLIENT_ID;   //11
    String USER_NAME;   //16
    String PASS_WORD;   //16
};

template <class T>
void write_config(uint16_t, T);
template <class T>
void read_config(uint16_t, T);

#endif