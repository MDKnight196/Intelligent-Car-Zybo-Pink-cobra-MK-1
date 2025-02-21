/*
 * operationalMode.h
 *
 *  Created on: Dec 7, 2016
 *      Author: ulab
 */

#ifndef SRC_OPERATIONALMODE_H_
#define SRC_OPERATIONALMODE_H_

#include "platform.h"
#include "xil_types.h"
#include "xsysmon.h"
#include "xtmrctr.h"
#include "xparameters.h"
#include "Xil_exception.h"
#include "xttcps.h"
#include "xil_io.h"
#include "oLED.h"
#include "bluetooth.h"
#include "PIDcontroller.h"

#define StandByMode 	0
#define DiscoveryMode 	1
#define AcuracyMode		2
#define SpeedMode	 	3
#define CollisionAvoidanceLeader 4
#define CollisionAvoidanceFollower 5
#define ManualMode		6
#define DebugMode		7



void setStandbyMode();
void setSpeedMode();
void setAcuracyMode();
void setDiscoveryMode();
void setManualMode();
void setFollowMode();
void updateMode();
void incModeSel();
int getMode();
void setManualControl(int speed, int direction);
void ModeOperation(XTtcPs ForwardPWM, XTtcPs BackwardPWM, XTtcPs ServoTimer, int PWMSignal, int center, int blackPixelCount);
int isDebug();
void setConnect(int Connect);
void setPixyDir(int dir);




#endif /* SRC_OPERATIONALMODE_H_ */
