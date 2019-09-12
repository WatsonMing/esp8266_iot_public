/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 23:08:49
 */

// template <class T>
/**
 * @name: 写入配置文件函数
 * @msg: 
 * @param {type} 
 * @return: 
 */
// void write_config(short addr, T config)
// {
//     EEPROM.begin(short(EEPROM_START));
//     EEPROM.put(addr, config);
//     EEPROM.end();
// }
// template <class T>
#include "flash_control.h"
#include "config.h"
#include <EEPROM.h>
void write_config(struct NETWORK_CONFIG network_config)
{
    EEPROM.begin(EEPROM_START);
    EEPROM.put(EEPROM_CONFIG, network_config);
    EEPROM.end();
    Serial.println("write config success");
}

/**
 * @name: 读取配置文件函数
 * @msg: 
 * @param {type} 
 * @return: 
 */
// void read_config(short addr, T config)
// {
//     EEPROM.begin(short(EEPROM_START));
//     EEPROM.get(addr, config);
//     EEPROM.end();
// }
void read_config(struct NETWORK_CONFIG network_config)
{
    EEPROM.begin(EEPROM_START);
    EEPROM.get(EEPROM_CONFIG, network_config);
    EEPROM.end();
    Serial.println("read config success");
}