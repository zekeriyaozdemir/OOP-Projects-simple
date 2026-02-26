#include "uav.h"

UAV::UAV(string name, double maxSpeed)
    : Aircraft(name, maxSpeed) {}

void UAV::engineStart()
{
    cout << "UAV engine is starting..." << endl;
}

void UAV::engineStop()
{
    cout << "UAV engine is stopping..." << endl;
}

void UAV::takeOff()
{
    cout << "UAV vertical take-off..." << endl;
}

void UAV::landing()
{
    cout << "UAV is landing..." << endl;
}