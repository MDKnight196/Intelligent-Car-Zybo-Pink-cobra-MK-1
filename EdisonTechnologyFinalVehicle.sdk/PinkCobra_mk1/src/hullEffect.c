/*
 * hullEffect.c
 *
 *  Created on: Dec 6, 2016
 *      Author: ulab
 */

#include "hullEffect.h"
//ft per sec
//rev = 6in
//8 intCnt = rev

float intCntlast=0;
float getDISTraveled(int intCnt){
	return (float)intCnt/16; // (((intCnt/8)*6)/12)
}

float calSpeed(int intCnt){
	float speed=0;

	speed=(getDISTraveled(intCnt)-getDISTraveled(intCntlast))/TIME_INTERVAL_S;
	intCntlast=intCnt;

	return speed;

}
