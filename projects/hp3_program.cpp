/*
MODIFY THIS FILE
*/

#include "hp3_program.hpp"

#include <iostream>
using namespace std;


/* Setup() - 	Create the list of locations
 *              Allocate needed memory
 * */
void Program::Setup()
{
    // This is called automatically when the program begins
	*locationList;
	locationList = new Location [6];

	locationList[0].name = "Treasure room";
	locationList[0].description = "There is a lot of gold here!";

	locationList[3].name = "Gate room";
	locationList[3].description = "Almost there";

	locationList[2].name = "Middle room";
	locationList[2].description = "You can go anywhere";

	locationList[4].name = "Lost room";
	locationList[4].description = "You must be lost";

	locationList[5].name = "Trap room";
	locationList[5].description = "You must be traped";

	locationList[1].name = "Start room";
	locationList[1].description = "Your journy begins here";

	locationList[1].ptrToEast = &locationList[2];

	
	locationList[2].ptrToSouth = &locationList[4];
	locationList[2].ptrToWest = &locationList[1];

	locationList[4].ptrToNorth = &locationList[2];
	locationList[4].ptrToEast = &locationList[5];

	locationList[5].ptrToNorth = &locationList[3];
	locationList[5].ptrToWest = &locationList[4];


	locationList[3].ptrToWest = &locationList[2];
	locationList[3].ptrToNorth = &locationList[0];
	locationList[3].ptrToSouth = &locationList[5];

	ptrCurrentLocation = &locationList[1];
	ptrEndLocation = &locationList[0];

}



/* Cleanup() - 	Clean up memory allocated
 * */
void Program::Cleanup()
{
    // This is called automatically when the program ends
	if (locationList != nullptr)
	{
		delete [] locationList;

	}
	

}



/* Main() - Main program loop
 * */
void Program::Main()
{
	bool done = false;
	while (!done)
	{
		DisplayCurrentLocation();
		if (ptrCurrentLocation == ptrEndLocation)
		{
			cout << "You have reached your destination!" << endl;
			done = true;
			break;
		}
		
		string x = GetUserInput();
		if (x == "n" && ptrCurrentLocation->ptrToNorth != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToNorth;
		}
		else if (x == "s" && ptrCurrentLocation->ptrToSouth != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToSouth;
		}
		else if (x == "w" && ptrCurrentLocation->ptrToWest != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToWest;
		}
		else if (x == "e" && ptrCurrentLocation->ptrToEast != nullptr)
		{
			ptrCurrentLocation = ptrCurrentLocation->ptrToEast;
		}
		else if (x == "q")
		{
			done = true;
		}
		else
		{
			cout << "invalid choice" << endl << endl;
		}
	}
	cout << endl << "GOOD BYE!" << endl;
	while (true) {}
}



/* DisplayCurrentLocation() - Use the current location
 *              pointer to display the location's name
 *              and description, as well as which
 *              directions the player can move next.
 * */
void Program::DisplayCurrentLocation()
{
	cout << ptrCurrentLocation->name << endl << endl;
	cout << ptrCurrentLocation->description << endl << endl;

	

	if (ptrCurrentLocation->ptrToNorth != nullptr)
	{
		cout << "you can move              *north" << endl;
	}
	if (ptrCurrentLocation->ptrToSouth != nullptr)
	{
		cout << "you can move              *south" << endl;
	}
	if (ptrCurrentLocation->ptrToEast != nullptr)
	{
		cout << "you can move              *east" << endl;
	}
	if (ptrCurrentLocation->ptrToWest != nullptr)
	{
		cout << "you can move               *west" << endl;
	}
	
}



/* GetUserInput() - Display the list of options to the
 *                  user, then get their input and return
 *                  their choice.
 * */
string Program::GetUserInput()
{
	string x;
	cout << endl << endl << endl;
	cout << " where do you want to move to ?" << endl << endl;
	cout << "(e)ast" << "\t" << "(w)est" << "\t" << "(n)orth" << "\t" << "(s)outh" << "\t" << "(q)uit "<<endl << endl;
	cin >> x;
	cout << endl;
	return x ; // temp - replace me
}



/************************************/
/* Don't modify *********************/
/************************************/

Program::Program()
{
    locationList = nullptr;
    ptrCurrentLocation = nullptr;
    Setup();
}

Program::~Program()
{
    Cleanup();
}
