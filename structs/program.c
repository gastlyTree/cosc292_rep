/*
 * program.c
 *
 *  Created on: Mar 14, 2017
 *      Author: ins222
 */


/*
 Author: ins222
 Date: Mar 14, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void TestStructDeclarationBasicFormat()
{

	BYTE b;

	//Does this create a struct or a reference to a struct?
	//This is an instance, created on the stack (no call to malloc).
	struct BirthDate bd1;

	//Try to add a value to a struct member
	//It works!!
	bd1.day = 24;

	//How big is the struct?  Depends on the order the attributes are declared.
	//By default the attributes align on 4 byte boundaries (on this system).
	//Therefore, an int will always aling on a 4 byte boundary.  the 5 bytes for cName will
	//actually take up 8 bytes, even though only 5 are required.  If gender is placed after
	//cName, it will fit in the remaining 3 bytes of cName.  If added as the last attribute
	//gender will take up an entire 4 byte chunk.  So with byte alignment set to anything other
	//than 1, the order you declare the attributes might affect the overall size of the struct.
	printf("The size of the struct in bytes is %d\n", sizeof(bd1));

	//Instantiate a struct with data.
	struct BirthDate bd2 = {"Rob", 'm', 21, 3, 1987};
	DisplayBirthDateBasic(bd2);
	//change the day
	bd2.day = 15;
	//Change the month using pointer math (crazy way).
	//*(&bd2.day + 1) = 15;
	DisplayBirthDateBasic(bd2);

	//Display bd1 where not all attributes have been set.
	DisplayBirthDateBasic(bd1);
}

void TestStructDeclarationTypedef()
{
	BirthDateTD bd = {"Mike", 'm', 21, 3, 1980};

	//Can we do assignment? Yes
	BirthDateTD bd1 = bd;

	//Modify bd1
	bd1.day = 10;

	//Display both to see if a copy is made.  They are different.  In other words, a
	//byte by byte copy of the struct is made when doing assignment.
	DisplayBirthDateTypeDef(bd);
	DisplayBirthDateTypeDef(bd1);

	//Are structs pass by value (copy is made) or pass by ref?
	//No change in the day, so it is pass by value.
	AlterBirthDate(bd);
	DisplayBirthDateTypeDef(bd);

	AlterBirthDateByRef(&bd);
	DisplayBirthDateTypeDef(bd);
}

void TestDynamicallyAllocatedStructs()
{
	BirthDateTD * bdPtr = NULL;
	//This fails, no struct allocated.
	//(*bdPtr).day = 12;

	bdPtr = (BirthDateTD *)malloc(sizeof(BirthDateTD));
	//Unfortunately, the syntax for accessing attributes with a pointer is horrible!!!
	(*bdPtr).day = 12;
	//There is a short cut called the arrow operator
	bdPtr->day = 20;

	DisplayBirthDateTypeDef(*bdPtr);

	free(bdPtr);
	bdPtr = NULL;
}


void TestStudentStruct()
{
	int marks [] = {89, 92, 96, 100};
	student * sPtr = CreateStudent("Rob Miller", 123456789, marks, sizeof(marks)/sizeof(int));
	DisplayStudent(*sPtr);
	FreeStudent(sPtr);
}


int main (void)
{
	//TestStructDeclarationTypedef();
	TestDynamicallyAllocatedStructs();

	return EXIT_SUCCESS;
}
