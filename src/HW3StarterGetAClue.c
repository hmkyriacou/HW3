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
#include <string.h>

int main(void) {
	puts("!!!Mystery Mansion aka HW3!!!\n\n");
    
    FILE *AdjMat = fopen("AdjMatrix.txt", "w");
	fprintf(AdjMat, "0 1 0 0 0 0 0 0 0 0 0 0\n");
	fprintf(AdjMat, "1 0 1 0 0 0 0 0 0 1 1 0\n");
	fprintf(AdjMat, "0 1 0 1 0 0 1 0 0 0 1 0\n");
	fprintf(AdjMat, "0 0 1 0 1 0 0 0 0 0 1 0\n");
	fprintf(AdjMat, "0 0 0 1 0 1 0 0 0 1 1 0\n");
	fprintf(AdjMat, "0 0 0 0 1 0 1 0 0 0 1 0\n");
	fprintf(AdjMat, "0 0 1 0 0 1 0 1 0 0 0 0\n");
	fprintf(AdjMat, "0 0 0 0 0 0 1 0 1 0 1 0\n");
	fprintf(AdjMat, "0 0 0 0 0 0 0 1 0 1 1 0\n");
	fprintf(AdjMat, "0 1 0 0 1 0 0 0 1 0 0 0\n");
	fprintf(AdjMat, "0 1 1 1 1 1 0 1 1 0 0 1\n");
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
        puts("Thank you for doing a through examination. Which room number would you like to start in?");
        int startingRoom;
        scanf("%d", &startingRoom);
        
        DLLNode* walkThroughList = makeEmptyLinkedList();
        Room* searchedRoom = findRoom(startingRoom, roomList);
        
        searchedRoom->discovered = true;
        searchedRoom->searched = true;
        savePayload(walkThroughList, searchedRoom);

        int* adjRooms = findAdjRooms("AdjMatrix.txt", searchedRoom->roomNum);

        int DUMMY = printRoomInfo(searchedRoom);

        //int numOfSearchedRooms = 1;
        //while (numOfSearchedRooms <= 12){
            
            puts("\n\nBeggining bredth-first-search...\n");

            printf("From the %s, you can see %d rooms.\n\n", searchedRoom->roomName, *(adjRooms-1));

            puts("The adjacent rooms are...");
            
            printf("\n--------DEBUG--------\nfindAdjRooms size=%d\nfindAdjRooms[0]=%d\nfindAdjRooms[1]=%d\nfindAdjRooms[2]=%d\nfindAdjRooms[3]=%d\n\n",*(adjRooms-1), adjRooms[0], adjRooms[1], adjRooms[2], adjRooms[3]);
            printf("Room name: %s\n\n", findRoom(10, roomList)->roomName);

            for (int i = 0; i < *(adjRooms-1); i++){
                printf("%c", i==2 ? '1' : '\0');
                Room* curRoom = findRoom(adjRooms[i], roomList);
                printf("%c", i==2 ? '2' : '\0');
                printf("The %s\n", curRoom->roomName);
                printf("%c", i==2 ? '3' : '\0');
                
                curRoom->discovered = true;
                printf("%c", i==2 ? '4' : '\0');
                savePayload(walkThroughList, curRoom);
                printf("%c", i==2 ? '5' : '\0');

            }
            printf("\n");
        //}

    } else {
        puts("What roomNumber would you like to see the information for?");
        int lookAtRoom;
        scanf("%d", &lookAtRoom);
        
        Room* searchedRoom = findRoom(lookAtRoom, roomList);
        int DUMMY = printRoomInfo(searchedRoom); 
    }

    //printf("%d\n", *(adjRooms-1));


	return EXIT_SUCCESS;
}

int printRoomInfo(Room* r){
    
    int n = r->roomNum;
    int c = r->numClues;
    char name[50];
    strcpy(name, r->roomName);
    bool s = r->searched;
    bool d = r->discovered;

    printf("\nShowing information for the %s... \n", name);
    printf("The room number is: %d\n", n);
    printf("The number of clues is %d\n", c);
    printf("The room %s searched\n", s ? "has been" : "has not been");
    printf("The room %s discovered\n\n", d ? "has been" : "has not been");

    return 0;
}

