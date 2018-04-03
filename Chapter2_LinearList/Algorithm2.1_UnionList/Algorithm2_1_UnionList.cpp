/* 
*  - Algorithm2.1_UnionList
*  - Luke
*  - 2018/3/29 Thu
*/

#include <stdio.h>
#include <string.h>

//union two list into ListOne
void unionList(char listOne[], char listTwo[]); 
//print elements in list
void printList(char list[]);

int main() {
	//initiate datas
	char listOne[10] = {'1','3','5','7','9'};
	char listTwo[5] = {'0','2','5','6','8'};


	//call back function - unionList
	unionList(listOne, listTwo);
	//call back function - printList
	printList(listOne);

	return 0;
}

/* 
* - union two list into ListOne
* - parameters: *listOne, *listTwo
*/
void unionList(char listOne[], char listTwo[]) {
	//initiate params
	int i = 0, j = 0;
	int length = strlen(listTwo);

	for(i; i < length; i++) {
		//linear search listOne, if has element of listTwo, break circulation
		for(j; j < strlen(listOne); j++) {
			if(listTwo[i] == listOne[j]) {
				break;
			}
		}
		//if circulate the all listOne, add 
		if(j == strlen(listOne)) {
			listOne[j] = listTwo[i];
		}
		j = 0; //initiate index of listOne
	}	
}

/*
* - print elements in list
* - parameters: *list
*/
void printList(char list[]) {
	int index = 0;
	//linear search to print listOne
	for(index; index < strlen(list); index++) {
		printf("%c", list[index]);
	}
}