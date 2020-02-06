/*
 * structures.h
 *
 *  Created on: Feb 6, 2019
 *      Author: Harrison
 */

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include <stdbool.h>
#include "LinkedList.h"
#include "Room.h"

DLLNode* makeRooms(char[]);
Room* findRoom(int, DLLNode*);

#endif
