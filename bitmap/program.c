/*
 * program.c
 *
 *  Created on: Mar 28, 2017
 *      Author: ins222
 */

#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

void GreyScale(PIXEL * p)
{
	BYTE Grey = 0;
	Grey = (BYTE)(0.11*p->bBlu + 0.59*p->bGrn + 0.3*p->bRed);

	p->bBlu = Grey;
	p->bGrn = Grey;
	p->bRed = Grey;
}

void Negative(PIXEL * p)
{
    p->bBlu = (BYTE)(255 - p->bBlu);
    p->bGrn = (BYTE)(255 - p->bGrn);
    p->bRed = (BYTE)(255 - p->bRed);
}

void TestLoadImage()
{
    FILE * infile = GetFile("Enter file to open", "rb");
    FILE * outfile = GetFile("Enter output file name ", "w+b");

    //Create an image struct with both of it's pointers set to null
    IMAGE img = {NULL, NULL};

    //Read an image in
    ReadImage(&img, infile);
    //close the file
    fclose(infile);
    
    ManipulateImage(&img, Negative);

	//Write the image out to file
	WriteImage(&img, outfile);
	fclose(outfile);
}

int main (void)
{
	//printf("Sizeof bitmaphdr %d\n", sizeof(BITMAPHDR));
    TestLoadImage();

	return EXIT_SUCCESS;
}
