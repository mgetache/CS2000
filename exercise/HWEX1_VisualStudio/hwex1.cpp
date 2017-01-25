#include <iostream>     // input/output commands
using namespace std;    // standard library

int main()              // program entry function
{
	// Variable declarations
	float width;
	float length;
	float area;
	float perimeter;
	// Get user input:
	cout << "ROOM CALCULATOR" << endl;
	cout << endl;
	cout << "Room 1" << endl;
	cout << endl;
	cout << "Enter the width: ";        // text output
	cin >> width;                       // input from the user

	cout << "Enter the length: ";
	cin >> length;

	area = width * length;              // assignment statement
	perimeter = 2 * width + 2 * length;
										// Display results:
	cout << endl;                       // empty line
	cout << "Area: " << area << endl;
	cout << "Perimeter:" << perimeter << endl;
	cout << endl;
	
	cout << "Room 2" << endl;
	cout << endl;
	cout << "Enter the width: ";        
	cin >> width;                       

	cout << "Enter the length: ";
	cin >> length;

	area = width * length;              
	perimeter = 2 * width + 2 * length;
	
	cout << endl;                       
	cout << "Area: " << area << endl;
	cout << "Perimeter:" << perimeter << endl;
	while (true);
	return 0;           // end of program
}
