/*
 * poller.h
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */

#ifndef INC_POLLER_H_
#define INC_POLLER_H_

signed short int X ;
char msb, lsb;

void Poll(void);
void StartPolling(void);
void StopPolling(void);
void SetPollingTime(int polling_time);

#endif /* INC_POLLER_H_ */


