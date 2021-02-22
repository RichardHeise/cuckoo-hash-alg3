#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
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

int parseKey(char* str) {
	char aux_str[MAX];
	strcpy(aux_str, str);
	return atoi(strtok(aux_str, ","));
}

static int Sort_aux(const void *a, const void *b) {
	int aux_a = parseKey(*(char **)a);
	int aux_b = parseKey(*(char **)b);
	if (aux_a < aux_b) return -1;
	if (aux_a > aux_b) return 1;
	return 0;
}

void printTable(int table_1[], int table_2[]){

	char** output = malloc(sizeof(char) * M * 2);

	int i;
	int j = 0;
	for(i = 0; i < M; i++){
		if(table_1[i] != FLAG && table_1[i] != OPEN) {
			char *aux = malloc(sizeof(char) * MAX);
			snprintf(aux, MAX, "%d,T1,%d", table_1[i], i);
			output[j] = aux;
			j++;
		}
		if(table_2[i] != FLAG && table_2[i] != OPEN) {
			char *aux = malloc(sizeof(char) * MAX);
			snprintf(aux, MAX, "%d,T2,%d", table_2[i], i);
			output[j] = aux;
			j++;
		}
	}

	qsort(output, j, sizeof(char*), Sort_aux);

	for(i = 1; i < j; i++) {
		printf("%s\n", output[i]);
	}
}

int search(int key, int table_1[], int table_2[]) {

	int k;
	k = hash_1(key); /* find the position where key should be on table 1*/

	if (table_1[k] != OPEN ) { /*if position is ocupied*/
		if (table_1[k] == key) {
			return k;
		} else if ( table_2[hash_2(key)] == key) {
			return hash_2(key); /*return pos on table 2*/
		}
	} 

	return OPEN;
}

int remover(int key, int table_1[], int table_2[]) {

	int k;
	k = hash_2(key); /* find the position where key should be on table 2*/

	if (table_2[k] != OPEN ) { /*if position is ocupied*/
		if (table_2[k] == key) {
			table_2[k] = FLAG;
			return 1;
		} else if ( table_1[hash_1(key)] == key  ) {
			table_1[hash_1(key)] = FLAG;
			return 1;
		}
	} 

	return 0;
}
