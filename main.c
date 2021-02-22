#include<stdio.h>
#include"myht.h"
#include<stdlib.h>

int main(){

	int table_1[M], table_2[M];

	initTable(table_1);
	initTable(table_2);

	insert(10, table_1, table_2);
	insert(22, table_1, table_2);
	insert(4, table_1, table_2);
	insert(15, table_1, table_2);
	insert(59, table_1, table_2);

	int table;
	int test = search(4, table_1, &table);
	test = search(59, table_1, &table);
	printf("%d\n", test);

	printf("\n");
	printTable(table_1, 1);
	printTable(table_2, 2);

	return 0;
}
