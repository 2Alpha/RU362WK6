//***************************************************************************
//  FILENAME:	 AllenAssn5.cpp
//  DESCRIPTION: Course Managemmt Program
//
//  DATE:        10/1/15
//  CLASS/TERM:  CS362_X40_Data Structures - CU_CS362 - XIN_X40_15F8W1
//  DESIGNER:	 Andrae Allen
//  FUNCTIONS:	 main - reads values, performs calculations, & displays results
//				 course::course - constructor 
//				 course::operator++ - increments course capacity by 1 
//				 course::setCourseNum - Sets course number
//				 course::setCourseTitle - Sets Course Title
//				 course::initilizeCourseNum - Initiaize course Number on first run
//				 course::initializeCourseTitle - Initialize course title on first run
//				 course::LsetCapacity - sets capacity for course
//				 course::studentManagement - student Management Menu 
//				 course::getCourseNum - gets course number
//				 course::getCourseTitle - gets course title
//				 course::getCapacity - gets course capacity
//				 course::getNumEnrolled - gets number of enrolled students 
//				 course::printCourse - prints course informatiomn 
//				 course::printCourseNumber -prints course number 
//				 course::printCourseTitle - prints course title 
//				 course::printStudentIDs - prints student ID's
//				 course::addOneStudent - adds student to course 
//				 course::dropOneStudent - removes student from course 
//				 course::incrementCourseCap increase course capacity by 1 
//				 friend ostream& operator<< - overloaded output operator
//				 convert2UpperCase - converts string to uppercase
//				 course2Manage - shows course to manage menu
//				 countArrayEntries - counts array entries 
//				 Search4Course - searches for course
//				 CourseManagementMenu - shows course management menu 
//				 courseNumFormatCheck - checks course number format
//				 courseTitleCheck - checks course title format
//				 errorCheckStuID - error check student id
//               isolateObject  - identifies oject course resides in
//***************************************************************************

#include <iostream> 
#include <fstream>
#include <cstdio> 
#include <iomanip>
#include <string>
#include <cstddef>

using namespace std;

const int MIN_CAPACITY = 1;				// Minimum course capacity
const int MAX_CAPACITY = 30;			// Max course capacity
const int DEFAULT_CAPACITY = 30;		// Default capacity
const int IGNORE_AMOUNT = 1000;			// Ignore amount
const int STUDENT_ID_LENTH = 5;			// student ID Length 
const int COURSE_CHAR_LENGTH = 5;		// Character length for course
const int END_OF_ALPHA_POSITION = 2;	// End of alpha position for course numbers


class course
{
private:
		string courseNumber;					// course number 
		string courseTitle;						// course title 
		int capacity;							// course capacity
		int enrolledStudents;					// enrolled students 
		string StudentIDList[MAX_CAPACITY];		// array of student IDs 
		
public:
	course();
	course(string cNumber, string cTitle, int cCap);
	course operator++();

		void setCourseNum(string managementMenuChoice);
		void setCourseTitle(string managementMenuChoice);
		void initilizeCourseNum();
		void initializeCourseTitle();
		void setCapacity(string managementMenuChoice);
		void studentManagement(string managementMenuChoice);

		string getCourseNum();
		void getCourseTitle();
		void getCapacity();
		int getNumEnrolled();

		void course::printCourse(string managementMenuChoice, course indentifiedObject);
		void printCourseNumber();
		void printCourseTitle();
		void printStudentIDs(string MenuChoice); 

		void addOneStudent(string MenuChoice);
		void dropOneStudent(string MenuChoice);
		void incrementCourseCap();
		
		
		friend ostream& operator<< (ostream& outStream, const course& data);

};


string convert2UpperCase(string stringInput);
string course2Manage(course c1, course c2, course c3);

int countArrayEntries(string targetArray[]);
bool Search4Course(string target, course c1, course c2, course c3);

void CourseManagementMenu(string validCourseNum, course& c1, course& c2, course& c3);

int  courseNumFormatCheck(string courseNumEntered); 
int courseTitleCheck(string title2Check);
int errorCheckStuID(string incomingID);

course * isolateObject(string validCourse, course& c1, course& c2, course& c3);

