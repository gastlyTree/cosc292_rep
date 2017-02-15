

#ifndef DMA_H_
#define DMA_H_
#define MAX_STRING_SIZE 250
#define MAX_NAME_SIZE 20

//Method to print an array of integers
void printInts(int *, int);

//return an array of integers that are synamically allocated
int * getInts(int);

//add an int tot he end of a dynamic array
int * addInt(int *, int *);

//get a dynamic string
char * getStringDynamic (char *);

//a function t hat creates a buffer with a name (MAX)NAME_SIZE) and SIN#
char * getNameAndSIN();

//a function to display a name and SIN#
void printNameAndSIN(char *);

#endif


