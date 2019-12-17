
#include "pch.h"

#include <string>
#include <iostream>
#include "student.h"
#include "networkStudent.h"
#include "roster.h"
#include "degree.h"

using namespace std;

NetworkStudent::~NetworkStudent() {
	return;
}

void NetworkStudent::print() {
	cout << "StudentID: " << getStudentID() << endl;
	cout << "First Name: " << getFirstName() << endl;
	cout << "Last Name: " << getLastName() << endl;
	cout << "Email: " << getEmail() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Days in course: ";
	for (int i = 0; i < 3; ++i) {
		cout << getNumDays()[i] << " ";
	}
	cout << endl;
	string tempDegree;
	if (getDegreeProgram() == SECURITY) {
		tempDegree = "SECURITY";
	}
	else if (getDegreeProgram() == SOFTWARE) {
		tempDegree = "SOFTWARE";
	}
	else if (getDegreeProgram() == NETWORKING) {
		tempDegree = "NETWORKING";
	}
	cout << "Degree: " << tempDegree << endl << "=============================================================" << endl;
	return;
}

Degree NetworkStudent::getDegreeProgram() {
	return degree;
}
