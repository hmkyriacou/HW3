/*
 * LinkedList.c
 *
 *  Created on: Nov 4, 2019
 *      Author: Therese
 */


#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

//Asks where DoublyLinkedList is empty  Takes doubly-linked list Pointer
bool isEmpty(DLLNode* dlP)
{
	bool ans = false;
	if(dlP->RoomP == (Payload*)0)
	{
		ans = true;
	}
	return ans;
}

//Creates Empty Doubly-Linked List (returns Pointer to DLL)
//Invoke like this :   DLLNode* myDLL = makeEmptyLinkedList();
DLLNode* makeEmptyLinkedList()
{
	DLLNode* dlP = (DLLNode*) malloc(sizeof(DLLNode));
	dlP->next = (struct DLLNode*)0;
	dlP->prev = (struct DLLNode*)0;
	dlP->RoomP = (Payload*)0;

	return dlP;
}

//Adds Payload (for us, a Marker) to the end of the list
//Note:  If the list is empty, it merely changes the Payload field of the NULL node
//to the Payload value passed in (by reference with a pointer)
//However, if the list is not empty, it creates a new node at the end of the DLL
//with the appropriate Payload value

void savePayload(DLLNode* lp, Payload* mp)
{
	//if the list is empty, then make payP be mp
	//else traverse the list,
	//make a new list element
	//put mp in that
	//attach the new list element to the existing list
	if(isEmpty(lp))
	{
		lp->RoomP = mp;
	}
	else
	{
		DLLNode* temp = lp;
		while(temp->next)
		{
			temp=(DLLNode*)temp->next;
		}
		//now temp points to the last element

		//make a new element, attach mp to it, wire up the new element
		DLLNode* newList = makeEmptyLinkedList();//Creates new empty (last) node
		newList->RoomP = mp;                      //Puts Payload in new node
		temp->next = (struct DLLNode*)newList;   //Old last node now points to new node
		newList->prev = (struct DLLNode*) temp;  //New node points backwards to old last node
	}
}


Payload* dequeueLIFO(DLLNode* lp)
{
	Payload* RoomP = (Payload*)0;
	if(isEmpty(lp))
	{
		puts("Trying to dequeue from empty.");
	}
	else
	{

		DLLNode* temp = lp;
		while(temp->next)
		{
			temp=(DLLNode*)temp->next;
		}
		//now temp points to the last element


		RoomP = temp->RoomP;
		temp->RoomP = (Payload*)0;

		//remove the last, now empty, element
		if(temp->prev)
		{
			temp=(DLLNode*)temp->prev;
			//free(temp->next);

			temp->next = (struct DLLNode*)0;
		}
		else
		{
			puts("Queue is now empty");
		}
		puts("returning from dequeue");fflush(stdout);
	}

	return RoomP;
}

backFromDQFIFO* dequeueFIFO(DLLNode* lp)
{
	backFromDQFIFO* fp = (backFromDQFIFO*) malloc(sizeof(backFromDQFIFO));
	if(lp->next == (struct DLLNode*)0)
	{
		//list of length 1 or 0
		fp->newQHead= lp;
	}
	else
	{
		fp->newQHead= (DLLNode*) lp->next;
	}
	fp->mp= lp->RoomP;//all return values are set
	if(lp->next != (struct DLLNode*)0)
	{
		//length list is >1
		free(lp);
	}

	return fp;
}

void printHistory(DLLNode* hp)
{
	puts("Printing history");
	if(hp->RoomP ==(Payload*)0)
	{
		puts("Empty list");
	}
	else
	{
		//traverse the list, printing as we go

		DLLNode* temp = hp;
		while(temp->next)
		{
			//room =temp->payP->roomNumber;
			//treasureSubtotal+= temp->payP->treasure;
			int roomNum = temp->RoomP->roomNum;
			//int row = temp->payP->row;
			//int col = temp->payP->col;
			printf("The Room was %d.\n", roomNum);
			temp=(DLLNode*)temp->next;

		}
		//room =temp->payP->roomNumber;
		// treasureSubtotal+= temp->payP->treasure;
		// printf("The room was %d, and the treasure subtotal was %f.\n", room, treasureSubtotal);
		int roomNum = temp->RoomP->roomNum;
		//int row = temp->payP->row;
		//int col = temp->payP->col;
		printf("The Room was %d.\n", roomNum);
		temp=(DLLNode*)temp->next;
	}
}

DLLNode* removeFromList(DLLNode* hP, Payload* pP)
{
	DLLNode* retHead = hP;//only changes if first element gets removed
	//find the payload
	//use the structure of a list, namely, list is empty or element followed by list
	if(isEmpty(hP))
	{
		//nothing to do
	}
	else
	{
		//puts("list is not empty");fflush(stdout);
		DLLNode* altHead = (DLLNode*)hP->next;
		//find the item, if it is there
		DLLNode* temp = hP;
		bool done = false;
		while((!done) && temp->next)
		{
			//are we there yet?
			if(temp->RoomP == pP)
			{
				done=true;
				//puts("found it 1");fflush(stdout);
			}
			else
			{
				temp=(DLLNode*)temp->next;
			}
		}
		//either we are pointing to the correct element, or we are at the end, or both
		if((temp->RoomP) == pP)
		{
			//puts("found it 2");fflush(stdout);
			//found it, remove it
			//are we at the beginning?
			if(temp == hP)
			{  //found it at the first element
				//puts("found it at first element");fflush(stdout);
				//is the list of length 1?
				if(!(temp->next))
				{//if there is no next
					//remove payload, return empty list
					hP->RoomP = (Payload*)0;
				}
				else //not of length 1
				{ //not freeing the Payload, but freeing the first list element
					//puts("found it at first element of list with length > 1");fflush(stdout);
					//free(hP);
					retHead = altHead;
				}
			}
			else //not found at first location in list
			{
				//puts("found it not at first element");fflush(stdout);
				//save the linkages
				//found element has a next
				//found element has a prev
				//participant before has a next
				//participant after has a prev
				DLLNode* prevPart = (DLLNode*) temp->prev;//non-zero because not at first element
				DLLNode* nextPart = (DLLNode*) temp->next;//could be zero, if found at last element
				prevPart->next = (struct DLLNode*) nextPart;//RHS is 0 if at end
				//puts("after setting the next of the previous");fflush(stdout);
               // printf("Next is %p, %d\n", nextPart, (bool)nextPart);fflush(stdout);
				if((bool)nextPart)//don't need guarded block if element found at end of list
				{
					//puts("before setting the previous of the next");fflush(stdout);
					nextPart->prev = (struct DLLNode*) prevPart;

				}
				//puts("after handling the  previous of the next");fflush(stdout);
			}//end of not found at first location
		}//end of found it
		else
		{
			//didn't find it
			//puts("did not find it");fflush(stdout);
			//nothing to do
		}//end did not find it
	}
	//printf("Returning %p\n", retHead); fflush(stdout);
	return retHead;
}
