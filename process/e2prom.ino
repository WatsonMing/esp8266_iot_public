#include <e2prom.h>
#include <EEPROM.h>

template <class T>
/**
 * @name: 写入配置文件函数
 * @msg: 
 * @param {type} 
 * @return: 
 */
void write_config(uint16_t addr,T config)
{
    EEPROM.begin(EEPROM_START);
    EEPROM.put(addr,config);
    EEPROM.end();
}
template <class T>
/**
 * @name: 读取配置文件函数
 * @msg: 
 * @param {type} 
 * @return: 
 */
void read_config(uint16_t addr,T config)
{
    EEPROM.begin(EEPROM_START);
    EEPROM.get(addr,config);
    EEPROM.end();
}