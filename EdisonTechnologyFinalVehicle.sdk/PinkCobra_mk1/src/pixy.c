/*
 * pixy.c
 *
 *  Created on: Dec 6, 2016
 *      Author: ulab
 */

#include "pixy.h"

int pixySetup(u16 DeviceId)
{
	int Status;
	XUartPs_Config *Config;


	/*
	 * Initialize the UART driver so that it's ready to use.
	 * Look up the configuration in the config table, then initialize it.
	 */
	Config = XUartPs_LookupConfig(DeviceId);
	if (NULL == Config) {
		return XST_FAILURE;
	}

	Status = XUartPs_CfgInitialize(&pixy, Config, Config->BaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*
	 * Use normal mode.
	 */
	XUartPs_SetOperMode(&pixy, XUARTPS_OPER_MODE_NORMAL);



	return XST_SUCCESS;
}


struct Blocks getBlocks(){
	u8 btye[BUFFER_SIZE];
	u16 test;

	struct Blocks blocks;

	blocks.cc1_set=0;
	blocks.cc1_sig=0xffff;
	blocks.cc1_loc=0xffff;
	blocks.cc2_set=0;
	blocks.cc2_sig=0xffff;
	blocks.cc2_loc=0xffff;
	blocks.read=1;

	int i, j;

	for (i=0; i<BUFFER_SIZE; i++){
		btye[i]=0;
	}

	XUartPs_Recv(&pixy, &btye[0], BUFFER_SIZE);


		for (i=3; i<BUFFER_SIZE; i++){
			if (btye[i-3]==0x55 && btye[i-2] ==0xaa && btye[i-1]==0x56 && btye[i] ==0xaa && blocks.cc1_set==0){
				blocks.cc1_set=1;
				blocks.cc1_sig = btye[i+4];
				blocks.cc1_sig = blocks.cc1_sig << 8;
				blocks.cc1_sig |= btye[i+3];
				blocks.cc1_loc = btye[i+6];
				blocks.cc1_loc = blocks.cc1_loc << 8;
				blocks.cc1_loc|= btye[i+5];
			}
			else if (btye[i-3] !=0x55 && btye[i-2] != 0xaa && btye[i-1]==0x56 && btye[i] ==0xaa && blocks.cc2_set==0){
				blocks.cc2_set=1;
				blocks.cc2_sig = btye[i+4];
				blocks.cc2_sig = blocks.cc2_sig << 8;
				blocks.cc2_sig |= btye[i+3];
				blocks.cc2_loc = btye[i+6];
				blocks.cc2_loc = blocks.cc2_loc << 8;
				blocks.cc2_loc|= btye[i+5];
			}
			if(blocks.cc2_set==1 && blocks.cc1_set ==1){
				//if (!(blocks.cc1_sig == YELLOW || blocks.cc1_sig == GREEN) &&
				//		!(blocks.cc2_sig == YELLOW || blocks.cc2_sig == GREEN)){
				if (!(blocks.cc1_sig == YELLOW && blocks.cc2_sig == YELLOW) &&
						!(blocks.cc1_sig == YELLOW && blocks.cc2_sig == GREEN) &&
						!(blocks.cc1_sig == GREEN && blocks.cc2_sig == YELLOW) &&
						!(blocks.cc1_sig == GREEN && blocks.cc2_sig == GREEN)){
					blocks.read=0;
				}
				break;
			}
		}


	for(j=0;j<5;j++){
		test=blocks.cc2_loc-2;
		if(blocks.cc1_loc == (test+j)){
			blocks.cc2_set=0;
			blocks.cc2_sig=0xffff;
			blocks.cc2_loc=0xffff;
			break;
		}
	}

	return blocks;
}


int getDirection(struct Blocks check, struct Blocks *read, int *cnt){
	int i, sigCount;

	for(i=0; i<*cnt; i++){
		if (check.cc1_sig == read[i].cc1_sig &&
			check.cc2_sig == read[i].cc2_sig ){
			sigCount++;
		}
	}

	*cnt = 0;

	if(sigCount>3){
		if (check.cc1_set==1 && check.cc2_set==1){
			if(check.cc1_sig == check.cc2_sig){
				if (check.cc1_sig == YELLOW){
					return 4;
				}
				else if (check.cc1_sig == GREEN){
					return 1;
				}
			}
			else{
				if ((check.cc1_sig==YELLOW && check.cc1_loc > check.cc2_loc) ||
					(check.cc1_sig==GREEN && check.cc1_loc < check.cc2_loc)){
					return 3;
					}
				else if ((check.cc1_sig==GREEN && check.cc1_loc > check.cc2_loc) ||
						(check.cc1_sig==YELLOW && check.cc1_loc < check.cc2_loc)){
					return 2;
				}
			}
		}
	}
	return 0;
}
