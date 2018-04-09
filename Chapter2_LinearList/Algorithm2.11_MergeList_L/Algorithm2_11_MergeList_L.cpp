/*
*  - Algorithm2.11_MergeList
*  - Luke
*  - 2018/4/9 Mon
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode {
	int data;
	ListNode *next;
};

//Merge two list into one list - listThree
void MergeList(ListNode *listOne, ListNode *listTwo, ListNode *listThree );
//Insert element into list
bool ListInsert(ListNode *list, int index, int element);
//Create a LinkList in positive order
ListNode *CreateLinkList_PositiveOrder(int length);
//Delete the element at index
bool DeleteElement(ListNode *list, int index, int &element);
//Create a LinkList in reversed order
ListNode *CreateLinkList_ReversedOrder(int length);
//Get the element of LinkList list at index
int GetElement(ListNode *list, int index);
//Print list
void PrintList(ListNode *list);

int main() {
	ListNode *linkListOne = CreateLinkList_PositiveOrder(10);
	ListNode *linkListTwo = CreateLinkList_PositiveOrder(15);
	ListNode *linkListThree = (ListNode *)malloc(sizeof(ListNode));
	MergeList(linkListOne, linkListTwo, linkListThree);
	PrintList(linkListThree);
	return 0;
}

//Merge two list into one list - listOne
void MergeList(ListNode *listOne, ListNode *listTwo, ListNode *listThree ) {
	ListNode *positionOne, *positionTwo, *positionThree;
	positionOne = listOne->next;
	positionTwo = listTwo->next;
	listThree->next = listOne->next;
	positionThree = listThree;

	while(positionOne && positionTwo) {
		if(positionOne->data < positionTwo->data) {
			positionThree->next = positionOne;
			positionOne = positionOne->next;
		} else {
			positionThree->next = positionTwo;
			positionTwo = positionTwo->next;
		}
		positionThree = positionThree->next;
	}

	positionThree->next = positionOne ? positionOne : positionTwo;

	free(listTwo);
	
}

//Insert element into list
bool ListInsert(ListNode *list, int index, int element) {
	ListNode *position = list->next;
	int time = 1;
	while(position && time < index) {
		time++;
		position = position->next;
		if(!position) {
			printf("index is out of range.");
			return false;
		}
	}
	if(index < 0) {
		printf("index is illegal.");
		return false;
	}
	ListNode *insertNode = (ListNode *)malloc(sizeof(ListNode));
	insertNode->data = element;
	insertNode->next = position->next;
	position->next = insertNode;
	return true;
}

/*
* - Create a LinkList in positive order
* - Parameters: length
* - Return: a LinkList
*/
ListNode *CreateLinkList_PositiveOrder(int length) {
	ListNode *listHead, *position, *listTail;
	int listNodeSize = sizeof(ListNode);
	listHead = (ListNode *)malloc(listNodeSize);
	listHead->next = NULL;
	listTail = listHead;
	
	for(int initNum = 0; initNum < length; initNum++) {
		position = (ListNode *)malloc(listNodeSize);
		//scanf("%d",&position->data);
		position->data = initNum;
		position->next = listTail->next;
		listTail->next = position;
		listTail = position;
	}

	return listHead;
}

/*
* - Delete the element at index
* - Parameters: *list index element
* - Return: whether delete successfully
*/
bool DeleteElement(ListNode *list, int index, int &element) {
	ListNode *position = list->next;
	int time = 1;
	while(position && time < index - 1) {
		position = position->next;
		time++;
		if(!position->next) {
			printf("index is out of range.");
			return false;
		}
	}
	if(index < 0) {
		printf("index is illegal.");
		return false;
	}
	element = position->next->data;
	ListNode *temp = position->next;
	position->next = temp->next;
	free(temp);
	return true;
}

/*
* - Print list
* - Parameters: *list
*/
void PrintList(ListNode *list) {
	ListNode *position = list->next;
	while(position) {
		printf("%d ", position->data);
		position = position->next;
	}
	printf("\n");
}

/*
* - Create a LinkList in reversed order
* - Parameters: length
* - Return: a LinkList
*/
ListNode *CreateLinkList_ReversedOrder(int length) {
	ListNode *listHead, *position;
	int listNodeSize = sizeof(ListNode);
	listHead = (ListNode *)malloc(listNodeSize);
	listHead->next = NULL;
	
	for(int initNum = 0; initNum < length; initNum++) {
		position = (ListNode *)malloc(listNodeSize);
		//scanf("%d",&position->data);
		position->data = initNum;
		position->next = listHead->next;
		listHead->next = position;
	}

	return listHead;
}

/*
* - Get the element of LinkList list at index
* - Parameters: *list index
* - Return: element(INT_MIN if index is illegal)
*/
int GetElement(ListNode *list, int index) {
	ListNode *position = list->next;
	int time = 1;
	while(position && time < index) {
		position = position->next;
		time++;	
		if(!position) {
			break;
		}
	}
	if(index < 0) {
		printf("no element in this index.\n");
		return INT_MIN;
	}
	return position->data;
}