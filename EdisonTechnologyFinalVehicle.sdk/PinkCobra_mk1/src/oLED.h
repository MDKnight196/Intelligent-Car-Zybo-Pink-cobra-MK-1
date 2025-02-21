/*
 * oLED.h
 *
 *  Created on: Dec 5, 2016
 *      Author: ulab
 */

#ifndef SRC_OLED_H_
#define SRC_OLED_H_

#include "XIicPs.h"
#include "sleep.h"
#include "XGpio.h"

#define OLED_IIC_ADDR      	0b0111101
#define MAX_NUM_IMAGE      	9
#define STANDBY_IMAGE_NUM	1
#define I2C_COMMAND        	0x00
#define I2C_DATA           	0x40
#define DISPLAYOFF         	0xAE
#define SETDISPLAYCLOCKDIV 	0xD5
#define SETMULTIPLEX       	0xA8
#define SETDISPLAYOFFSET   	0xD3
#define SETSTARTLINE       	0x40
#define CHARGEPUMP         	0x8D
#define NORMALDISPLAY      	0xA6
#define DISPLAYALLONRESUME 	0xA4
#define SEGREMAP           	0xA0
#define COMSCANDEC         	0xC8
#define SETCOMPINS         	0xDA
#define SETCONTRAST        	0x81
#define SETPRECHARGE       	0xD9
#define SETVCOMDESELECT	   	0xDB
#define DISPLAYON          	0xAF
#define IIC_SCLK_RATE	   	100000

#define IIC_ID				XPAR_PS7_I2C_0_DEVICE_ID
#define ROM_GPIO_ID			XPAR_AXI_GPIO_2_DEVICE_ID
#define RST_GPIO_ID		XPAR_AXI_GPIO_1_DEVICE_ID

XIicPs oLED;
XGpio rom, rst;
u8 message[2];

int setupIIC(u16 deviceId);
int setupoLED();
void display(int opMode);

#endif /* SRC_OLED_H_ */