//**************************************************************************
//  FUNCTION:       main
//  DESCRIPTION:    Creates three course class objects and manipulates them.
//  OUTPUT:	
//  Return Value:	0 for success
//  CALLS TO:	    course2Manage, CourseManagementMenu, 
//**************************************************************************
int main()
{
	
	string validCourseNum;												// valid course number

	course course1("CS361", "Control Structures", DEFAULT_CAPACITY);

	course course2("CS362", "Data Structures", 10);
	
	course course3;
	course3.initilizeCourseNum();
	course3.initializeCourseTitle();

	do
	{
		validCourseNum = course2Manage(course1, course2, course3);

		CourseManagementMenu(validCourseNum, course1, course2, course3);


	} while (validCourseNum != "E");


	system("PAUSE");
	return 0;

}


//**************************************************************************
//  FUNCTION:       course::course
//  DESCRIPTION:    Constructor without parameters
//  OUTPUT:	
//  Return Value:	none
//  CALLS TO:	    none, 
//**************************************************************************
course::course()
{
	courseNumber = "";
	courseTitle = "";
	capacity = MIN_CAPACITY;
	enrolledStudents = 0;

	
}

//**************************************************************************
//  FUNCTION:       course::course
//  DESCRIPTION:    Constructor with parameters
//  OUTPUT:	
//  Return Value:	none
//  CALLS TO:	    none 
//**************************************************************************
course::course(string cNumber, string cTitle, int cCap)
{
	courseNumber = cNumber;

	courseTitle = cTitle;

	enrolledStudents = 0;

	capacity = cCap; 

}

//**************************************************************************
//  FUNCTION:       course::initilizeCourseNum
//  DESCRIPTION:    Initiaize course Number on first run
//  INPUT			Parameters- none
//  OUTPUT:			none
//**************************************************************************
void course::initilizeCourseNum()
{
	string desiredCourseNum;

	do 
		{
			cout << "Initialze object named course3 with a course number: ";
			cin >> desiredCourseNum;
			desiredCourseNum = convert2UpperCase(desiredCourseNum);
		} 
	
	while (courseNumFormatCheck(desiredCourseNum) > 0);

	courseNumber = desiredCourseNum;

}

//**************************************************************************
//  FUNCTION:       course::initilizeCourseTitle
//  DESCRIPTION:    Initiaize course Title on first run
//  INPUT			Parameters- none
//  OUTPUT:			none
//**************************************************************************
void course::initializeCourseTitle()
{
	string desiredCourseTitle;

	do
	{
		cout << "Initialze object named course3 with course a Title: ";
		cin.clear();
		getline(cin >> ws, desiredCourseTitle);

	} while (courseTitleCheck(desiredCourseTitle) > 0);

	courseTitle = desiredCourseTitle;


}


//**************************************************************************
//  FUNCTION:       course::getCourseNum
//  DESCRIPTION:    gets course number
//  INPUT			Parameters- none
//  OUTPUT:			courseNumber
//**************************************************************************
string course::getCourseNum()

{
	return courseNumber;

}

//**************************************************************************
//  FUNCTION:       course::printCourse
//  DESCRIPTION:    prints out object info
//  INPUT			Parameters - managementMenuChoice, indentifiedObject
//  OUTPUT:			none
//**************************************************************************
void course::printCourse(string managementMenuChoice, course indentifiedObject)
{
	if (managementMenuChoice == "P")
	{
		cout << indentifiedObject; 

	}

}

//**************************************************************************
//  FUNCTION:       course::printCourseNumber
//  DESCRIPTION:    prints course number
//  INPUT			none
//  OUTPUT:			none
//**************************************************************************
void course::printCourseNumber()
{
	cout << courseNumber; 
	
}

//**************************************************************************
//  FUNCTION:       course::printCourseTitle
//  DESCRIPTION:    prints course title
//  INPUT			none
//  OUTPUT:			none
//**************************************************************************
void course::printCourseTitle()
{
	cout << courseTitle;

}

//**************************************************************************
//  FUNCTION:       course::setCourseNum
//  DESCRIPTION:    prints course title
//  INPUT			Parameters - managementMenuChoice
//  OUTPUT:			none
//**************************************************************************
void course::setCourseNum (string managementMenuChoice)
{

	if (managementMenuChoice == "N")
	{	
		string desiredCourseNum;

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
		cout << "You modfied course " << courseNumber << " to course # " << desiredCourseNum << endl;

		courseNumber = desiredCourseNum;
	}
}

