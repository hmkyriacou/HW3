#include <stdio.h>
#include <stdbool.h>
#include "structures.h"
#include <stdlib.h>
#include <string.h>

DLLNode* makeRooms(char name[50])
{
	int i;
	int sentinel;
	int rNum;
	char rName[50];
	int rClues;

	FILE* file = fopen(name, "r");
	fscanf(file,"%d ", &sentinel);
	DLLNode* Rooms = makeEmptyLinkedList();
	//printf("%d\n", sentinel);
    
	for (i=0; i<sentinel; i++){
		Room* rm1 = (Room*) malloc(sizeof(Room));

		fscanf(file, "%d", &rNum);
        //printf("%d ", rNum);
		rm1->roomNum = rNum;

		fscanf(file, "%s", rName);
		//printf("%s ", rName);
        strcpy(rm1->roomName, rName);

		fscanf(file, "%d", &rClues);
        //printf("%d ", rClues);
		rm1->numClues = rClues;

		rm1->searched = false;
		rm1->discovered = false;

		savePayload(Rooms, rm1);

        //printf("\n");
	}
	
    return Rooms;

}



Room* findRoom(int findNum, DLLNode* roomList){
    if (roomList->RoomP->roomNum == findNum){
        return roomList->RoomP;
    } else if (roomList->next == NULL) {
        return NULL;
    } else {
        return findRoom(findNum, (DLLNode*) roomList->next);
    }
}  
