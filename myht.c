#include<math.h>
#include<stdio.h>
#include"myht.h"

void initTable(int table[]) {

	int i;

	for (i = 0; i < M; i++) {
		table[i] = OPEN;
	}
}

int hash_1(int key) {
	return (key % M);
}

int hash_2(int key) {
	return floor(M * (key * 0.9 - floor(key * 0.9)));
}

int insert(int key, int table_1[], int table_2[]) {

	int k;
	k = hash_1(key); /*we hash the key first*/

	if (table_1[k] == key) /*if table[k] already exists*/
		return k;
	else if (table_1[k] == FLAG || table_1[k] == OPEN ) /*if table[k] is free*/
		table_1[k]=key;
	else {
		int j; /*variable that'll receive the new pos of key on table 2*/
		j = table_1[k];
		j = hash_2(j);
		table_2[j] = table_1[k];
		table_1[k] = key;
	}

	return k;
}

void printTable(int table[], int t){

	int i;
	for(i = 0; i < M; i++){
		if(table[i] != FLAG && table[i] != OPEN)
			printf("%d,T%d,%d\n",table[i], t, i);
	}

}

int search(int key, int table_1[], int *table) {

	int k;
	k = hash_1(key); /* find the position where key should be on table 1*/

	if (table_1[k] != OPEN ) { /*if position is ocupied*/
		if (table_1[k] == key) {
			*table = 1;
			return k;
		} else {
			*table = 2;
			return hash_2(key); /*return pos on table 2*/
		}
	} 

	return OPEN;
}

int remover(int key, int table_1[], int table_2[]) {

	int k;
	k = hash_2(key); /* find the position where key should be on table 1*/

	if (table_2[k] != OPEN ) { /*if position is ocupied*/
		if (table_2[k] == key) {
			table_2[k] = FLAG;
			return 1;
		} else if ( table_1[hash_1(key)] == key  ) {
			table_1[hash_1(key)] = FLAG; /*return pos on table 2*/
			return 1;
		}
	} 

	return 0;
}
