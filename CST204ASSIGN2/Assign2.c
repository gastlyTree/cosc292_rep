/*
    program.c

    Nicholas Sutter
    CST240

*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Assign2"

//Create a vehicle with the given information passed in.
//There are no repairs at this point, so set the 'repairs' pointer to NULL
//Set 'iNumRepairs' to 0
//Return a pointer to the vehicle.
Vehicle * CreateVehicle (char * cVinP, char * cMakeP, char * cModelP)
{
    Vehicle * vPtr = (Vehicle *)malloc(sizeof(Vehicle));
    
    vPtr->cVin = 
}

//Create a repair with the information passed in.  Return a pointer to the repair.
Repair * CreateRepair (int iRepairID, double dCost, char * cDescriptonP, char * dateP)
{
    
}

//Given a vehicle and a pointer to a repair, add this repair directly to the vehicle
//'repairs' array.
void AddRepair(Vehicle * vP, Repair * rP)
{

}

//Display the data regarding the vehicle an all of its repairs
void DisplayVehicle(Vehicle v)
{
    
}

//This will locate a repair with the given id.  If the repair is not found,
//return NULL, else, return a pointer to the found repair.
Repair * FindRepair( Vehicle v, int id)
{
    
}

//Find the given repair in the vehicles repair list. If it is found, delete it.  Otherwise,
//do nothing, but print "Repair not found".
void DeleteRepair(int RepairID, Vehicle * v)
{
    
}
