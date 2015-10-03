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

string uiCourseNum(); 
string convert2UpperCase(string stringInput);


int main()
{
	course course1("CS361", "Control Structures", DEFAULT_CAPACITY);


	course course2("CS362", "Data Structures", 10);
	
	
	course course3;

	course3.printCourse();

	uiCourseNum();


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

string uiCourseNum()
{
	int length;
	int errorCounter;
	string courseNumEntered; 

	
	
	do
	{
		errorCounter = 0;

		cout << "Please enter a course number: ";
		cin >> courseNumEntered;

		courseNumEntered = convert2UpperCase(courseNumEntered);
		length = courseNumEntered.length();

		if (length < 5)
		{
			cout << "ERROR! Input " << courseNumEntered << " is not long enough. System Expected 5 characters." << endl << endl;
			errorCounter++;

		}

		else if (length > 5)
		{
			cout << "ERROR! Input " << courseNumEntered << " is too long. System Expected 5 characters." << endl << endl;
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