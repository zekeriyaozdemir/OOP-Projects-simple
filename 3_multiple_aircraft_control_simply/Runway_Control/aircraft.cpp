#include <iostream>
#include "aircraft.h"

using namespace std;

Aircraft::Aircraft(string name, double maxSpeed)
{
	this->name = name;
	this->maxSpeed = maxSpeed;
}

void Aircraft::engineStart()
{
	cout << "Engine Starting..." << endl;
}

void Aircraft::engineStop()
{
	cout << "Engine Stopping..." << endl;
}


void Aircraft::takeOff()
{
	cout << "Aircraft take-off..." << endl;

}

void Aircraft::landing()
{
	cout << "Aircraft landing..." << endl;

}

void Aircraft::getInfo()
{
	cout << "Name: " << name << endl;
	cout << "Max Speed: " << maxSpeed << endl;
}