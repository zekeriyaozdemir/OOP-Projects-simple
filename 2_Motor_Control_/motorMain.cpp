#include <iostream>
#include "motorParameter.h"

using namespace std;

int main()
{
	int function = 0;
	double threshold = 100.0;
	int duty;

	Motor motor;

	cout << "************** MOTOR CONTROL PANEL **************" << endl;

	cout << "======= Choose function =======" << endl;
	cout << "1 - START" << endl << "2 - STOP" << endl << "3 - SET SPEED" << endl << "4 - Quit" << endl;
	cout << "Your choice: ";
	cin >> function;

	if (function == 4) cout << "Exiting from the Panel..." << endl;

	while (function != 4)
	{
		if (function == 1)
		{
			motor.start();
			break;
		}
		else if (function == 2)
		{
			motor.stop();
			break;
		}
		else if (function == 3)
		{
			cout << "Please Entry Speed Value: ";
			cin >> duty;
			motor.setSpeed(duty, threshold);
			break;
		}
		else
		{
			cout << "Please Entry A Valid Value..." << endl;
			cout << "Please Choose 1 - start, 2 - stop, 3 - set speed, 4 - Exit ..." << endl << "your Choice: ";
			cin >> function;
		}
    }


	return 0;
}