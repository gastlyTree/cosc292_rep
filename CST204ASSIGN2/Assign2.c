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
    //create the stuct
    Vehicle * vPtr = (Vehicle *)malloc(sizeof(Vehicle));

    //add the inputed values to the struct
    vPtr->cVin = (char *)malloc((strlen(cVinP)+1)*sizeof(char));
    strcpy(vPtr->cVin, cVinP);
    
    vPtr->cMake = (char *)malloc((strlen(cMakeP)+1)*sizeof(char));
    strcpy(vPtr->cMake, cMakeP);

    vPtr->cModel = (char *)malloc((strlen(cModelP)+1)*sizeof(char));
    strcpy(vPtr->cModel, cModelP);

    vPtr->iNumRepairs = 0;

    //return a pointer to the struct
    return vPtr;
}

//Create a repair with the information passed in.  Return a pointer to the repair.
Repair * CreateRepair (int iRepairID, double dCost, char * cDescriptonP, char * dateP)
{
    //create the repair struct
    Repair * rPtr = (Repair *)malloc(sizeof(Repair));

    //add the repair
    rPtr->iRepairID = iRepairID;
    rPtr->dCost = dCost;
    rPtr->cDescripton = (char *)malloc((strlen(cDescriptonP)+1)*sizeof(char));
    strcpy(rPtr->cDescripton, cDescriptonP);

    rPtr->date = (char *)malloc((strlen(dateP)+1)*sizeof(char));
    strcpy(rPtr->date, dateP);

    //return a pointer to the Repair struct
    return rPtr;
}

//Given a vehicle and a pointer to a repair, add this repair directly to the vehicle
//'repairs' array.
void AddRepair(Vehicle * vP, Repair * rP)
{
    //create a new repair array that is one bigger than the old one
    Repair * newArrayPtr = (Repair *)malloc(sizeof(Repair) * (vP->iNumRepairs +1));
    //copy the old values to the new array
    memcpy(newArrayPtr, vP, sizeof(newArrayPtr));
    //increment the counter
    vP->iNumRepairs++;
    //add the new Repair to the new array
    vP->repairs[vP->iNumRepairs] = *rP;
    //free the old stuff
    free(vP.repairs);
    //reassign the old repair array
    vP->repairs = *newArrayPtr
}

//Display the data regarding the vehicle an all of its repairs
void DisplayVehicle(Vehicle v)
{
    //print out the vehicle info
    printf("Vin Number: %s\n", v.cVin);
    printf("Make: %s\t\tModel: %s\n", v.cMake, v.cModel);
    printf("Repairs\n");
    
    //loop through the repairs on the vehicle and display them
    for(int var = 0; var < v.iNumRepairs; var++)
    {
        printf("\tRepair Id: %d\n", v.repairs[var].iRepairID);
        printf("\tCost: %f\n", v.repairs[var].dCost);
        printf("\tDescription: %s\n", v.repairs[var].cDescripton);
        printf("\tDate: %s\n\n", v.repairs[var].date);
    }
}

//This will locate a repair with the given id.  If the repair is not found,
//return NULL, else, return a pointer to the found repair.
Repair * FindRepair( Vehicle v, int id)
{
    //create a repair pointer
    Repair * result;
    //default it to NULL
    result = NULL;
    //loop through the repairs
    for(int var = 0; var < v.iNumRepairs; var++)
    {
        //if the id's match'
        if(v.repairs[var].iRepairID == id)
        {
            //set the pointer tot he found repair
            result = &(v.repairs[var]);
        }
    }
    //return the pointer
    return result;
}

//Find the given repair in the vehicles repair list. If it is found, delete it.  Otherwise,
//do nothing, but print "Repair not found".
void DeleteRepair(int RepairID, Vehicle * v)
{
    //create a counter to reference later
    int startCount = v->iNumRepairs;
    //loop through the repairs to find the one to delete
    for(int var = 0; var < v->iNumRepairs; var++)
    {
        //if the id's match'
        if(v->repairs[var]->iRepairID == RepairID)
        {
            //set the repair to null
            v->repairs[var] = NULL;
            
            //should shink the array to it's new size'
        }
    }
    //if the count did not change
    if(v->iNumRepairs == startCount)
    {
        printf("Repair not found");
    }
}

//free a given vehicle and all of its repairs
void freeVehicle(char * vPtr)
{
    for(int var = 0; var < vPtr->iNumRepairs; var++)
    {
        free(vPtr->repairs[var]->cDescripton);
        vPtr->repairs[var]->cDescripton = NULL;
    }
    free(vPtr);
    vPtr = NULL;
}
