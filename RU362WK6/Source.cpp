//***************************************************************************
//  FILENAME:	 AllenAssn5.cpp
//  DESCRIPTION: m
//
//  DATE:        10/1/15
//  CLASS/TERM:  CS362_X40_Data Structures - CU_CS362 - XIN_X40_15F8W1
//  DESIGNER:	 Andrae Allen
//  FUNCTIONS:	 main - reads values, performs calculations, & displays results
//***************************************************************************

#include <iostream> 
#include <fstream>
#include <cstdio> 
#include <iomanip>
#include <string>

using namespace std;

const int MIN_CAPACITY = 1;
const int MAX_CAPACITY = 30;
const int DEFAULT_CAPACITY = 30;



class course
{
private:
		string courseNumber; 
		string courseTitle; 
		int capacity; 
		int enrolledStudents;
		string StudentIDList[MAX_CAPACITY];
		

public:
	course();
	course(string cNumber, string cTitle, int cCap);
	
		void setCourseNum();
		void setCourseTitle();
		void setCapacity();

		void getCourseNum();
		void getCourseTitle();
		void getCapacity();
		void getNumEnrolled();

		void printCourse(); 
		void printStudentIDs(); 

		void addOneStudent(); 
		void dropOneStudent(); 

};

string convert2UpperCase(string stringInput);
string course2Manage();

int countArrayEntries(string targetArray[]);

int main()
{
	string listOfCourses[] = { "CS361", "CS362", "MT415", "111", "456"};

	course course1("CS361", "Control Structures", DEFAULT_CAPACITY);


	course course2("CS362", "Data Structures", 10);
	
	
	course course3;

	//course3.printCourse();

	countArrayEntries(listOfCourses);


	system("PAUSE");
	return 0;

}


course::course()
{
	courseNumber = "";
	courseTitle = "";
	capacity = MIN_CAPACITY;
	enrolledStudents = 0;

}

course::course(string cNumber, string cTitle, int cCap)
{
	courseNumber = cNumber;

	courseTitle = cTitle;

	capacity = cCap; 

}

void course::printCourse()
{

	cout << courseNumber << endl; 

}


string  course2Manage()
{
	int length;
	int errorCounter;
	string courseNumEntered;
	
	do
	{
		errorCounter = 0;

		cout << "Choose a course to manage :" << endl;
		cout << "CS361 – Control Structures" << endl;
		cout << "CS362 – Data Structures" << endl;
		cout << "MT415 – Linear Algebra" << endl;
		cout << "Enter the course number(e.g.CS200) or E to exit : ";

		cin >> courseNumEntered;
		courseNumEntered = convert2UpperCase(courseNumEntered);


		length = courseNumEntered.length();

		if (length < 5)
		{
			cout << "ERROR! The course number you entered  " << courseNumEntered << " is too short." << endl;
			cout << "System Expected 5 characters." << endl << endl;
			errorCounter++;

		}

		else if (length > 5)
		{
			cout << "ERROR! The course number you entered  " << courseNumEntered << " is too long. "<< endl;
			cout <<  "System Expected 5 characters." << endl << endl;
			errorCounter++;

		}

		else if (length == 5)
		{
			for (int index = 0; index < 2; index++)         // Used Loops for error checking 
			{
				if (!(isalpha(courseNumEntered[index])))
				{
					errorCounter++;
					//cout << "not a X " << endl;
				}
			}

			for (int index = 2; index < 5; index++)         // Used Loops for error checking 
			{
				if (!(isdigit(courseNumEntered[index])))
				{
					errorCounter++;
					//cout << "not a # " << endl;
				}
			}

		}


		if ((length == 5) && (errorCounter > 0))
		{
			{
				cout << endl;
				cout << "Error! You Enterd 5 characters, however not in the correct format." << endl;
				cout << "Please follow the format \"XX###\" Try again." << endl;
			}
		}

	}


	while (errorCounter > 0);

	
	
	
	return courseNumEntered;


}

string convert2UpperCase(string stringInput)
{
	int i = 0;
	char c;

	string upperCasedString;

	while (stringInput[i] != '\0')
	{
		// if character is a letter 
		if (isalpha(stringInput[i]))
		{
			c = stringInput[i];
			stringInput[i] = toupper(c);
			i++;
		}

		else
		{
			i++;
		}

	}

	upperCasedString = stringInput;

	return upperCasedString;

}

void  Search4Course(string target, string courseNumList[])
{
	
	int placeFound = 0;
	string validCourseNumber;

	int numOfEntries = countArrayEntries(courseNumList);


	while ((placeFound < numOfEntries) && (courseNumList[placeFound] != target))
			placeFound++;

	//If itemToDel was Found, delete it
	if (placeFound < numOfEntries)
	{

	}




	
}

int countArrayEntries(string targetArray[])
{

	int count = 0;

	for (int index = 0; targetArray[index] != ""; index++)
		if (targetArray[index] != "")
		{
			count++;
		}

	count--; 

	//cout << count << endl; 

	return count; 
}