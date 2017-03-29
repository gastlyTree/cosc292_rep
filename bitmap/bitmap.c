/*
 * bitmap.c
 *
 *  Created on: Mar 28, 2017
 *      Author: ins222
 */

#include "bitmap.h"
#include <malloc.h>


void ReadImage (IMAGE * imgPtr, FILE * infile)
{
	if(imgPtr != NULL && infile != NULL)
	{
		//Read the header first
		ReadHeader(imgPtr, infile);
		//If the header was read in
		if(imgPtr->bmHDR != NULL)
		{
			//Read in the data
			ReadData(imgPtr, infile);
		}
	}
}

void ReadHeader(IMAGE * imgPtr, FILE * infile)
{
	BOOL bSuccess = FALSE;
	//Allocate memory for the header
	if((imgPtr->bmHDR = (BITMAPHDR *)malloc(BMPHDRSIZE)) != NULL)
	{
		if(fread(imgPtr->bmHDR, BMPHDRSIZE, 1, infile) == 1)
		{
			bSuccess = TRUE;
		}
	}

	//What happens if we failed to read
	if(!bSuccess && imgPtr->bmHDR != NULL)
	{
		free(imgPtr->bmHDR);
		imgPtr->bmHDR = NULL;
	}
}

void ReadData(IMAGE * imgPtr, FILE * infile)
{
	BOOL bSuccess = FALSE;

	//The size of the image in bytes
	unsigned int imageSize = 0, padding = 0;
    
    //calculate the padding
    padding = imgPtr->bmHDR->dwWidth%4;

    //calculate the image size

    imageSize =
    (imgPtr->bmHDR->dwWidth*sizeof(PIXEL)+padding)*imgPtr->bmHDR->dwHeight;

    if((imgPtr->))

}

void WriteImage (IMAGE * imgPtr, FILE * outfile)
{

}

void WriteHeader(IMAGE * imgPtr, FILE * outfile)
{

}

void WriteData(IMAGE * imgPtr, FILE * outfile)
{

}
