#include <iostream>
#include "home.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

Home::Home() {}

string Home::lock(string selection)
{
	string state;
	if (selection == "OPEN" || selection == "open" || selection == "Open")
	{
		cout << "\nThe doors are opening...\n";
		this_thread::sleep_for(seconds(1));
		state = "ON";
	}
	else if (selection == "CLOSE" || selection == "close" || selection == "Close")
	{
		cout << "\nThe doors are closing...\n";
		this_thread::sleep_for(seconds(1));
		state = "OFF";
	}
	else
	{
		cout << "\nPlease choose available option ! \n";
	}
	return state;
}

string Home::lights(string selection)
{
	string state;
	if (selection == "OPEN" || selection == "open" || selection == "Open")
	{
		cout << "\nThe lights are opening...\n";
		this_thread::sleep_for(seconds(1));
		state = "ON";
	}
	else if (selection == "CLOSE" || selection == "close" || selection == "Close")
	{
		cout << "\nThe lights are closing...\n";
		this_thread::sleep_for(seconds(1));
		state = "OFF";
	}
	else
	{
		cout << "\nPlease choose available option ! \n";
	}
	return state;
}

string Home::soundSystem(string selection)
{
	string state;
	if (selection == "OPEN" || selection == "open" || selection == "Open")
	{
		cout << "\nThe sound system is opening...\n";
		this_thread::sleep_for(seconds(1));
		state = "ON";
	}
	else if (selection == "CLOSE" || selection == "close" || selection == "Close")
	{
		cout << "\nThe sound system is closing...\n";
		this_thread::sleep_for(seconds(1));
		state = "OFF";
	}
	else
	{
		cout << "\nPlease choose available option ! \n";
	}
	return state;
}

string Home::robot_vacuum(string selection)
{
	string state;
	if (selection == "in" || selection == "In")
	{
		cout << "\nThe robot is going in to cave...\n";
		this_thread::sleep_for(seconds(1));
		state = "in Cave";
		
	}
	else if (selection == "out" || selection == "Out")
	{
		cout << "\nThe robot is going out from cave...\n";
		this_thread::sleep_for(seconds(1));
		state = "out Cave";
		
	}
	else
	{
		cout << "\nPlease choose available option ! \n";
	}
	return state;
}

string Home::garage_door(string selection)
{
	string state;
	if (selection == "OPEN" || selection == "open" || selection == "Open")
	{
		cout << "\nThe garage door is opening...\n";
		this_thread::sleep_for(seconds(1));
		state = "ON";
	}
	else if (selection == "CLOSE" || selection == "close" || selection == "Close")
	{
		cout << "\nThe garage door is closing...\n";
		this_thread::sleep_for(seconds(1));
		state = "OFF";
	}
	else
	{
		cout << "\nPlease choose available option ! \n";
	}
	return state;
}

void Home::fireAlarm(int temperature)
{
	if (temperature <= 65)
	{
		this_thread::sleep_for(milliseconds(1500));
		cout << "The value does not exceed the threshold." << endl;
	}
	else if(temperature >= 66 && temperature < 75)
	{
		this_thread::sleep_for(milliseconds(1500));
		cout << "The value exceed the threshold !" << endl;
	}
	else
	{
		for (int i = 0; i <= 2; i++)
		{
			cout << " ! FIRE ALARM ! " << endl;
			this_thread::sleep_for(seconds(1));

		}
	}
}

void Home::smokeAlarm(double smoke_value)
{
	if (smoke_value <= 120.0)
	{
		this_thread::sleep_for(milliseconds(1500));
		cout << "The value does not exceed the threshold." << endl;
	}
	else if (smoke_value >= 120.0 && smoke_value < 125.0)
	{
		this_thread::sleep_for(milliseconds(1500));
		cout << "The value exceed the threshold !" << endl;
	}
	else
	{
		for (int i = 0; i <= 2; i++)
		{
			cout << " ! SMOKE ALARM ! " << endl;
			this_thread::sleep_for(seconds(1));

		}
	}
}

void Home::motionDetector()
{
	this_thread::sleep_for(milliseconds(1570));
	cout << "Movement Detector..." << endl;
	this_thread::sleep_for(seconds(1));
	cout << "No movement detected." << endl;
	this_thread::sleep_for(seconds(1));
}

void Home::getID()
{
	cout << "-------- Home ID Informations --------" << endl;
	cout << "Home ID: " << home_ID << endl;
	cout << "Lock Card ID: " << lock_card_ID << endl << endl;
	
}