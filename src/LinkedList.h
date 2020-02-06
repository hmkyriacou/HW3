/*
 * LinkedList.h
 *
 *  Created on: Nov 4, 2019
 *      Author: Therese
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdbool.h>
#include "Room.h"

//Makes Payload a synonym for Marker, can be used anywhere Marker can--including declarations
typedef Room Payload;

struct DLLNode;
typedef struct
{
	struct DLLNode* next;
	struct DLLNode* prev;
	Payload* RoomP;
}DLLNode;


typedef struct
{
	Payload* mp;
	DLLNode* newQHead;
}backFromDQFIFO;

DLLNode* makeEmptyLinkedList();
DLLNode* removeFromList(DLLNode* hp, Payload* pP);
void savePayload(DLLNode* lp, Payload* mp);
bool isEmpty(DLLNode* lp);
Payload* dequeueLIFO(DLLNode* lp);
backFromDQFIFO* dequeueFIFO(DLLNode* lp);
void printHistory(DLLNode* hp);

#endif /* LINKEDLIST_H_ */