//**************************************************************************
//  FUNCTION:       course::setCourseTitle
//  DESCRIPTION:    sets course title
//  INPUT			Parameters - managementMenuChoice
//  OUTPUT:			none
//**************************************************************************
void course::setCourseTitle(string managementMenuChoice)
{
	string desiredCourseTitle; 

	if (managementMenuChoice == "T")
	{
		do
		{
			cout << endl;
			cout << "Enter the desired Course Title : " << endl;
			cin.clear();
			getline(cin>>ws, desiredCourseTitle);

		} while (courseTitleCheck(desiredCourseTitle) > 0);


		cout << endl;
		cout << "Success!" << endl;
		cout << "New course Title is " <<  desiredCourseTitle << endl;

		courseTitle = desiredCourseTitle;


	}


}

//**************************************************************************
//  FUNCTION:       course::setCapacity
//  DESCRIPTION:    sets course capacity
//  INPUT			Parameters - managementMenuChoice
//  OUTPUT:			none
//**************************************************************************
void course::setCapacity(string managementMenuChoice)
{
	if (managementMenuChoice == "C")
	{
		int errorCounter;
		int desiredCapacity;
		int currentlyEnrolled = getNumEnrolled();

		do
		{
			errorCounter = 0;
			cout << endl; 
			cout << "The current course capacity is " << capacity << endl;
			cout << "The current number of enrolled students is " << currentlyEnrolled << endl;
			cout << "Enter the desired course capcity: ";
			cin >> desiredCapacity;
	
			
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(IGNORE_AMOUNT, '\n');
				cout << "ERROR!" << endl; 
				cout << "Only values of type integer are welcome to this party" << endl;
				cout << "Please Try Agin." << endl; 
				errorCounter++;
			}

			else if ((cin.fail()) || (desiredCapacity < currentlyEnrolled))
			{
				cin.clear();
				cin.ignore(IGNORE_AMOUNT, '\n');
				errorCounter++;
				cout << "Error! cannot change capacity to " << desiredCapacity << " unless " << currentlyEnrolled - desiredCapacity << endl;
				cout << "are dropped, because " << currentlyEnrolled << " students are alreday registered" << endl;
				cout << " Try Again." << endl; 

			}

			else if ((cin.fail()) || (desiredCapacity < MIN_CAPACITY) || (desiredCapacity > MAX_CAPACITY))
			{
				cin.clear();
				cin.ignore(IGNORE_AMOUNT, '\n');
				errorCounter++;
				cout << "Error! cannot change capacity to " << desiredCapacity << endl;
				cout << "Try Again." << endl;

			}

		} while (errorCounter > 0);

		cout << "Success! Course capacity is now " << desiredCapacity; 
		capacity = desiredCapacity;
	}

}

//**************************************************************************
//  FUNCTION:       course::studentManagement
//  DESCRIPTION:    shows student Management Menu
//  INPUT			Parameters - managementMenuChoice
//  OUTPUT:			none
//**************************************************************************
void course::studentManagement(string managementMenuChoice)
{
	if (managementMenuChoice == "S")
	{
		string menuChoice;
		int errorCounter = 0;

		do
		{
			cout << endl;
			cout << "Student Management Menu" << endl;
			cout << "P - Print Student IDs" << endl;
			cout << "A - Add One Student" << endl;
			cout << "D - Drop One Student" << endl;
			cout << "B - Back to course Management Menu" << endl;
			cout << "Enter choice here : ";

			cin >> menuChoice;
			menuChoice = convert2UpperCase(menuChoice);

			if ((menuChoice != "P") && (menuChoice != "A") && (menuChoice != "D") &&
				(menuChoice != "B"))
			{
				cout << endl;
				cout << "ERROR! Unrecognized input, please try again." << endl;
				cout << endl;
				errorCounter++;
			}

		} while (errorCounter > 0);

		printStudentIDs(menuChoice); 
		addOneStudent(menuChoice);
		dropOneStudent(menuChoice);


	}
}

//**************************************************************************
//  FUNCTION:       course::getNumEnrolled
//  DESCRIPTION:    gets number of enrolled students 
//  INPUT			Parameters - none
//  OUTPUT:			enrolledStudents
//**************************************************************************
int course::getNumEnrolled()
{
	return enrolledStudents;
}

