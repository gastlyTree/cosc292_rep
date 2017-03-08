/*
 * program.c
 *
 *  Created on: Mar 7, 2017
 *      Author: ins222
 */
/*
 Author: ins222
 Date: Mar 7, 2017
*/

#include <stdio.h>
#include <stdlib.h>


/*
General Notes on Bit Operations

A bitwise operation operates on one or more bit patterns a the level of their
individual bits.  It is a fast, primitive action directly supported by the processor,
and is used to manipulate values for comparisons and calculations.  On simple low-cost
processors, typically, bitwise operations are substantially faster for division, several times
faster for multiplication and sometimes significantly faster than addition.  While modern
processors perform addition and multiplication just as fast as bit operations, bitwise operations
do commonly use less power because of the reduced resources.
Source:  http://en.wikipedia.org/wiki/bitwise_operation
*/



//Prints a value as a string of bits (up to 32 bits)
void showBits(int value, int bytes)
{
	int filter = 1;
	int bit;

	char * bits = (char *)malloc(33);
	for (bit = 0; bit < bytes * 8; bit++)
	{
		if (value & filter)
		{
			bits[31 - bit] = '1';
		}
		else
		{
			bits[31 - bit] = '0';
		}
		filter *= 2;
	}
	//Put in the null terminator
	bits[32] = 0;
	printf("The value %d in binary is %s\n", value, &bits[32 - bytes * 8]);
	free(bits);
}

//Bitwise AND (&)
//If both bits in the compared postion are 1, the bit in the resulting binary
//representaion is 1, otherwise, the result is 0.
void bitAND ()
{
	unsigned char a = 0x48;
	unsigned char b = 0xB8;
	unsigned char result = a & b;
	printf("Bitwise AND of a and b is %x\n", result);
	showBits(result, sizeof(char));
}

//Bitwise OR (|)
//The result in each position is 1 if the first bit is 1 OR the second bit is 1
//OR both bits are 1, otherwise the result is 0.
void bitOR()
{
	unsigned char a = 0x48;
	unsigned char b = 0xB8;
	unsigned char result = a | b;
	printf("Bitwise OR of a and b is %x\n", result);
	showBits(result, sizeof(char));
}


//Bitwise "exclusive OR" - XOR (^)
//The result in each position is 1 if only the first bit is 1 OR only the second bit is 1,
//but will be 0 if both are 0 or both are 1.
//Can be used to model the state of something such as a two-way light switch.
void bitXOR()
{
	unsigned char a = 0x48;
	unsigned char b = 0xB8;
	unsigned char result = a ^ b;
	printf("Bitwise XOR of a and b is %x\n", result);
	showBits(result, sizeof(char));
}

//Bitwise NOT (~) flips the bits
void inversion()
{
	unsigned char a = 0x48;
	unsigned char result = ~a;
	printf("Bitwise inversion of a is %x\n", result);
	showBits(result, sizeof(char));
}


//Bitshift operators << and >>
//No comparison is made, bits ar simply moved left or right
//Shifting right n positions is equivalent to dividing by 2^n (2 to the power n).
//Shifting left n positions is equivalent to multiplying by 2^n.
void shiftOperators()
{
	short x = 37;
	int z = 1;
	char y = -128;
	char value = 0xD3;
	char mask = 0x0f;
	char result;

	//Display x in binary
	//printf("No shift in x\n");
	//showBits(x, sizeof(short));

	//Note that bit shifting to the left is the same as multiplying by a power of 2
	//printf("Shift x 1 bit to the left\n");
	//showBits(x << 1, sizeof(short));

	//Note that bit shifting to the right is the same as dividing by a power of 2
	//printf("Shift x 1 bit to the right\n");
	//showBits(x >> 1, sizeof(short));

	//Note that the right side is padded with 0's.
	//printf("Shift z 30 bits to the left\n");
	//showBits(z << 30, sizeof(int));

	//Note that the right shift of 1 resulted in padding of 1's, not 0's
	//If a value is a signed value, the padding is determined byt the value of the sign bit.
	//1 if it is set and 0 if it is not.
	//printf("Shift z 31 bits to the left and then 1 bit to the right\n");
	//showBits(z << 31 >> 1, sizeof(int));

	//printf("Shift y left by 1\n");
	//showBits(y << 1, sizeof(char));

	//printf("Shift y left by 1\n");
	//showBits(y >> 1, sizeof(char));

	//Masking demo
	printf("Value\n");
	showBits(value, sizeof(char));

	printf("Mask\n");
	showBits(mask, sizeof(char));

	//The lower nibble of value is
	showBits(value & mask, sizeof(char));

	//The upper nibble of value is
	showBits((value >> 4) & mask, sizeof(char));
}

unsigned char swapNibbles(unsigned char cVal)
{
    return (cVal << 4) | (cVal >> 4);    
}

int main (void)
{
	shiftOperators();

	return EXIT_SUCCESS;
}



