/*
 * funcs.h
 *
 *  Created on: Mar 21, 2017
 *      Author: ins222
 */

#ifndef FUNCS_H_
#define FUNCS_H_

//Define a function pointer type.  You are specifying the signature of the
//functions that your pointer will point to.  The part in all caps is the function
//pointer type.

//A function pointer to a function that returns an int and takes an int.
typedef int (*FNPTR_TYPE) (int); //The pointer name can be anything

//An example of a function that utilizes a function pointer.
void iterateNumbers (int iArray [], int iSize, FNPTR_TYPE fn);


#endif /* FUNCS_H_ */
