/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-04-05     bigmagic    first version
 */

#include <rtthread.h>
#include <rtdevice.h>

int main(int argc, char** argv)
{
    int a=1,status;
    a=a+1;
#if 1
    rt_device_t uart;
    char rec_buff[200];
    struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;  /* 初始化配置参数 */
    rt_uint8_t buff[]="hello swust\n";
#if 1  
    uart = rt_device_find("uart4");
    rt_kprintf("the device not found22\n"); 
    if(uart==RT_NULL)
    {
        rt_kprintf("the device not found\n");  
        //while(1);
    }
    rt_device_init(uart);//对串口4进行初始化
	/*
    config.baud_rate = BAUD_RATE_115200;        //修改波特率为 9600
    config.data_bits = DATA_BITS_8;           //数据位 8
    config.stop_bits = STOP_BITS_1;           //停止位 1
    config.bufsz     = 128;                   //修改缓冲区 buff size 为 128
    config.parity    = PARITY_NONE;           //无奇偶校验位
    rt_device_control(uart, RT_DEVICE_CTRL_CONFIG, &config);*/

    status=rt_device_open(uart,RT_SERIAL_EVENT_RX_IND);
    if(status!=RT_EOK)
    {
        rt_kprintf("open error\n");
    }
    rt_device_write(uart,-1,&buff,sizeof(buff));
	//rt_device_read(uart, -1, &rec_buff, 20);这部分短接tx和rx直接进行回环测试
    rt_kprintf("%s\n",rec_buff);
#endif
#endif  
    rt_kprintf("Hi, this is RT-Thread4444!!\n");
    return 0;
}
