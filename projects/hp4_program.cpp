/*
MODIFY THIS FILE
*/

#include "hp4_program.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


//! Initializes the program state.
/**
    - Seed the random number generator:       srand( time( NULL ) );
    - Set the two pointer variables to nullptr; m_locationList and m_team.
    - Set the m_week variable to 0.
    - Call the Setup() function.
*/
Program::Program()
{
	 srand(time(NULL));
	 m_locationList = nullptr;
     m_team = nullptr;
	 m_week = 0;
	 Setup();

}

//! Cleans up the program.
/**
    - Call the Cleanup() function.
*/
Program::~Program()
{
	Cleanup();
}

//! Calls functions needed for program setup, and then calls Main().
/**
    - Call SetupDynamicArrays()
    - Call LoadLocations()
    - Call LoadPeople()
    - Call Main()


*/
void Program::Setup()
{
	SetupDynamicArrays();
	LoadLocations();
	LoadPeople();
	Main();
}

//! Cleans up the dynamic memory.
/**
    Safely free the memory allocated by m_team and m_locationList.


*/
void Program::Cleanup()
{
	delete[]  m_locationList;
	delete[] m_team;
}

//! Main game loop.
/**
    With the game loop...
        - Increment the week by 1
        - Call DisplayWeekStats()
        - Call UpdateTeam()
        - Call ScavengePhase()
        - Call ZombiePhase()
        - if everyone is dead (call IsEveryoneDead())...
            - done with game loop
        - Call RoundPause()

    - Once the game is over, call DisplaySummary().
*/
void Program::Main()
{
	bool notdone = true;
	while ( notdone)
	{
		m_week = m_week + 1;
		
		DisplayWeekStats();
		UpdateTeam();
		ScavengePhase();
		ZombiePhase();
		IsEveryoneDead();
		bool x = IsEveryoneDead();
		if (x == true)
		{
			notdone = false;
		}
		RoundPause();
	}
	DisplaySummary();
}

//! Display the base's stats and the current week.
/**
    Display the current week, as well as the current ammo and food held by the base.
*/
void Program::DisplayWeekStats()
{
	cout << "Week is : " << m_week << endl;
	cout << "Amount of ammo : " << m_base.GetAmmo() << endl;
	cout << "Amount of food : " << m_base.GetFood() << endl;
	
}

//! Update the team's hunger and health.
/**
    For each team member:
        - Call their Update() function
        - Look at the person's GetHunger() value, and request that amount of food from the base via TakeFood().
        - Have person Eat() that food.
        - Display that person's stats afterwards.
*/
void Program::UpdateTeam()
{
	for (int i = 0; i < m_teamCount; i++)
	{
		m_team [i].Update();
		int x = m_team[i].GetHunger();
		
		m_team[i].Eat(m_base.TakeFood(x));
		m_team[i].DisplayStats();
	}
}

//! Get player to choose scavenging locations and update base and team stats.
/**
    - Display a list of all the available locations.
    - Ask the user which 3 locations to scavenge at, get their input.
    - Do input validation to make sure they have selected 3 valid indices.
    - Calculate the total amount of ammo salvaged from all 3 locations.
    - Calculate the total amount of food salvaged from all 3 locations.
    - Display the results - amount of food and ammo scavenged (total of each.)
    - Add that amount of ammo and food back to the base.
*/
void Program::ScavengePhase()
{
	for (int i = 0; i < m_locationCount; i++)
	{
		cout <<i << "."<< m_locationList[i].GetName() << endl;
		
	}
	cout << "which three location to scavange" << endl;
	int c1, c2, c3;
	cin >> c1;
	cin >> c2;
	cin >> c3;
	
		
	int x = m_locationList[c1].GetAmmo() + m_locationList[c2].GetAmmo() + m_locationList[c3].GetAmmo();
	int y = m_locationList[c1].GetFood() + m_locationList[c2].GetFood() + m_locationList[c3].GetFood();
	cout << " The amount of food salvaged : " << y << endl << endl;
	cout << " The amount of ammo salvaged : " << x << endl << endl;
	m_base.AddAmmo(x);
	m_base.AddFood(y);
}

