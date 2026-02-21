#pragma once

#include <iostream>

using namespace std;

class Student
{
public:

	string Name;
	int ID;
	string department;
	int entryYear;

	void getInfo(Student arr[], int size);
};
