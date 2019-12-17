#include "pch.h"
#include "student.h"
#include "degree.h"
#include <string>

using namespace std;

// Constructor 
Student::Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], int arraySize, Degree degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; ++i) {
		this->numDays[i] = numDays[i];
	}
	this->degree = degree;
}

Student::Student() {
	return;
}

//Destructor 
Student::~Student() {
	return;
}

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmail() {
	return email;
}

int Student::getAge() {
	return age;
}

int *Student::getNumDays() {
	return numDays;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setNumDays(int numDays[], int arraySize) {
	for (int i = 0; i < arraySize; ++i) {
		this->numDays[i] = numDays[i];
	}
}