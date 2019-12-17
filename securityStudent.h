#pragma once

#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

class SecurityStudent : public Student {
public:
	SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int numDays[], int arraySize, Degree degree)
		: Student(studentID, firstName, lastName, email, age, numDays, arraySize, degree) {
		return;
	}
	~SecurityStudent();
	void print();
	Degree getDegreeProgram();


};