//**************************************************************************
//  FUNCTION:       course::operator++
//  DESCRIPTION:    increments course capacity by 1
//  INPUT			Parameters - none
//  OUTPUT:			itself
//**************************************************************************
course course::operator++()
{
	

		if (capacity < MAX_CAPACITY)
		{
			capacity++;
			cout << "Capacity is now " << capacity << endl;
		}

		else
		{
			cout << "Course is already set to Max capacity" << endl;
		}

		return *this;
	
}

//**************************************************************************
//  FUNCTION:       course::printStudentIDs
//  DESCRIPTION:    prints student ID's
//  INPUT			Parameters - MenuChoice
//  OUTPUT:			none
//**************************************************************************
void course::printStudentIDs(string MenuChoice)
{
	
	if (MenuChoice == "P")
	{
		int numOfStudentIds = enrolledStudents;

		if (numOfStudentIds == 0)
		{
			cout << endl;
			cout << "The course does not have any student enrolled." << endl;
			cout << "Therefore there are no student Id's to display" << endl;
		}

		else
		{
			cout << endl;
			cout << numOfStudentIds << " Student(s) enrolled in " << courseNumber << endl;
			for (int index = 0; index < numOfStudentIds; index++)
			{
				cout << StudentIDList[index] << endl;
			}
		}
	}
}

//**************************************************************************
//  FUNCTION:       course::addOneStudent
//  DESCRIPTION:    adds one student to course
//  INPUT			Parameters - MenuChoice
//  OUTPUT:			none
//**************************************************************************
void course::addOneStudent(string MenuChoice)
{

	if (MenuChoice == "A")
	{
		string newStudentId;

		if (enrolledStudents < capacity)
		{
			do
			{

				cout << endl; 
				cout << "Student ID's must be 5 digits, no leading Zero's" << endl;
				cout << "Enter student ID: ";
				cin >> newStudentId;

			} while (errorCheckStuID(newStudentId) > 0); 



			StudentIDList[enrolledStudents] = newStudentId;
			enrolledStudents++;

			cout << endl; 
			cout << "Added student id " << newStudentId;
			cout << endl; 
		}
		
		else
		{
			cout << endl; 
			cout << "ERROR! Course is full.  Cannot add any more students." << endl; 
		}



	}

}

//**************************************************************************
//  FUNCTION:       course::dropOneStudent(
//  DESCRIPTION:    removes one student from course
//  INPUT			Parameters - MenuChoice
//  OUTPUT:			none
//**************************************************************************
void course::dropOneStudent(string MenuChoice)
{
	if (MenuChoice == "D")
	{
		if (enrolledStudents > 0)
		{
			string target;

			int numOfStudentIds = enrolledStudents;
			cout << "Choose student ID to delete from "<< courseNumber << endl;
			for (int index = 0; index < numOfStudentIds; index++)
			{
				cout << StudentIDList[index] << endl;
			}

			do
			{
				cout << "Enter student ID to delete here : ";
				cin >> target;

			} while (errorCheckStuID(target) > 0);

			int placeFound = 0;

			while ((placeFound < (enrolledStudents) && (StudentIDList[placeFound] != target)))
				placeFound++;                        // increment index


			//If itemToDel was Found, delete it
			if (placeFound < enrolledStudents) 
			{

				// Move all values below itemToDel UP one cell
				for (int num = placeFound + 1; num < enrolledStudents; num++)
				{
					StudentIDList[num - 1] = StudentIDList[num];
				}


				// Decrement list size
				enrolledStudents--;

				cout << endl << "Success!" << endl;
				cout << "Rental entry with phone # \"" << target << "\" has been deleted.";
				cout << endl;

			}  // end if

			else
			{
				cout << endl << "ERROR!" << endl;
				cout << "Student ID " << target << " cound not be found." << endl;
				cout << "Try Agian." << endl; 
			}

		}


		else
		{
			cout << "Cannot drop a student -- no students are enrolled." << endl; 
		}

	}
}

//**************************************************************************
//  FUNCTION:       course2Manage
//  DESCRIPTION:    displays course options
//  INPUT			Parameters - c1, c2, c3
//  OUTPUT:			courseNumEntered
//**************************************************************************
string course2Manage(course c1, course c2, course c3)
{

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


		} while (courseNumFormatCheck(courseNumEntered) > 0) ;


		courseExist = Search4Course(courseNumEntered, c1, c2, c3);

	} while (courseExist != true);
	
	
	
	return courseNumEntered;


}

