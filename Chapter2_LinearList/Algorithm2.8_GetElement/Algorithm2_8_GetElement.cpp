/*
*  - Algorithm2.8_GetElement
*  - Luke
*  - 2018/4/6 Fri
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode {
	int data;
	ListNode *next;
};

//Create a LinkList
ListNode *CreateLinkList_ReversedOrder(int length);
//Get the element of LinkList list at index
int GetElement(ListNode *list, int index);

int main() {
	ListNode *linkList = CreateLinkList_ReversedOrder(10);
	printf("Get element at 11 is %d\n", GetElement(linkList, 11));

	return 0;
}

/*
* - Create a LinkList
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
	if(index < 0 || time >= index) {
		printf("no element in this index.\n");
		return INT_MIN;
	}
	return position->data;
}