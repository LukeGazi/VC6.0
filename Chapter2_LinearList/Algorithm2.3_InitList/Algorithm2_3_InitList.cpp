/*
*  - Algorithm2.3_InitList
*  - Luke
*  - 2018/4/1 Sun
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

//Initiate List
void InitList(List &list);
//Testify the initiation of list
void TestListInitiation(List &list);

int main() {
	//declare list
	List list;

	//callback the function - InitList
	InitList(list);
	//callback the function - TestListInitiation
	TestListInitiation(list);
	
	return 0;
}

/*
* - Initiate List
* - Parameters: *list
*/
void InitList(List &list) {
	list.element = (int *)malloc(100 * sizeof(int));
	if(!list.element) {
		exit(0); //end application
	}
	
	//initiate properties
	list.length = 0;
	list.listSize = LIST_INIT_SIZE;
}

/*
* - Testify the initiation of list
* - Parameters: *list
*/
void TestListInitiation(List &list) {
	//print the pratical size of list
	printf("the size of list is %d\n", sizeof(list)); // 3 * sizeof(int) = 12
	//print the pratical size of list
	printf("the size of list is %d\n", sizeof(list.element)); // sizeof(*) = 4 the size of pointer
	//print the property size of list
	printf("the size of list is %d\n", list.listSize);
}
