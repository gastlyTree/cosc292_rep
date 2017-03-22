/*
 * program.c
 *
 *  Created on: Mar 21, 2017
 *      Author: CST204
 */

#include <stdio.h>
#include <stdlib.h>

/*
A union is a datatype that is similar in syntax to a struct.  A
union can have several attributes, however, only one is assigned at a time.
The memory reserved by a union is equal to that of its largest member.

Example, suppose we want to store how much fertilizer a farmer purchased.
Fertilizer is sold in various units.  The following union could be used
to store the amount purchased.
*/

typedef union
{
	unsigned char truckloads;
	unsigned int bags;
	double tons;
} FertilzerQuantity;


typedef struct
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char t;
}Pixel;

typedef union
{
	unsigned int iVal;
	Pixel components;
}ColorVal;



void TestFertilizerUnion()
{
	//Create an instance of a union
	FertilzerQuantity fq;

	//How big is the union?  The size is 8, the size of the attribute "tons"
	printf("The size of an instance of FertilizerQuantity is %d\n", sizeof(fq));
	//Assign truckloads
	fq.truckloads = 3.0;
	//Assign to bags.  Note that truckloads will be overwritten.
	fq.bags = 400;
	//Overwrite bags
	fq.tons = 12345.78965;




	printf("The value of truckloads is %d\n", fq.truckloads);
	printf("The value of bags is %d\n", fq.bags);
	printf("The value of tons is %f\n", fq.tons);


	printf("The address of truckloads is %p\n", &fq.truckloads);
	printf("The address of bags is %p\n", &fq.bags);
	printf("The address of tons is %p\n", &fq.tons);

}

void TestColourConversion()
{
	ColorVal c;

	c.iVal = 0x2A3BFF1C;

	printf("The whole colour as a hex val is %x\n", c.iVal);

	printf("The red component is %x\n", c.components.r);
	printf("The green component is %x\n", c.components.g);
	printf("The blue component is %x\n", c.components.b);
	printf("The opacity component is %x\n", c.components.t);

}



int main (void)
{
	//TestFertilizerUnion();
	TestColourConversion();

	return EXIT_SUCCESS;
}
