#pragma once


#include "roster.h"
#include "degree.h"
#include <string>
#include <iostream>
#include "student.h"

using namespace std;

class SoftwareStudent : public Student {
public:
	SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int numDays[], int arraySize, Degree degree)
		: Student(studentID, firstName, lastName, email, age, numDays, arraySize, degree) {
		return;
	}
	~SoftwareStudent();
	void print();
	Degree getDegreeProgram();


};