/*
 * Room.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Hercule Poirot
 */

#include "Room.h"
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
//Perhaps a function to make a Room

int* findAdjRooms(char fileName[], int roomNum){
    
    int c = 0; //num of adjacent rooms
    int* adjRooms = (int*) malloc(sizeof(int)*12);

    FILE* adjMat = fopen("AdjMatrix.txt", "r");

    int curLine = 0;
    int adjRoomNum = 0;
    char ch;

    while ((ch = fgetc(adjMat)) != EOF){
        
        if (curLine != roomNum){
            
            if (ch == '\n'){
                curLine++; //If newline char is found, increment curLine
            }
        
        } else { //If curLine == roomNum
            
            if (ch == '1'){
                
                c++; //increment num of adjacent rooms
                adjRooms[c] = adjRoomNum;

            } else if (ch == ' ') {
                
                adjRoomNum++;

            } else if (ch == '\n') {
                curLine++;
            }
                    
        }
    }

    fclose(adjMat);
    adjRooms[0] = c;
    return adjRooms+1;
}
