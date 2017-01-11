#include <stdio.h>
#include <stdlib.h>
//Similar to "Using" statements in C# or "Import" in Java
//Tells the pre-processor that there is some existing code that we want to utilize in this code.
//Note that the <> brackets tell the pre-processor to look in the built in standard libraries.
//We will use "" instead of <> to tell the pre-processor to look in the local project first.

//Note that the pre-processor reads the current source file looking for pre-processor directives (start with #).
//In this case, the #include tells the pre-processor to find stdio.h and substitute its text into this file.


//Another type of pre-processor directive is the "define" statement.
//Note that the define statement does not end with a semi-colon.
#define PI 3.14159
#define Radius 2


void PrimitiveDataTypes()
{
	char c = 'R';
	int x = 80;
	float f = PI;
	double d = 12345.6597;
	//Print the value of variables
	//Note the use of the format specifiers that start with %
	printf("The value of c is %c\n", c);
	printf("The value of c as an int %d\n", c);
	printf("The value of x is %d\n", x);
	printf("The value of x as a character %c\n", x);
	printf("The value of f is %f\n", f);
	//use format specifiers to modify output. For example, to display 10 digits total, with two decimals:
	printf("The value of d is %10.2f\n", d);

	//What are the sizes of each data type
	//The sizeof() function is used to return the size of a datatype, struct, or an array, etc.
	printf("The size of char is %d\n", sizeof(c));
	printf("The size of an int is %d\n", sizeof(x));
	printf("The size of a float is %d\n", sizeof(float));
	printf("The size of a double is %d\n", sizeof(d));

}

//Modifiers tot he primitive data types
void Modifiers()
{
	//note that c defaults to signed values

	//unsigned --> positive values only
	unsigned char e = 255;
	signed char c = 127;

	//short and long
	short int x;
	short y;
	long int z;
	

	//add one to e and c
	e = e + 1;
	c = c + 1;	
    
	printf("The value of e is %d\n",e);	
	printf("The value of c is %d\n",c);
    
	//display the size of short and long modifiers. Note that a short is 2 bytes inthis environment
	printf("The size of x and y are %d and %d respectively.\n", sizeof(x), sizeof(y));
	printf("the size of z id %d.\n", sizeof(z));
    
}

//strings in c --> wait a minute! there are no strings in c, well not string
//objects
void StringDemo()
{
    char myChar = 'm'; //Single quotes surround any single character.
    char s1[] = "Bill"; //can initialize a string literal to a char []
    char s2[5];
    
    //s2 = "John"; Can't a literal string to char array

    //the only way to assign "John" is char by char
    s2[0] = 'J';
    s2[1] = 'o';
    s2[2] = 'h';
    s2[3] = 'n';
    //make sure you always have the null terminator at the end of your strings
    s2[4] = '\0'; //or s2[4] = 0;    

    //note the use of %s for strings
    printf("The value of string s1 is %s\n", s1);
    printf("The size of the string in bytes is %d\n", sizeof(s1));

    printf("The value of string s2 is %s\n", s2);
    printf("The size of the string in bytes is %d\n", sizeof(s2));
}


//casting in c
void CastDemo()
{
    int x;
    float y =3.2f;
    float fahr = 0;
    float celc = 0;

    //assign y to x
    x = y;
    printf("The value of x is%d\n", x);

    //temp conversion
    printf("The tempurature in farenheight is %f\n", fahr);
    celc = ((float)5/9)*(fahr-32);
    printf("The tempurature in Celcius is %f\n", celc);
}

void DemoConstants()
{
	//note the keyword const
	const float pi = 3.14159;
	printf("The value of pi id %f\n", pi);
}

int main (void)
{
	//Use printf to output to the console.
	//printf("Hello cruel world\n");

	//PrimitiveDataTypes();
	//Modifiers();
	//DemoConstants();
    //CastDemo();
    StringDemo();
    //normally a c program returns 0 if successful
    return EXIT_SUCCESS;
}
