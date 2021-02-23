#include <stdio.h>
#include "myht.h"
#include <stdlib.h>
#include <string.h>

int main(){

	int table_1[M], table_2[M];

	// initialize tables
	initTable(table_1);
	initTable(table_2);

	// parse inputs
	char *buffer = malloc(50 * sizeof(char));
	for(;fgets(buffer,50,stdin);){

		char *code=strtok(buffer," ");
		int key = atoi( strtok(NULL, " "));

		if(!strcmp("i",code))
			insert(key,table_1,table_2);
		else if (!strcmp("r",code))
			remover(key,table_1,table_2);
		else{
			perror("Invalid operation code\n");
			exit(INVALID_OPCODE);
		}

	}

	printTable(table_1, table_2);
	return SUCCESS;

}
