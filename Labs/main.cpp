#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Student
{
    string surname;
    string givenName;
    string degree;
    float gpa;
	string classes[4];

    void Display()
    {
        cout << endl;
        cout << surname << ", " << givenName;
        cout << "\t" << degree << " (" << gpa << " gpa)" << endl;
		cout << "CLASSES: " << endl;
		cout << "\t" << classes[0] << endl;
		cout << "\t" << classes[1] << endl;
		cout << "\t" << classes[2] << endl;
		cout << "\t" << classes[3] << endl;
		
		 cout << endl;
    }
};

Student* ReadStudentList( string filename, int& studentCount )
{
    Student* studentList = nullptr;

    ifstream input( filename );

    // First line of text file is the amount of students
    input >> studentCount;

    studentList = new Student[ studentCount ];

    for ( int i = 0; i < studentCount; i++ )
    {
        input >> studentList[i].surname;
        input >> studentList[i].givenName;
        input >> studentList[i].degree;
        input >> studentList[i].gpa;
		for (int k = 0; k < 4; k ++)
		{
			input >> studentList[i].classes[k];
		}

    }

    input.close();

    cout << studentCount << " students loaded" << endl;

    return studentList;
}

void SaveStudentList( string filename, const Student* studentList, int studentCount )
{
    ofstream output( filename );

    output << studentCount << endl;
    for ( int i = 0; i < studentCount; i++ )
    {
		output << setw(20)
			<< studentList[i].surname << setw(15)
			<< studentList[i].givenName << setw(10)
			<< studentList[i].degree << setw(10)
			<< studentList[i].gpa << endl;
			
		for (int k = 0; k < 4; k++)
			{
				output << " " << studentList[i].classes[k] << endl;
			}
		
    }

    output.close();

    cout << "File saved" << endl;
}

void DisplayStudents( const Student* studentList, int studentCount )
{
    for ( int i = 0; i < studentCount; i++ )
    {
        string name = studentList[i].surname + ", " + studentList[i].givenName;
		cout << i << ". \t " << setw(20)
			<< name << setw(15)
			<< "DEGREE: " << studentList[i].degree << setw(15)
			<< "GPA: " << studentList[i].gpa << endl;
		
    }
}

void MakeANote()
{
    ofstream output( "USE_THIS_DIRECTORY.TXT" );
    output << "PUT YOUR INPUT FILE IN THIS DIRECTORY!" << endl;
    output.close();
}

int main()
{
    MakeANote();

    int studentCount;
    Student* students = ReadStudentList( "studentList_classes.txt", studentCount );

    bool done = false;
    while ( !done )
    {
        cout << endl << endl;

        DisplayStudents( students, studentCount );

        cout << endl << "Enter a student ID, between 0 and " << studentCount - 1 << ", " << endl;
        cout << "OR enter -1 to save quit." << endl;
        cout << " >> ";
        int modifyIndex;
        cin >> modifyIndex;

        if ( modifyIndex < -1 || modifyIndex >= studentCount )
        {
            // Invalid!
            continue;
        }

        if ( modifyIndex == -1 )
        {
            break;
        }

        students[ modifyIndex ].Display();

        cout << "Modify which field?" << endl;
        cout << " 1. Surname \n 2. Given name \n 3. Degree \n 4. GPA \n 5. Class " << endl;
        cout << "\n >> ";
        int choice;
        cin >> choice;

        while ( choice < 1 || choice > 5 )
        {
            cout << "Invalid choice, try again: ";
            cin >> choice;
        }

        if ( choice == 1 )
        {
            cout << "Enter new surname: ";
            cin >> students[ modifyIndex ].surname;
        }
        else if ( choice == 2 )
        {
            cout << "Enter new given name: ";
            cin >> students[ modifyIndex ].givenName;
        }
        else if ( choice == 3 )
        {
            cout << "Enter new degree: ";
            cin >> students[ modifyIndex ].degree;
        }
        else if ( choice == 4 )
        {
            cout << "Enter new gpa: ";
            cin >> students[ modifyIndex ].gpa;
        }
        else if ( choice == 5 )
        {
			int k;
			cout << "what index";
			cin >> k;
			cout << "Enter new class: ";
			
			cin >> students[modifyIndex].classes[k];
            
        }
    }

    SaveStudentList( "studentList_classes.txt", students, studentCount );

    if ( students != nullptr )
    {
        delete [] students; // free student array
    }
    return 0;
}
