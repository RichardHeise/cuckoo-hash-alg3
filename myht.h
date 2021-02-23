#define M 11
#define FLAG -5
#define MAX 40
#define OPEN -4
#define INVALID_OPCODE -2
#define MEMORY_ERROR -3
#define SUCCESS 1

/*
 * Function to initiate a hash table
 * Receives the hash table to be initiated
 */
void initTable (int table[]);

/*
 * First hashing function
 * Receives an int key to be hashed
 */
int hash_1(int key);

/*
 * Second hashing function
 * Receives an int key to be hashed
 */
int hash_2(int key);

/*
 * Funcion to insert values into tables
 * Receives an int key and the two tables
 */
int insert(int key, int table_1[], int table_2[]);

/* 
 * Function to print table in order
 * Receives both tables
 */
void printTable(int table_1[], int table_2[]);

/*
 * Function to search for values in the hash tables
 * Receives an int key and the first table.
 */
int search(int key, int table_1[], int table_2[]);


/*
 * Function to remove values in the hash tables
 * Receives an int key and the two tables.
 */
int remover(int key, int table_1[], int table_2[]);
