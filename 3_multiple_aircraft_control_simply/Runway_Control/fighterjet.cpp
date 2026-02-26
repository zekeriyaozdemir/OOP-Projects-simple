#include "fighterjet.h"

fighterjet::fighterjet(string name, double maxSpeed)
	: Aircraft(name, maxSpeed) { }

void fighterjet::engineStart()
{
	cout << "Fighter Jet engines at full afterburner!" << endl;
}

void fighterjet::engineStop()
{
	cout << "Fighter Jet engine is stop..." << endl;
}

void fighterjet::takeOff()
{
	cout << "Fighter Jet rapid take-off!" << endl;
}

void fighterjet::landing()
{
	cout << "Fighter Jet is landing..." << endl;
}