#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 10

enum BOOL {false,true};


void enumerations()
{
    int i=1;
    //Instance of enumeration.
    enum BOOL done = false;
    do
    {
        printf("%d\n",i);
        i++;

        if(i > 15)
        {
            done = true;
        }   
    }while(!done);

}

void enter_name(char * cNamePtr, char * cPrompt)
{
    printf("%s\n:", cPrompt);       
    scanf("%9s", cNamePtr);
}

void test_enter_name()
{
    char fName[MAX_NAME_SIZE];
    char lName[MAX_NAME_SIZE];

    enter_name(fName, "Enter First Name: ");
    enter_name(lName, "Enter Last Name: ");

    printf("\nName is: %s ", fName);
    printf("%s", lName);
}

void string_funcs()
{
    char string1 []= "hello world";
    char string2 []= "you have shit taste";
    //char string3 [40]= ;
    char string4 []= "Bob";

    //strlen
    printf("the length of string1 is: %d\n", strlen(string1));
    //just for fun, overwrite the null terminator in string4
    string4[3]= "?";
    printf("the length of string 4 is: %d\n", strlen(string4));
}

void string_cat(char * leftPtr, char * rightPtr)
{
        
}

void test_string_cat()
{
	char left [] = "Hello";
	char right [] = "World";
	char concat [20];

	concat[0] = '\0';

	string_cat(concat, left);
	string_cat(concat, " ");
	string_cat(concat, right);


	printf("%s\n", concat);
}

int main ()
{
    //enumerations();
    //test_enter_name();
    string_funcs();
    return EXIT_SUCCESS;
}
