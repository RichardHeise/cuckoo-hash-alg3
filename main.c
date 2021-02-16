#include<stdio.h>
#include"myht.h"
#include<stdlib.h>

int main(){

	int table_1[M] = {FLAG}, table_2[M] = {FLAG};

	insert(10, table_1, table_2);
	insert(22, table_1, table_2);
	insert(4, table_1, table_2);
	insert(15, table_1, table_2);
	insert(59, table_1, table_2);

	printTable(table_1);
	printTable(table_2);

	return 0;
}
