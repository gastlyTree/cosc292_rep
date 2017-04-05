/*
 * program.c
 *
 *  Created on: Mar 28, 2017
 *      Author: cst204
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
    p->bBlu = 255 - p->bBlu;
    p->bGrn = 255 - p->bGrn;
    p->bRed = 255 - p->bRed;
}

void SwapNibbles(PIXEL * p)
{
    p->bBlu = (p->bBlu << 4) | (p->bBlu>> 4);
    p->bGrn = (p->bGrn << 4) | (p->bGrn>> 4);
    p->bRed = (p->bRed << 4) | (p->bRed>> 4);
}

void Blend(PIXEL * p1, PIXEL * p2)
{
	p1->bBlu = p1->bBlu/2 + p2->bBlu/2;
	p1->bGrn = p1->bGrn/2 + p2->bGrn/2;
	p1->bRed = p1->bRed/2 + p2->bRed/2;
}


void Hide(PIXEL * p1, PIXEL * p2)
{
	p1->bBlu = (p1->bBlu & 0xF0) | (p2->bBlu >> 4);
	p1->bGrn = (p1->bGrn & 0xF0) | (p2->bGrn >> 4);
	p1->bRed = (p1->bRed & 0xF0) | (p2->bRed >> 4);
}

void TestTwoImages()
{
	FILE * infile1 = GetFile("Enter file to open ", "rb");
	FILE * infile2 = GetFile("Enter file to open ", "rb");
	FILE * outfile = GetFile("Enter output file name ", "w+b");
	IMAGE img1 = {NULL, NULL};
	IMAGE img2 = {NULL, NULL};

	ReadImage(&img1, infile1);
	ReadImage(&img2, infile2);
	fclose(infile1);
	fclose(infile2);

	ManipulateTwoImages(&img1, &img2, Hide);

	//Write the image out to file
	WriteImage(&img1, outfile);
	fclose(outfile);


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
    
    ManipulateImage(&img, SwapNibbles);

	//Write the image out to file
	WriteImage(&img, outfile);
	fclose(outfile);
}

int main (void)
{
	//printf("Sizeof bitmaphdr %d\n", sizeof(BITMAPHDR));
    //TestTwoImages();
    TestLoadImage();

	return EXIT_SUCCESS;
}
