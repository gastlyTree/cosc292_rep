/*
 * GIF_Functions.c
 *
 *  Created on: Apr 3, 2017
 *      Author: cst204
 */

#include <malloc.h>
#include "GIF_Functions.h"

//Get handle to a gif file
FILE * GetFile(char * cPrompt, char * cMode)
{
    
}
//Functions to read and write image data to/from files
void ReadImage(IMAGE * img, FILE * infile)
{
    
}

void ReadHeader(IMAGE * img, FILE * infile)
{
    
}

void ReadColorTable(IMAGE * img, FILE * infile)
{
    
}

void ReadData(IMAGE * img, FILE * infile);
{
    
}

void WriteImage(IMAGE * img, FILE * outfile)
{
    
}

void WriteHeader(IMAGE * img, FILE ** outfile)
{
    
}

void WriteColorTable(IMAGE * img, FILE ** outfile)
{
    
}

void WriteData(IMAGE * img, FILE * outfile)
{
    
}

//Functions to manipulate pixels
//We a need a function pointer that will point to functions that can manipulate
//a PIXEL
BOOL ManipImage(IMAGE * img, GIF_FUNC_PTR pixelFunc)
{
    
}

//Free the memory that was dynamically allocated
void FreeImage(IMAGE * img)
{
    
}
