#pragma once
#include <iostream>

using namespace std;

class Aircraft {

protected:
	string name;
	double maxSpeed;


public:

	Aircraft(string name, double maxSpeed);

	virtual void engineStart();
	virtual void engineStop();
	virtual void takeOff();
	virtual void landing();

	void getInfo();

};