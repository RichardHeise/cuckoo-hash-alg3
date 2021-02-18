#include<math.h>
#include<stdio.h>
#include"myht.h"

int insert(int key, int table_1[], int table_2[]){

	int k;

	k = key % M;
	if (table_1[k] == key) /*if table[k' already exists*/
		return k;
	else if (table_1[k] == FLAG) /*if table[k] is free*/
		table_1[k]=key;
	else{
		int j;
		j = table_1[k];
		j = floor(M * (j * 0.9 - floor(j * 0.9)));
		table_2[j] = table_1[k];
		table_1[k] = key;
	}

	return k;
}

void printTable(int table[]){

	int i;
	for(i=0;i<M;i++){
		//if(i[M] != FLAG);
		printf("%d %d\n",i, table[i]);
	}

}

int search(int key, int table_1[], int table_2[]) {

	int k;
	k = key % M;

	if (table_1[k] != FLAG) {
		if (table_1[k] == key) {
			return k;
		} else {
			int j;
			j = floor(M * (key * 0.9 - floor(key * 0.9)));

			return j;
		}
	} 

	return FLAG;
}

void initTable (int table[]) {
	int i;

	for (i = 0; i < M; i++) {
		table[i] = FLAG;
	}
}