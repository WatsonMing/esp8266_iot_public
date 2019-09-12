/*
 * @Descripttion: 
 * @version: 
 * @Author: donmine
 * @LastEditors: donmine
 * @LastEditTime: 2019-09-12 21:33:01
 */
// #include "network.h"

void setup()
{
    Serial.begin(9600); // 设置串口波特率为9600
    while (!Serial)
        ; // 如果串口没有打开，则死循环下去不进行下面的操作
    //wifi_start();
    //mqtt_connect();
}
void loop()
{
    char incomedate;
    if (Serial.available() > 0) //串口接收到数据
    {
        incomedate = Serial.read(); //获取串口接收到的数据
        if (incomedate == 'H')
        {
            Serial.println("Good Job!");
        }
    }
}
