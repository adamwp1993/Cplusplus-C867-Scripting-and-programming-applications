#pragma once
#include <iostream>
//#include "roster.h"
#include "degree.h"
#include <string>


using namespace std;


class Student {
public:
	Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], int arraySize, Degree degree);
	Student();
	~Student();

	// Getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int *getNumDays();

	// Setters 
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumDays(int numDays[], int arraySize);

	//Virtual functions
	virtual void print() {
		return;
	};
	virtual Degree getDegreeProgram() {
		return degree;
	};

	
protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numDays[3];
	Degree degree;

	
	
};