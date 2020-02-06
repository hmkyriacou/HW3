/*
 * Room.h
 *
 *  Created on: Feb 3, 2020
 *      Author: Inspector Clouseau
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <stdbool.h>

//Creates a struct called Room with five data fields
typedef struct
{
	int roomNum;       //number of room -- corresponds to rows/columns of adjacency matrix
    char roomName[50]; //common room name
    int numClues;      //number of clues to be found in the Room
    bool searched;     //true iff room has been searched
    bool discovered;   //true iff room is available to be searched--not searched but adjacent to a room that has been searched
}Room;

int* findAdjRooms(char[], int);


#endif /* ROOM_H_ */
