/*
 * bluetooth.h
 *
 *  Created on: Dec 6, 2016
 *      Author: ulab
 */

#ifndef SRC_BLUETOOTH_H_
#define SRC_BLUETOOTH_H_

#include "xuartps.h"

#define BUFFER_SIZE 		100
#define BLUETOOTH_ID        XPAR_PS7_UART_0_DEVICE_ID

u8 outputBuffer[BUFFER_SIZE];
u8 inputBuffer[BUFFER_SIZE];
XUartPs bluetooth;

int bluetoothSetup(u16 DeviceId);
int addToString(float value, int index);
int newline(int index);
void readData(u8 *iBuffer, int numbytes);
void writeData(u8 *oBuffer, int numbytes);

#endif /* SRC_BLUETOOTH_H_ */
