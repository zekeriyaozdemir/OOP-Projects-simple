#pragma once
#include <iostream>

using namespace std;

class Aircraft {

public:

	void getName(string name, double maxSpeed);
	void engineStart();
	void engineStop();
	void pushSpeed();
	void takeOff();
	void landing();

private:
	string name;
	double maxSpeed;
};