#include <iostream>
#include <string>
using namespace std;

// A person struct - by making a struct, we can then
// declare a variable whose data-type is Person.
// The Person data-type contains two internal variables:
// name, a string	&	home, a string pointer

struct Location
{
	string city;
	string state;
	int zip;
};
struct Person
{
	string name;
	Location* home;
};


void SetupLocations(Location* locationList);
void SetupPeople(Person* personList, int personCount, Location* locationList, int locationCount);

int main()
{
	Location* locationList;							// Create a string* pointer
	locationList = new Location[5];					// Use the pointer to create a dynamic array
	SetupLocations(locationList);					// Call function to set up data


	Person* personList;								// Create a Person* pointer
	personList = new Person[4];						// Use the pointer to create a dynamic array
	SetupPeople(personList, 4, locationList, 5);	// Call function to set up data


													// Display all people info
	for (int p = 0; p < 4; p++)
	{
		// Display each person's name and their home location's name.
		// Note that Person.home is a POINTER. You have to dereference
		// the pointer to get its value, otherwise it will just
		// give you a memory address.

		cout << personList[p].name << "\t";
		cout<< personList[p].home->city << "       "<< personList[p].home->state<< "   " << personList[p].home->zip<<endl;
	}


	// Make sure to free up the memory afterward!
	delete[] locationList;
	delete[] personList;
	while (true) {}
	return 0;
}

void SetupLocations(Location* locationList)
{
	locationList[0].city = "Raytown";
	locationList[1].city = "Grandview";
	locationList[2].city = "Independence";
	locationList[3].city = "Liberty";
	locationList[4].city = "Belton";

	locationList[0].state = "Missouri";
	locationList[1].state = "Missouri";
	locationList[2].state = "Missouri";
	locationList[3].state = "Missouri";
	locationList[4].state = "Missouri";

	locationList[0].zip = 64133;
	locationList[1].zip = 64030;
	locationList[2].zip = 64050;
	locationList[3].zip = 64069;
	locationList[4].zip = 64012;
}

void SetupPeople(Person* personList, int personCount, Location* locationList, int locationCount)
{
	for (int p = 0; p < personCount; p++)
	{
		cout << "Person " << p << "'s name: ";

		cin >> personList[p].name;

		cout << endl << "Locations:" << endl;
		for (int c = 0; c < locationCount; c++)
		{
			cout << c << ". " << locationList[c].city<< "    " <<locationList[c].state<< "   "<< locationList[c].zip<< endl;
		}
		cout << personList[p].name << "'s home: ";

		personList[p].home = new Location;
		int index;
		cin >> index;

		personList[p].home->city = locationList[index].city;
		personList[p].home->state = locationList[index].state;
		personList[p].home->zip = locationList[index].zip;
		
	}
}