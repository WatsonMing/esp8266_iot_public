/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 21:48:42
 */
#include "flash_control.h"
#include "config.h"
#include <EEPROM.h>
template <class T>
/**
 * @name: 写入配置文件函数
 * @msg: 
 * @param {type} 
 * @return: 
 */
void write_config(short addr, T config)
{
    EEPROM.begin(short(EEPROM_START));
    EEPROM.put(addr, config);
    EEPROM.end();
}
template <class T>
/**
 * @name: 读取配置文件函数
 * @msg: 
 * @param {type} 
 * @return: 
 */
void read_config(short addr, T config)
{
    EEPROM.begin(short(EEPROM_START));
    EEPROM.get(addr, config);
    EEPROM.end();
}
