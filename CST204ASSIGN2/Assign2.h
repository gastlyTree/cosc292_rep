/*
    Assign2.h

    Nicholas Sutter
    CST240

*/

#ifndef ASSIG2_H
#define ASSIG2_H
#define MAX_VIN 18
#define MAKE 15
#define MODEL 15
#define DATE_SIZE 11

typedef struct
{
	int iRepairID;
	double dCost; //Cost in dollars
	char * cDescripton; //Description of the repair
	char date [DATE_SIZE];  //Date in the format 24/03/2010
}Repair;

typedef struct
{
	char cVin [MAX_VIN]; //17 characters max
	char cMake [MAKE]; //14 characters max
	char cModel [MODEL]; //14 characters max
	Repair ** repairs; //A pointer to an array of dynamically allocated repairs
	int iNumRepairs;
}Vehicle;

//Create a vehicle with the given information passed in.
//There are no repairs at this point, so set the 'repairs' pointer to NULL
//Set 'iNumRepairs' to 0
//Return a pointer to the vehicle.
Vehicle * CreateVehicle (char * cVinP, char * cMakeP, char * cModelP);
//Create a repair with the information passed in.  Return a pointer to the repair.
Repair * CreateRepair (int iRepairID, double dCost, char * cDescriptonP, char * dateP);
//Given a vehicle and a pointer to a repair, add this repair directly to the vehicle
//'repairs' array.
void AddRepair(Vehicle * vP, Repair * rP);
//Display the data regarding the vehicle an all of its repairs
void DisplayVehicle(Vehicle v);
//This will locate a repair with the given id.  If the repair is not found,
//return NULL, else, return a pointer to the found repair.
Repair * FindRepair( Vehicle v, int id);
//Find the given repair in the vehicles repair list. If it is found, delete it.  Otherwise,
//do nothing, but print "Repair not found".
void DeleteRepair(int RepairID, Vehicle * v);
#endif
