/*
    program.c

    Nicholas Sutter
    CST240

*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Assign2.h"

void main (void)
{
	Vehicle * v = CreateVehicle("DFASDGASDGD", "GMC", "Sierra");
	AddRepair(v, CreateRepair(10, 23.4, "sparkplugs", "01-01-1999"));
	AddRepair(v, CreateRepair(20, 12.3, "engine", "01-01-1999"));
	AddRepair(v, CreateRepair(30, 31.2, "oil", "01-01-1999"));
	DisplayVehicle(*v);
	DeleteRepair(20,v);
	DisplayVehicle(*v);
    freeVehicle(v);
}
