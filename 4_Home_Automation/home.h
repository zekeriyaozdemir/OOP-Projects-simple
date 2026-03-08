#pragma once
#include <iostream>

using namespace std;

class Home {

private:

	string home_ID = "192.121.16.xx";
	string lock_card_ID = "192.121.18.xx";
	
public:

	Home();

	string lock(string option);
	string lights(string option);
	string soundSystem(string option);
	string robot_vacuum(string order);
	string garage_door(string option);

	void fireAlarm(int temperature);
	void smokeAlarm(double smoke_value);
	void motionDetector();

	void getID();
	 
};