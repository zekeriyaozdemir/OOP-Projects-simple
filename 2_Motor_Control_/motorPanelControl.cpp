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