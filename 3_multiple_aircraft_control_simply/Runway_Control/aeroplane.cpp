#include "aeroplane.h"

Aeroplane::Aeroplane(string name, double maxSpeed)
	: Aircraft(name, maxSpeed) { }

void Aeroplane::engineStart()
{
    cout << "Aeroplane engine is starting..." << endl;
}

void Aeroplane::engineStop()
{
    cout << "Aeroplane engine is stopping..." << endl;
}

void Aeroplane::takeOff()
{
    cout << "Aeroplane vertical take-off..." << endl;
}

void Aeroplane::landing()
{
    cout << "Aeroplane is landing..." << endl;
}