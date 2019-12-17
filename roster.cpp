
#include "pch.h"
#include "student.h"
#include "softwareStudent.h"
#include "degree.h"
#include "roster.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;

Roster::Roster() {
	return;
}

Roster::~Roster() {
	delete classRosterArray;
	return;
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int numDays[], int arraySize, Degree degree) {
	
	if (degree == SOFTWARE) {
		classRosterArray[numStudents] = new SoftwareStudent(studentID, firstName, lastName, email, age, numDays, arraySize, degree);
		
		++numStudents;
	}
	else if (degree == NETWORKING) {
		classRosterArray[numStudents] = new NetworkStudent(studentID, firstName, lastName, email, age, numDays, arraySize, degree);
		++numStudents;
	}
	else if (degree == SECURITY) {
		classRosterArray[numStudents] = new SecurityStudent(studentID, firstName, lastName, email, age, numDays, arraySize, degree);
		
		++numStudents;
	}
	return;
}

void Roster::printAll() {
	for (int i = 0; i < numStudents; ++i) {
		classRosterArray[i]->print();
	}
	return;
}

void Roster::printDaysInCourse(string StudentID) {
	for (int i = 0; i < numStudents; ++i) {
		string checkVal = classRosterArray[i]->getStudentID();
		if (checkVal == StudentID) {
			int totalDays = 0;
			int avg = 0;
			for (int j = 0; j < 3; ++j) {
				totalDays +=classRosterArray[i]->getNumDays()[j];
			}
			avg = totalDays / 3;
			cout << "Average Days in course: " << avg << endl;
		}
		else {};
	
	}
	return;
	
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < numStudents; ++i) {
		string checkVal = classRosterArray[i]->getEmail();
		bool spaceFlag = false;
		bool atFlag = false;
		bool dotFlag = false;
		char spaceToken = checkVal.find(' ');
		char atToken = checkVal.find('@');
		char dotToken = checkVal.find('.');

		if (spaceToken != string::npos || atFlag == string::npos || dotToken == string::npos) {
			cout << "Invalid Email: " << checkVal << endl;
		}
		else {};
	}
}

int Roster::getNumStudents() {
	return numStudents;
}

void Roster::printByDegree(int degree) {
	for (int i = 0; i < numStudents; ++i) {
		if (static_cast<int>(classRosterArray[i]->getDegreeProgram()) == degree) {
			classRosterArray[i]->print();
		}
		else {};
	}
}

void Roster::remove(string studentID) {
	bool checkFlag = false;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			for (int j = i; j < (numStudents - 1); ++j) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			checkFlag = true;
			numStudents -= 1;
			cout << "Student " << studentID << " Deleted." << endl;
		}
	}

	if (checkFlag == false) {
		cout << "No Student found." << endl;
	}

}



int main()
{

	Roster classRoster;
	const int arraySize = 3;
	const string studentData[5] =
	{ 
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Adam,Petersen,apet219@wgu.edu,26,22,30,35,SOFTWARE" 
	};
	

	cout << "C867 Class Roster Program in C++\nAdam Petersen" << endl << endl << endl << "Unformatted Data:" << endl;



	// parse the string into a vector to hold the object constructors input
	string delimiter = ",";
	for (int i = 0; i < 5; ++i) {
		vector<string> inputVctr;
		cout << studentData[i] << endl;
		string parseMe = studentData[i];
		string parsedToken = "";
		int position = 0;
		while (parseMe.length() > 0) {
			int position = parseMe.find(delimiter);
			parsedToken = parseMe.substr(0, position);
			inputVctr.push_back(parsedToken);
			if (position != string::npos) {
				parseMe.erase(0, (position + 1));
			}
			else {
				parseMe.erase(0, parseMe.length());
			}
		}


		// Define the input variables out of the vector 
		int inputAge = stoi(inputVctr.at(4));
		int inputNumDays[3];
		string inputStudentID = inputVctr.at(0);
		string inputFirstName = inputVctr.at(1);
		string inputLastName = inputVctr.at(2);
		string inputEmail = inputVctr.at(3);
		for (int i = 0; i < 3; ++i) {
			int tempInt = stoi(inputVctr.at(i + 5));
			inputNumDays[i] = tempInt;
		}
		string evalDegree = inputVctr.at(8);


		// evaluate the string to determine the Degree type
		Degree inputDegree;
		if (evalDegree == "SOFTWARE") {
			inputDegree = SOFTWARE;
		}
		else if (evalDegree == "NETWORK") {
			inputDegree = NETWORKING;
		}
		else if (evalDegree == "SECURITY") {
			inputDegree = SECURITY;
		}

		classRoster.add(inputStudentID, inputFirstName, inputLastName, inputEmail, inputAge, inputNumDays, arraySize, inputDegree);

	}


	classRoster.printAll();
	classRoster.printInvalidEmails();

	for (int i = 0; i < classRoster.getNumStudents(); ++i) {
		string studentID = classRoster.classRosterArray[i]->getStudentID();
		cout << "StudentID: " << studentID << "   ";
		classRoster.printDaysInCourse(studentID);

	}
	cout <<  "\nPrinting all students with degree of SOFTWARE: " << endl;
	classRoster.printByDegree(static_cast<int>(SOFTWARE));

	classRoster.remove("A3");
	classRoster.remove("A3");

	return 0; // classRoster gets deleted as it goes out of scope of main
	
}

