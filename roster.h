#pragma once

#include <iostream>
#include "degree.h"
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include <string>

using namespace std;

class Roster {
public:
	void add(string studentID, string firstName, string lastName, string email, int age, int numDays[], int arraySize, Degree degree);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegree(int degree);
	int getNumStudents();
	Roster();
	~Roster();

	Student *classRosterArray[5];
private:
	int numStudents = 0;
};