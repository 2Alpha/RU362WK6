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
const int IGNORE_AMOUNT = 100;

struct crossReference
{
	string objectName;
	string ClassNumber;

};

class course
{
private:
		string courseNumber; 
		string courseTitle; 
		int capacity; 
		int enrolledStudents;
		string StudentIDList[MAX_CAPACITY];
		
		static string listOfCourses[]; 
		int scnRunCounter = 0;
		int sctRunCounter = 0; 

		//string course::listOfCourses[] = { "CS361", "CS362", "MT415", "E" };
		

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
		void printCourseNumber();
		void printCourseTitle();
		void printStudentIDs(); 

		void addOneStudent(); 
		void dropOneStudent(); 

		friend ostream& operator<< (ostream& outStream, const course& data);

};

string course::listOfCourses[] = { "CS361", "CS362", "MT415", "E" };

string convert2UpperCase(string stringInput);
string course2Manage(course c1, course c2, course c3);

int countArrayEntries(string targetArray[]);
bool Search4Course(string target, string courseNumList[]);

void CourseManagementMenu(string mainMenuResponse, crossReference courseData[], course c1, course c2, course c3);

int courseNumFormatCheck(string courseNumEntered); 
int courseTitleCheck(string title2Check);

int main()
{
	crossReference courseProperties[3];

	courseProperties [0].objectName = "course1";
	courseProperties [0].ClassNumber = "CS361";

	courseProperties [1].objectName = "course2";
	courseProperties [1].ClassNumber = "CS362";

	
	//string listOfCourses[] = { "CS361", "CS362", "MT415", "E"};
	string mainMenuResponse;

	course course1("CS361", "Control Structures", DEFAULT_CAPACITY);


	course course2("CS362", "Data Structures", 10);
	
	
	course course3;

	course3.setCourseNum();
	course3.setCourseTitle();



	do
	{
		mainMenuResponse = course2Manage(course1, course2, course3);

		CourseManagementMenu(mainMenuResponse, courseProperties, course1, course2, course3);


	} while (mainMenuResponse != "E");


	//CourseManagementMenu();

	// cout << course2; // over load ready 

	//course3.printCourse();

	//cout << "# " << countArrayEntries(listOfCourses) << endl; ;

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

	enrolledStudents = 0;

	capacity = cCap; 

}

void course::printCourse()
{

	cout << courseNumber << endl; 

}
void course::printCourseNumber()
{
	cout << courseNumber; 

}


void course::printCourseTitle()
{//
	cout << courseTitle;

}


void course::setCourseNum()
{
	string desiredCourseNum;

	if (scnRunCounter < 1)
	{	
		do
		{
			cout << "Initialze object named course3 with a course number: ";
			cin >> desiredCourseNum;
			desiredCourseNum = convert2UpperCase(desiredCourseNum);
		}
		while (courseNumFormatCheck(desiredCourseNum) > 0);

		courseNumber = desiredCourseNum;

	}

	
	else
	{
		do
		{
			cout << endl;
			cout << "Enter the desired Course Number : " << endl;
			cout << "Remember format must be XX###: ";

			cin >> desiredCourseNum;
			desiredCourseNum = convert2UpperCase(desiredCourseNum);

		} while (courseNumFormatCheck(desiredCourseNum) > 0);

		cout << endl;
		cout << "Success!" << endl;
		cout << "You modfied course" << courseNumber << " to course # " << desiredCourseNum << endl;

		courseNumber = desiredCourseNum;
	}
}

void course::setCourseTitle()
{
	string desiredCourseTitle; 

	if (sctRunCounter < 1)
	{
		do
		{
			cout << "Initialze object named course3 with course a Title: ";
			cin.clear();
			getline(cin>>ws, desiredCourseTitle);

		} while (courseTitleCheck(desiredCourseTitle) > 0);

		courseTitle = desiredCourseTitle;


	}


}

