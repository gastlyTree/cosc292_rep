/*
 * structs.h
 *
 *  Created on: Mar 14, 2017
 *      Author: ins222
 */

#ifndef STRUCTS_H_
#define STRUCTS_H_
#define NAME_SIZE 5
/*
Structs, also known as record, are similar to Classes in Java and C# with the exception
that structs do not contain methods (in C). Structs contain attributes (primitive types, pointers,
arrays, function pointers).  There is no support for inheritance or polymorphism.

Structs are generally defined in a header file.
*/

//Basic way to define a struct without a typedef statement.
//We don't really create structs this way.
struct BirthDate
{
	char cName [NAME_SIZE];
	char cGender;
	int day;
	int month;
	int year;
};

//A typedef statement can be used to simplify the declaration and use of a struct.
//Simple example:
typedef unsigned char BYTE;


//This is how YOU will make ALL of your structs in THIS class.
typedef struct
{
	//Attributes
	char cName [NAME_SIZE];
	char cGender;
	int day;
	int month;
	int year;
} BirthDateTD;


typedef struct
{
	//Some of the attributes are dynamically allocated.
	char * cNamePtr;
	int iStudentNum;
	int * iMarksPtr;
	int iMarkCount;
}student;

void DisplayBirthDateBasic(struct BirthDate);
void DisplayBirthDateTypeDef(BirthDateTD);
void AlterBirthDate(BirthDateTD);
void AlterBirthDateByRef(BirthDateTD *);
student * CreateStudent(char * cNamePtr, int iStudentNum, int * iMarksPtr, int iMarkCount);
void DisplayStudent(student);
void FreeStudent(student *);

#endif /* STRUCTS_H_ */
