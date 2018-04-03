/*
*  - Algorithm2.5_ListDelete
*  - Luke
*  - 2018/4/3 Tue
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

//Delete element into list at position where oder is index
bool ListDelete(List &list, int index, int &num);
//Insert element into list at position where oder is index
bool ListInsert(List &list, int index, int num);
//Initiate List
void InitList(List &list);
//Linear Search and print element
void PrintList(List &list);

int main() {
	//initiate data
	List list;

	//function callback
	InitList(list);
	for(int i = 1; i < 102; i++) {
		ListInsert(list, i, i);
	}
	PrintList(list);
	int deleteNum = 0;
	ListDelete(list, 50, deleteNum);
	PrintList(list);
	printf("the num is deleted is : %d\n", deleteNum);

	return 0;
}

/*
* - Insert element into list at position where oder is index
* - Parameters: *list index *element
* - Return: whether delete successfully
*/
bool ListDelete(List &list, int index, int &num) {
	index--;
	//judge index
	if((unsigned)index > (unsigned)list.length) {
		printf("index(%d) is illegal!\n", index + 1);
		return false;
	}
	
	int *deletePosition = &list.element[index];
	num = *deletePosition; //gain the element will be deleted

	//left shift the remains
	for(deletePosition; deletePosition < (list.element + list.length); deletePosition) {
		*deletePosition = *(deletePosition + 1);
		deletePosition++;
		//*deletePosition = *(++deletePosition);
	}

	list.length--; //reduce the length

	return true;
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
