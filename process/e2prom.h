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
void write_config(uint16_t,T);
template <class T>
void read_config(uint16_t,T);

#endif