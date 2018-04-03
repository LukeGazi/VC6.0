/*
*  - Algorithm2.2_MergeList
*  - Luke
*  - 2018.3.30 Fri
*/

#include <stdio.h>
#include <string.h>
#define GET_LENGTH(list) sizeof(list) / sizeof(list[0])

//Merge ordered listOne and ordered listTwo to listThree in order
void MergeList(int listOne[], int listTwo[], int listThree[]);
//Print the list
void PrintList(int list[]);

//declare length
int lengthOne, lengthTwo, lengthThree;

int main() {
	//initiate datas
	int listOne[] = {3,5,8,11};
	int listTwo[] = {2,6,8,9,11,15,20};
	int listThree[11];
	
	//initiate length
	lengthOne = GET_LENGTH(listOne);
	lengthTwo = GET_LENGTH(listTwo);
	lengthThree = GET_LENGTH(listThree);

	//callback the function - MergeList
	MergeList(listOne, listTwo, listThree);
	
	//callback the function - PrintList
	PrintList(listThree);	

	return 0;
}

/*
* - Merge ordered listOne and ordered listTwo to listThree in order
* - Parameters: *listOne, *listTwo, *listThree
*/
void MergeList(int listOne[], int listTwo[], int listThree[] ){
	//initiate index
	int indexOne = 0, indexTwo = 0, indexThree = 0;

	
	//circulate until the shortest list search out
	while(indexOne < lengthOne && indexTwo < lengthTwo) {
		//add the smaller one into listThree
		if(listOne[indexOne] < listTwo[indexTwo]) {
			listThree[indexThree++] = listOne[indexOne++];
		} else {
			listThree[indexThree++] = listTwo[indexTwo++];	
		}
	}
	//append the remained elements to listThree
	while(indexOne < 4) {
		listThree[indexThree++] = listOne[indexOne++];
	}
	while(indexTwo < 7) {
		listThree[indexThree++] = listTwo[indexTwo++];
	}
}

/*
* - Print the list
* - Parameters: *list
*/
void PrintList(int list[]) {
	//initiate index
	int index = 0;

	//linear search list
	for(index; index < lengthThree; ) {
		printf("%d ", list[index++]);
	}
}