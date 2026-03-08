#include <iostream>
#include "home.h"

using namespace std;

int main()
{
	Home home;
	home.getID();

	int selection;

	int temperature_sensor;
	cout << "Entry temperature value: ";
	cin >> temperature_sensor;
	home.fireAlarm(temperature_sensor);

	double smoke_sensor;
	cout << "Entry smoke threshold value: ";
	cin >> smoke_sensor;
	home.smokeAlarm(smoke_sensor);

	home.motionDetector();

	cout << "************************************************************" << endl;
	cout << "******************** HOME CONTROL PANEL ********************" << endl;
	cout << "************************************************************" << endl;
	cout << " 1 - Lock\n 2 - Lights\n 3 - Sound System\n 4 - Robot Vacuum\n 5 - Garage Door\n\n";
	cout << " Selection: ";
	cin >> selection;

	if (selection == 1)
	{
		string option;
		cout << " Give Option: ";
		cin >> option;
		cout << "State: " << home.lock(option) << endl;
	}

	else if (selection == 2)
	{
		string option;
		cout << " Give Option: ";
		cin >> option;
		cout << "State: " << home.lights(option) << endl;
	}

	else if (selection == 3)
	{
		string option;
		cout << " Give Option: ";
		cin >> option;
		cout << "State: " << home.soundSystem(option) << endl;
	}

	else if (selection == 4)
	{
		string order;
		cout << " Give an order { in/out }: ";
		cin >> order;
		cout << "State: " << home.robot_vacuum(order) << endl;
	}

	else if (selection == 5)
	{
		string option;
		cout << " Give Option: ";
		cin >> option;
		cout << "State: " << home.garage_door(option) << endl;
	}

	else
	{
		cout << "You cannot choose other options ! ";
	}
	return 0;
}