//**************************************************************************
//  FUNCTION:       convert2UpperCase
//  DESCRIPTION:    converts  string to upper case
//  INPUT			Parameters - c1, c2, c3
//  OUTPUT:			upperCasedString
//**************************************************************************
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

//**************************************************************************
//  FUNCTION:       Search4Course
//  DESCRIPTION:    searches for course withiin ojects
//  INPUT			Parameters - c1, c2, c3
//  OUTPUT:			bool courseFound 
//**************************************************************************
bool Search4Course (string target, course c1, course c2, course c3)
{
	bool courseFound = false; 
	
	if (target == "E")
	{
		courseFound = true;
	}

	else if (target == c1.getCourseNum())
	{
		courseFound = true; 
	}

	else if (target == c2.getCourseNum())
	{
		courseFound = true;
	}

	else if (target == c3.getCourseNum())
	{
		courseFound = true;
	}

	if (courseFound == false)
	{
		cout << endl; 
		cout << "ERROR! Course " << target << " could not be found." << endl; 
		cout << "On the brightside, theres always next semester. Try Again." << endl; 
	}

	return courseFound;

}

//**************************************************************************
//  FUNCTION:       CourseManagementMenu
//  DESCRIPTION:    Display course Managment Menu
//  INPUT			Parameters - validCourseNumm, c1, c2, c3
//  OUTPUT:			none 
//**************************************************************************
void CourseManagementMenu(string validCourseNum, course& c1, course& c2, course& c3)
{
	if (validCourseNum != "E")
	{
		
		string level1Response;
		bool repeatQuestion;

		do
		{

			cout << endl; 
			cout << "P - Print course data" << endl;
			cout << "N - Modify course Number" << endl;
			cout << "T - Modify course Title" << endl;
			cout << "C - Modify course Capacity" << endl;
			cout << "I - Increment course Capacity" << endl;
			cout << "S - Student Management" << endl;
			cout << "B - Back to Choose Course menu" << endl;
			cout << "Enter response here: ";

			cin >> level1Response;
			cin.ignore(IGNORE_AMOUNT, '\n');

			level1Response = convert2UpperCase(level1Response);


			if ((level1Response != "P") && (level1Response != "N") && (level1Response != "T") &&
				(level1Response != "C") && (level1Response != "I") && (level1Response != "S") && 
				(level1Response != "B"))
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


		isolateObject(validCourseNum, c1, c2, c3)->setCourseNum(level1Response);
		isolateObject(validCourseNum, c1, c2, c3)->setCourseTitle(level1Response);
		isolateObject(validCourseNum, c1, c2, c3)->setCapacity(level1Response);
		isolateObject(validCourseNum, c1, c2, c3)->studentManagement(level1Response);
		
		if (level1Response == "P")
		{
			cout << *isolateObject(validCourseNum, c1, c2, c3);
		}


		if (level1Response == "I")
		{
			isolateObject(validCourseNum, c1, c2, c3)->operator++();
		}



	}

	
}

//**************************************************************************
//  FUNCTION:       countArrayEntries
//  DESCRIPTION:    count array entries
//  INPUT			Parameters - taragetArray 
//  OUTPUT:			count - num of array entries 
//**************************************************************************
int countArrayEntries(string targetArray[])
{

	int count = 0;

	for (int index = 0; targetArray[index] != ""; index++)
		if (targetArray[index].length() == STUDENT_ID_LENTH)
		{
			
			count++;
			//cout << count << endl; 
		}


	return count; 
}

//**************************************************************************
//  FUNCTION:       operator<<
//  DESCRIPTION:    overloaded output operator
//  INPUT			Parameters - outstream, data
//  OUTPUT:			outStream
//**************************************************************************
ostream& operator<< (ostream& outStream, const course& data)
{
	cout << endl; 
	outStream << data.courseNumber << " - " << data.courseTitle << ":" << endl;
	outStream << data.enrolledStudents << " Seats taken, out of " << data.capacity << " total seats." << endl; 
	cout << endl; 
	
	return outStream;
}

//**************************************************************************
//  FUNCTION:       courseNumFormatCheck
//  DESCRIPTION:    checks course number format
//  INPUT			Parameters - courseNumEntered
//  OUTPUT:			formatErrorCounter - number of errors detected
//**************************************************************************
int  courseNumFormatCheck(string courseNumEntered)
{
	int length;
	int formatErrorCounter = 0;
	string correctlyFormatedCourse; 
	bool loopQuestion = true; 


		length = courseNumEntered.length();

		if (courseNumEntered == "E")
		{
			formatErrorCounter = 0;
		}

		else if (length < COURSE_CHAR_LENGTH)
		{
			cout << endl;
			cout << "ERROR! The course number you entered  " << courseNumEntered << " is too short." << endl;
			cout << "System Expected 5 characters." << endl << endl;
			formatErrorCounter++;

		}

		else if (length > COURSE_CHAR_LENGTH)
		{
			cout << endl;
			cout << "ERROR! The course number you entered  " << courseNumEntered << " is too long. " << endl;
			cout << "System Expected 5 characters." << endl << endl;
			formatErrorCounter++;
		}

		else if (length == COURSE_CHAR_LENGTH)
		{
			for (int index = 0; index < END_OF_ALPHA_POSITION; index++)         // Used Loops for error checking 
			{
				if (!(isalpha(courseNumEntered[index])))
				{
					formatErrorCounter++;
					//cout << "not a X " << endl;
				}
			}

			for (int index = 2; index < COURSE_CHAR_LENGTH; index++)         // Used Loops for error checking 
			{
				if (!(isdigit(courseNumEntered[index])))
				{
					formatErrorCounter++;
					//cout << "not a # " << endl;
				}
			}

		}


		if ((length == COURSE_CHAR_LENGTH) && (formatErrorCounter > 0))
		{
			{
				cout << endl;
				cout << "Error! You Enterd 5 characters, however not in the correct format." << endl;
				cout << "Please follow the format \"XX###\" Try again." << endl << endl;
			}
		}



		return formatErrorCounter;

}

//**************************************************************************
//  FUNCTION:       courseTitleCheck
//  DESCRIPTION:    checks course Title Format
//  INPUT			Parameters - title2Check 
//  OUTPUT:			formatErrorCounter - number of errors detected
//**************************************************************************
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
			cout << "upper case after upper case" << endl;

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

//**************************************************************************
//  FUNCTION:       isolateObject
//  DESCRIPTION:    identifies oject course resides in
//  INPUT			Parameters -  validCourse, c1, c2, c3
//  OUTPUT:			course 
//**************************************************************************
course * isolateObject(string validCourse, course& c1, course& c2, course& c3)
{
	
	course *tempClass = NULL;

	if (validCourse == c1.getCourseNum())
	{
		
		return &c1;
	}

	else if (validCourse == c2.getCourseNum())
	{
		return &c2;
	}

	else if (validCourse == c3.getCourseNum())
	{
		return &c3;
	}

	else 
		
	return tempClass;

}

//**************************************************************************
//  FUNCTION:       errorCheckStuID
//  DESCRIPTION:    error checks student ID
//  INPUT			Parameters - incomingID - ID to examine
//  OUTPUT:			formatErrorCounter - number of errors detected
//**************************************************************************
int errorCheckStuID(string incomingID)
{
	int length; 
	int formatErrorCounter = 0;

	length = incomingID.length();

	if (length < STUDENT_ID_LENTH)
	{
		cout << endl;
		cout << "ERROR! The Student ID you entered  " << incomingID << " is too short." << endl;
		cout << "System Expected 5 characters." << endl << endl;
		formatErrorCounter++;
	}

	else if (length > STUDENT_ID_LENTH)
	{
		cout << endl;
		cout << "ERROR! The Student ID you entered  " << incomingID << " is too long. " << endl;
		cout << "System Expected 5 characters." << endl << endl;
		formatErrorCounter++;
	}

	else if (length == STUDENT_ID_LENTH)
	{
		for (int index = 0; index < STUDENT_ID_LENTH; index++)         // Used Loops for error checking 
		{
			if (!(isdigit(incomingID[index])))
			{
				formatErrorCounter++;
				//cout << "studID not a # " << endl;
			}

			if ((index == 0) && (incomingID[index] == '0'))
			{
				formatErrorCounter++;
				//cout << "Leading Zero found" << endl;
			}

		}

	}

	//cout << "errors found " << formatErrorCounter << endl; 
	return formatErrorCounter; 

}