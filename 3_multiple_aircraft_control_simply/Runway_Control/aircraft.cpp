#include <iostream>
#include "aircraft.h"

using namespace std;

void Aircraft::getName(string name, double maxSpeed)
{
	cout << "the aircraft name is " << name << endl << "Max Speed: " << maxSpeed << endl;
}

void Aircraft::engineStart()
{
	cout << "Engine Starting..." << endl;
}

void Aircraft::engineStop()
{
	cout << "Engine Stopping..." << endl;
}

void Aircraft::pushSpeed()
{
	cout << "Engine Speed..." << endl;
}

void Aircraft::takeOff()
{
	cout << "Aircraft take-off..." << endl;

}

void Aircraft::landing()
{
	cout << "Aircraft landing..." << endl;

}