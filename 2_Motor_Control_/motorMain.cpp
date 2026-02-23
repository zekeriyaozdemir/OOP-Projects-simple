#include <iostream>
#include "motorParameter.h"

using namespace std;

int main()
{
	int size = 10;
	int count = 0;

	int function = 0;
	double threshold = 100.0;
	int duty;

	float heatLevel;

	Motor motor;

	cout << "************** MOTOR CONTROL PANEL **************" << endl;
	
	cout << "======= Choose function =======" << endl;
	cout << "1 - START" << endl << "2 - STOP" << endl
		<< "3 - SET SPEED" << endl << "4 - Heat Calculation" << endl
		<< "5 - EXIT" << endl;
	cout << "Your choice: ";
	cin >> function;

	if (function == 5) cout << "Exiting from the Panel..." << endl;

	while (function != 5)
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
		else if (function == 4)				// measurement ten times for Heat Average
		{
			for (int k = 0; k < size; k++)       
			{
				cout << k+1 << ".Value: ";
				cin >> heatLevel;
				count += heatLevel;
			}
			motor.heatSensor( (float) count, (int) size);
			break;
		}
		else
		{
			cout << "Please Entry A Valid Value..." << endl;
			cout << "Please Choose 1 - start, 2 - stop, 3 - set speed, 4 - Heat Calculation ..." << endl << "your Choice: ";
			cin >> function;
		}
    }




	return 0;
}