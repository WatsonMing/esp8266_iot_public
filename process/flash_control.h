/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 23:06:38
 */
#ifndef __FLASH_CONTROL_H__
#define __FLASH_CONTROL_H__

// struct WIFI_CONFIG
// {
//     char *SSID;      //15
//     char *PASS_WORD; //15
// };

// struct HTTP_CONFIG
// {
//     char *HOST; //16
//     short PORT; //2
// };

// struct MQTT_CONFIG
// {
//     char *HOST;      //16
//     short PORT;      //2
//     char *CLIENT_ID; //11
//     char *USER_NAME; //16
//     char *PASS_WORD; //16
// };

// template <class T>
// void write_config(short, T);
// template <class T>
// void read_config(short, T);
// extern "C"
// {
typedef struct NETWORK_CONFIG
{
    String SSID;      //15
    String PASSWORD;  //15
    String HOST;      //16
    int PORT;         //2
    String CLIENT_ID; //11
    String USER_NAME; //16
    String PASS_WORD; //16
} ;
//     extern NETWORK_CONFIG network_config;
// }
void write_config();
void read_config();
#endif