//! Check for zombie attack, and adjust team health and base stats.
/**
    - Generate a random number between 0 and 3.
    - If the random number is 0, then zombie attack:
        - Randomly select the zombie amount, between 1 and 3.
        - Calculate the total zombie health: 10 x the zombie count.
        - Display a message about the zombie attack, and how many zombies there are.
        - Determine if the base has enough ammo to fend off the zombies.
        - If there is not enough ammo:
            - Display a message that the base is out of ammo.
            - Subtract the amount of ammo the base has from the total zombie health.
            - Base ammo is now 0.
            - Zombies get a chance to attack a person. Randomly select a team member to attack.
            - Display a message of who the zombies attacked.
            - Call that team member's Hurt() function, with a random amount of damage between 10 and 20.
        - If there is enough ammo:
            - Subtract the total zombie health from the ammo count.
            - Display a message that the zombies have been killed, and how much ammo was used (equivalent to total zombie health).
*/
void Program::ZombiePhase()
{
	int x = rand() % 4;
	if (x == 0)
	{
		int Zamount = rand() % 3 + 1;
		int Zhealth = 10 * Zamount;
		cout << endl << "Zombies are attacking. There are  " << Zamount << "  Zombies attacking!" << endl;

		if (m_base.GetAmmo() < Zhealth)
		{
			cout << " The base is out of ammo" << endl;
			m_base.SetAmmo(0);
			int x = Zhealth - m_base.GetAmmo();
			cout << "The zombies attacked the following people" << endl;
			 
			int y = rand() % m_teamCount;
			cout << m_team[y].GetName() <<endl;
			m_team [y].Hurt(rand() % 10 + 10);
				
			}
			 if (m_base.GetAmmo() >= Zhealth)
			 {
				 int y = m_base.GetAmmo() - Zhealth;
				 m_base.SetAmmo(y);
				 cout <<endl<< "The zombies have been killled. The total ammo used is : " << Zhealth << endl;
			 }
		}

		
	}


//! Check if the entire team is dead. If everyone is dead, return true. Otherwise, return false.
/**
    Determine if everybody on the team is dead. If at least one person lives, then this will return false.
    If everybody is dead, return true.

    If everyone is dead, display a message that everyone is dead.

    @return <bool>      true if everyone is dead; false if at least one person is alive.
*/
bool Program::IsEveryoneDead()
{
	for (int i = 0; i < m_teamCount; i++)

	{
		bool x = m_team[i].IsDead();
		if (x == false)
		{
			return false;
		}
	}
    return true; // temp
}

//! Display the game summary.
/**
    Display the amount of weeks that the team survived.
*/
void Program::DisplaySummary()
{
	cout << " The total amount of weeks the team had survived is : "<< m_week << endl;
}

//! Ask the user for input before continuing the program execution.
/**
    Ask the user to enter a value before continuing.
    (Can just be a dummy cin into a variable that doesn't do anything.)
*/
void Program::RoundPause()
{
	cout<< endl << "please enter any number" << endl;
	int x;
	cin >> x;
}

//! Load location information from the locations.txt file.
/**
    Create an ifstream object and open the locations.txt file.

    Create three temporary variables: name (string), ammo (int), food (int).
    Also create a counter variable i (int) and initialize it to 0.

    Create a while loop, while the counter i is less than the location count m_locationCount...
        - Retrieve name, ammo, and food from the input file
        - Setup location #i via its Setup() function.
        - Increment the counter variable i.

    Close the input file when done.
*/
void Program::LoadLocations()
{
	ifstream file ("locations.txt");
	string name;
	int ammo;
	int food;
	int i = 0;
	while (i < m_locationCount)
	{
		
		file >> name >> ammo >> food;
		
			m_locationList[i].Setup(name, ammo, food);
			i++;
		
			
		
	}
	file.close();
}

//! Load a list of names from the names.txt file and randomly assign names to the team.
/**
    Load names:
        - Create an array of strings that will store names that are loaded in. The array size should be 207.
        - Create a counter variable i, initialize it to 0.
        - Create an input file stream, and open names.txt
        - Use a while loop to load data from the input file to the names array
            e.g., while ( input >> names[i] )
        - Within the while loop, increment i by 1.
        - Close the input file once done.

    Assign names to team:
        - For each team member, use the Setup() function.
        - Pass in a random name to the Setup function to assign the person a random name.
*/
void Program::LoadPeople()
{
	string names[207];
	int i = 0;
	ifstream Load;
	Load.open("names.txt");
	while (Load >> names[i])
	{
		
		i++;
	}
	Load.close();
	for (int i = 0; i < m_teamCount; i++)
	{
		m_team[i].Setup(names[rand () % 207]);
	}
}

//! Ask the user how many locations and team members are available, and allocate memory for the dynamic arrays.
/**
    Ask the player how many locations and how many team members to have.

    Max location size is 10. Utilize a while loop to validate that the user has entered
    an amount between 0 and 10.

    Team count has to be 1 or more, use a while loop to validate that the user has entered
    an amount greater than 1.

    Afterward, use the m_locationList and m_team pointers to create
    dynamic arrays with the sizes given.
*/
void Program::SetupDynamicArrays()
{
	cout << "how many locations are available (max 10)" << endl;
	int x;
	cin >> x;
	cout << "how many team members to have" << endl;
	int y;
	cin >> y;
	
		while (x > 10)
		{
			cout << "how many locations are available" << endl;
			cin >> x;
			
		}
		while (y <= 1)
		{
			cout << "how many team members to have" << endl;
			
			cin >> y;
		}
		m_locationList = new Location[x];
		m_team = new Person[y];

		m_locationCount = x;
		m_teamCount = y;
}