string  course2Manage(course c1, course c2, course c3)
{
	int length;
	int formatErrorCounter;
	string courseNumEntered;
	bool courseExist = false; 
	
	do
	{
		do
		{
			cout << endl;
			cout << "Choose a course to manage :" << endl;
			c1.printCourseNumber();  cout << " - "; c1.printCourseTitle(); cout << endl; 
			c2.printCourseNumber();  cout << " - "; c2.printCourseTitle(); cout << endl;
			c3.printCourseNumber();  cout << " - "; c3.printCourseTitle(); cout << endl;
			cout << "Enter the course number(e.g.CS200) or E to exit : ";

			cin >> courseNumEntered;
			courseNumEntered = convert2UpperCase(courseNumEntered);

		} while (courseNumFormatCheck(courseNumEntered) > 0);


		//courseExist = Search4Course(courseNumEntered, existingCourses);

	} while (courseExist != true);
	
	
	
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

bool Search4Course(string target, string courseNumList[])
{
	
	int placeFound = 0;
	int numOfEntries = countArrayEntries(courseNumList);
	bool courseFound;

		
		while ((placeFound < numOfEntries) && (courseNumList[placeFound] != target))
		{
			placeFound++;		
			//cout << "looking" << endl;
		}


		if (placeFound < numOfEntries)
		{
			courseFound = true;
			cout << endl;
			cout << "Success! Input of " << target << " was accepted" << endl << endl;
		}

		else
		{
			courseFound = false;
			cout << endl; 
			cout << "ERROR! Course number " << target << " was not found." << endl; 
			cout << "Maybe next semester" << endl << endl;
		}

		return courseFound;
}

void CourseManagementMenu(string mainMenuResponse, crossReference courseData[], course c1, course c2, course c3)
{
	if (mainMenuResponse != "E")
	{

		int placeFound = 0;
		while ((placeFound < 2) && (courseData[placeFound].ClassNumber != mainMenuResponse))
		{
			placeFound++;
			//cout << "looking" << endl;
		}



		string level1Response;
		bool repeatQuestion;

		do
		{

			cout << "P - Print course data" << endl;
			cout << "N - Modify course Number" << endl;
			cout << "T - Modify course Title" << endl;
			cout << "C - Modify course Capacity" << endl;
			cout << "I - Increment course Capacity" << endl;
			cout << "S - Student Management" << endl;
			cout << "Enter response here: ";

			cin >> level1Response;
			cin.ignore(IGNORE_AMOUNT, '\n');

			level1Response = convert2UpperCase(level1Response);


			if ((level1Response != "P") && (level1Response != "N") && (level1Response != "T") &&
				(level1Response != "C") && (level1Response != "I") && (level1Response != "S"))
			{
				cout << endl;
				cout << "ERROR! Unrecognized input, please try again." << endl;
				cout << endl;
				repeatQuestion = true;

			}

			else
			{
				repeatQuestion = false;
			}

		}
		// while repeat question equals true
		while (repeatQuestion == true);


		if (level1Response == "P")
		{
			
			if (placeFound == 0)
			{
				cout << c1;
			}
				
			if (placeFound == 1)
			{
				cout << c2;
			}

			if (placeFound == 2)
			{
				cout << c3;
			}

		}

		if (level1Response == "N")
		{
			
			if (placeFound == 0)
			{
				 c1.setCourseNum();
			}

			if (placeFound == 1)
			{
				c1.setCourseNum();
			}

			if (placeFound == 2)
			{
				c1.setCourseNum();
			}

		}

	}
}

int countArrayEntries(string targetArray[])
{

	int count = 0;

	for (int index = 0; targetArray[index] != ""; index++)
		if (targetArray[index].length() == 5)
		{
			
			count++;
			//cout << count << endl; 
		}


	return count; 
}

ostream& operator<< (ostream& outStream, const course& data)
{
	cout << endl; 
	outStream << data.courseNumber << " - " << data.courseTitle << ":" << endl;
	outStream << data.enrolledStudents << " Seats taken, out of " << data.capacity << " total seats." << endl; 
	cout << endl; 
	
		
	// https://www.youtube.com/watch?v=WtoHf6gPnCs
	//outStream << 

	return outStream;
}

int courseNumFormatCheck(string courseNumEntered)
{
	int length;
	int formatErrorCounter = 0;
	string correctlyFormatedCourse; 


		length = courseNumEntered.length();

		if (length < 5)
		{
			cout << endl;
			cout << "ERROR! The course number you entered  " << courseNumEntered << " is too short." << endl;
			cout << "System Expected 5 characters." << endl << endl;
			formatErrorCounter++;

		}

		else if (length > 5)
		{
			cout << endl;
			cout << "ERROR! The course number you entered  " << courseNumEntered << " is too long. " << endl;
			cout << "System Expected 5 characters." << endl << endl;
			formatErrorCounter++;
		}

		else if (length == 5)
		{
			for (int index = 0; index < 2; index++)         // Used Loops for error checking 
			{
				if (!(isalpha(courseNumEntered[index])))
				{
					formatErrorCounter++;
					//cout << "not a X " << endl;
				}
			}

			for (int index = 2; index < 5; index++)         // Used Loops for error checking 
			{
				if (!(isdigit(courseNumEntered[index])))
				{
					formatErrorCounter++;
					//cout << "not a # " << endl;
				}
			}

		}


		if ((length == 5) && (formatErrorCounter > 0))
		{
			{
				cout << endl;
				cout << "Error! You Enterd 5 characters, however not in the correct format." << endl;
				cout << "Please follow the format \"XX###\" Try again." << endl << endl;
			}
		}


	return formatErrorCounter;

}


int courseTitleCheck(string title2Check)
{
	int formatErrorCounter = 0;
	int titleLength;

	titleLength = title2Check.length();
	//cout << "title length = " << titleLength << endl; 


	for (int index = 0; index < titleLength; index++)        
	{

		if (index == 0)
		{
			if (!(isupper(title2Check[index])))
			cout << "first Letter is not capital" << endl;
		}
		
		if ((isdigit(title2Check[index])))
			{
				formatErrorCounter++;
				cout << "digit dedected" << endl;
			}
		


		if ((title2Check[index] == ' ') && (!(isupper(title2Check[index + 1]))))
		{
			formatErrorCounter++;
			cout << "Next leter not capital" << endl;
			
		}

		if ((isupper(title2Check[index])) && (isupper(title2Check[index + 1])))
		{
			formatErrorCounter++;
			cout << "uper case after upper case" << endl;

		}


		if (index == (titleLength - 1))
		{
			if (!(islower(title2Check[index])))
			{
				cout << "Last Letter is not lower" << endl;
				formatErrorCounter++;
			}
		}
	}

	//cout << "format errors found = " << formatErrorCounter << endl; 
	return formatErrorCounter;

}