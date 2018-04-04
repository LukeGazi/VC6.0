/*
*  - Algorithm2.7 MergeList
*  - Luke
*  - 2018/4/4 Wed
*/

#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100 //default size
#define LIST_INCREAMENT 10 //append size

struct List {
	int *element;
	int length;
	int listSize; //based on sizeof
};

//Merge ordered listOne and ordered listTwo to listThree in order
void MergeList(List &listOne, List &listTwo, List &listThree);
//Insert element into list at position where oder is index
bool ListInsert(List &list, int index, int num);
//Initiate List
void InitList(List &list);
//Linear Search and print element
void PrintList(List &list);

int main() {
	//initiate data
	List listOne, listTwo, listThree;

	//function callback
	InitList(listOne);
	InitList(listTwo);
	InitList(listThree);
	int indexOne = 1;
	int indexTwo = 1;
	for(int i = 1; i < 102; i++) {
		if(i%2 == 0 && i < 80) {
			ListInsert(listOne, indexOne++, i);
		} else {
			ListInsert(listTwo, indexTwo++, i);	
		}		
	}

	MergeList(listOne, listTwo, listThree);

	PrintList(listOne);
	PrintList(listTwo);
	PrintList(listThree);

	return 0;
}

/*
* - Merge ordered listOne and ordered listTwo to listThree in order
* - Parameters: *listOne, *listTwo, *listThree
*/
void MergeList(List &listOne, List &listTwo, List &listThree ){
	int listOneIndex = 0; //element Position
	int listTwoIndex = 0; //element Position
	int listThreeIndex = 1; //insert Position
	
	while(listOneIndex < listOne.length && listTwoIndex < listTwo.length) {
		int inserElement;
		if(listOne.element[listOneIndex] < listTwo.element[listTwoIndex]) {
			inserElement = listOne.element[listOneIndex++];
		} else {
			inserElement = listTwo.element[listTwoIndex++];
		}
		//int inserElement = listOne.element[listOneIndex] < listTwo.element[listTwoIndex] ? (listOne.element[listOneIndex], listOneIndex++) : (listTwo.element[listTwoIndex], listTwoIndex++);
		ListInsert(listThree, listThreeIndex++, inserElement); 
	}
	while(listOneIndex < listOne.length) {
		ListInsert(listThree, listThreeIndex++, listOne.element[listOneIndex++]); 
	}
	while(listTwoIndex < listTwo.length) {
		ListInsert(listThree, listThreeIndex++, listTwo.element[listTwoIndex++]); 
	}
}

/*
* - Insert element into list at position where oder is index
* - Parameters: *list index element
* - Return: whether insert successfully
*/
bool ListInsert(List &list, int index, int num) {
	index--;
	//judge index
	if((unsigned)index > (unsigned)list.length) {
		printf("index(%d) is illegal!\n", index + 1);
		return false;
	}
	//expand size
	if(list.length >= list.listSize) {
		int *newbase = (int *)realloc(list.element, (list.listSize + LIST_INCREAMENT) * sizeof(int));
		printf("realloc!\n");
		if(!newbase) {
			printf("can not malloc!\n");
			return false;
		}
		list.element = newbase;
		list.listSize += LIST_INCREAMENT;
	}
	int *insertPosition = &(list.element[index]);
	for(int *movePosition = &(list.element[list.length - 1]); movePosition >= insertPosition; movePosition--) {
		*(movePosition + 1) = *movePosition; //right shift element
	}
	//insert element into list at insertPosition
	*insertPosition = num;
	list.length++;

	return true;
}

/*
* - Initiate List
* - Parameters: *list
*/
void InitList(List &list) {
	list.element = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if(!list.element) {
		exit(0); //end application
	}
	
	//initiate properties
	list.length = 0;
	list.listSize = LIST_INIT_SIZE;
}

/*
* - Linear Search and print element
* - Parameters: *list
*/
void PrintList(List &list) {
	for(int index = 0; index < list.length; index++) {
		printf("%d ", list.element[index]);
	}
	printf("\n");
}
