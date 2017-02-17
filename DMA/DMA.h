/*
 * DMA.h
 *
 *  Created on: Feb 15, 2017
 *      Author: ins222
 */

#ifndef DMA_H_
#define DMA_H_
#define MAX_STRING_SIZE 250
#define MAX_NAME_SIZE 20

//Method to print an array of integers
void printInts(int *, int);

//Return an array of integers that are dynamically allocated
int * getInts(int);

//Add an int to the end of a dynamic array
int * addInt(int *, int *);

//Get a dynamic string
char * getStringDynamic (char *);

//A function that creates a buffer with a name (MAX_NAME_SIZE) and SIN#
char * getNameAndSIN();

//A function to display a name and sin#
void printNameAndSIN(char *);


#endif /* DMA_H_ */
