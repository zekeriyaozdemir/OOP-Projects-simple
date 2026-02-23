#include <iostream>
#include "motorParameter.h"

void Motor::start()
{
	cout << "MOTOR STARTING..." << endl;
}

void Motor::stop()
{
	cout << "MOTOR STOPING..." << endl;
}

void Motor::setSpeed(int speed, double threshold)
{
	if (speed <= threshold)
	{
		rpm = speed;
		cout << "Speed : " << rpm << endl;
	}
	else
	{
		cout << "You can NOT exceed the Threshold ! " << endl;
	}
}

void Motor::heatSensor(float heatValue, int size)
{
	float avgValue = heatValue / (float)size;
	cout << endl << "Average heat value is calculating..." << endl;
	cout << "Average Value of Heat: " << avgValue << endl;
	if (avgValue >= 100)
	{
		cout << "Motor has overloading ! " << endl;
	}
}

