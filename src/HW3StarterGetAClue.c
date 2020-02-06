/*
 ============================================================================
 Name        : HW3StarterGetAClue.c
 Author      : me
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
#include "LinkedList.h"
#include "structures.h"

int main(void) {
	puts("!!!Mystery Mansion aka HW3!!!\n\n");
    
    FILE *AdjMat = fopen("AdjMatrix.txt", "w");
	fprintf(AdjMat, "0 1 0 0 0 0 0 0 0 0 0 0\n");
	fprintf(AdjMat, "1 0 1 0 0 0 0 0 0 0 1 0\n");
	fprintf(AdjMat, "0 1 0 1 0 0 1 0 0 0 1 0\n");
	fprintf(AdjMat, "0 0 1 0 1 0 0 0 0 0 1 0\n");
	fprintf(AdjMat, "0 0 0 1 0 1 0 0 0 1 1 0\n");
	fprintf(AdjMat, "0 0 0 0 1 0 1 0 0 0 1 0\n");
	fprintf(AdjMat, "0 0 1 0 0 1 0 1 0 0 0 0\n");
	fprintf(AdjMat, "0 0 0 0 0 0 1 0 1 0 1 0\n");
	fprintf(AdjMat, "0 1 0 0 0 0 0 1 0 1 1 0\n");
	fprintf(AdjMat, "0 0 0 0 1 0 0 0 1 0 0 0\n");
	fprintf(AdjMat, "0 1 1 1 1 1 0 1 1 0 1 0\n");
	fprintf(AdjMat, "0 0 0 0 0 0 0 0 0 0 1 0\n");

	fclose(AdjMat);

    //Pointer array to all adjacent rooms
    int* adjRooms = findAdjRooms("AdjMatrix.txt", 4);
    
    //Creates a pointer to a LinkedList of all rooms in the game
    DLLNode* roomList = makeRooms("MansionRooms.txt");
    //makeRooms("MansionRooms.txt");
    
    //Pointer to a room of the given room number
    //Room* room4 = findRoom(4, roomList);

    /*  BEGINING OF GAME  */

    puts("Hello detective, I am Inspector Gompei, what is your name?");
    char name[50];
    scanf("%s", name);
    printf("Thank you, %s, for taking the case.\n", name);
    puts("Would you like to do a through examination or just search a specific room? (Type 1 for thourough and 2 for specific room)");
    int gameMode;
    scanf("%d", &gameMode);
    
    if (gameMode == 1){
        puts("Thank you for doing a through examination. Which room would you like to start in?");
        int startingRoom;
        scanf("%d", &startingRoom);

        //TODO: Finish gameMode 1    

    } else {
        puts("What roomNumber would you like to see the information for?");
        int lookAtRoom;
        scanf("%d", &lookAtRoom);
        
        printf("Looking at room %d...\n", lookAtRoom);

        Room* searchedRoom = findRoom(lookAtRoom, roomList);
        printf("The room number is: %d\n", searchedRoom->roomNum);
        printf("The room name is: %s\n", searchedRoom->roomName);
        printf("The number of clues is: %d\n", searchedRoom->numClues);
    
    }

    //printf("%d\n", *(adjRooms-1));

    /*
    for (int i = 0; i < *(adjRooms-1); i++){
        
        printf("%d, ", adjRooms[i]);

    }
    printf("\n");
    */

	return EXIT_SUCCESS;
}

