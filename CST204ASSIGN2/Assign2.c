/*
    Assign2.c

    Nicholas Sutter
    CST240

*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Assign2.h"

//Create a vehicle with the given information passed in.
//There are no repairs at this point, so set the 'repairs' pointer to NULL
//Set 'iNumRepairs' to 0
//Return a pointer to the vehicle.
Vehicle * CreateVehicle (char * cVinP, char * cMakeP, char * cModelP)
{
    Vehicle * vPtr = (Vehicle *)malloc(sizeof(Vehicle));
    
    vPtr->cVin = cVinP;
    vPtr->cMake = cMakeP;
    vPtr->cModel = cModelP;
    vPtr->iNumRepairs = 0;

    return vPtr;
}

//Create a repair with the information passed in.  Return a pointer to the repair.
Repair * CreateRepair (int iRepairID, double dCost, char * cDescriptonP, char * dateP)
{
    Repair * rPtr = (Repair *)malloc(sizeof(Repair));

    rPtr->iRepairID = iRepairID;
    rPtr->dCost = dCost;
    rPtr->cDescripton = (char *)malloc((strlen(cDescriptonP)+1)*sizeof(char));
    strcpy(rPtr->cDescripton, cDescriptonP);
    rPtr->date = dateP;

    return rPtr;
}

//Given a vehicle and a pointer to a repair, add this repair directly to the vehicle
//'repairs' array.
void AddRepair(Vehicle * vP, Repair * rP)
{
    Repair * newArrayPtr = (Repair *)malloc(sizeof(Repair) * (*vP.iNumRepairs +1));
    memcpy(newArrayPtr, vP, sizeof(newArrayPtr));
    *vP.iNumRepairs++;
    *vP.repairs[*vP.iNumRepairs] = *rP;
    free(vP.repairs);
    *vP.repairs = *newArrayPtr
}

//Display the data regarding the vehicle an all of its repairs
void DisplayVehicle(Vehicle v)
{
    printf("Vin Number: %s\n", v.cVin);
    printf("Make: %s\t\tModel: %s\n", v.cMake, v.cModel);
    printf("Repairs\n");
    
    for(int var = 0; var < v.iNumRepairs; ++var)
    {
        printf("\tRepair Id: %d\n", v.iNumRepairs[var].iRepairID);
        printf("\tCost: %f\n", v.iNumRepairs[var].dCost);
        printf("\tDescription: %s\n", v.iNumRepairs[var].cDescripton);
        printf("\tDate: %s\n\n", v.iNumRepairs[var].date);
    }
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

//free a given vehicle and all of its repairs
void freeVehicle(char * vPtr)
{
    for(int var = 0; var < vPtr->iNumRepairs; ++var)
    {
        free(vPtr->repairs[var]->cDescripton);
        vPtr->repairs[var]->cDescripton = NULL;
    }
    free(vPtr);
    vPtr = NULL;
}
