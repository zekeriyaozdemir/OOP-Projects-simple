#include <iostream>
#include "aircraft.h"


using namespace std;

int main()
{
	Aircraft aircraft;
	string _name = "aircraft";
	double _maxSpeed = 12500.550;


	int selection;

	cout << "-------------- Aircraft Control --------------" << endl;
	cout << "1 - Engine Start\n" << "2 - Engine Stop\n" << "3 - Push Speed\n" << "4 - Take Off\n" 
		 << "5 - Landing\n" << "6 - Show Information\n" << "7 - Exit System\n";
	cout << "Selection: ";
	cin >> selection;
		
	while (selection != 7)
	{
		if (selection == 1)
		{
			aircraft.engineStart();
			break;
		}

		else if (selection == 2)
		{
			aircraft.engineStop();
			break;
		}

		else if (selection == 3)
		{
			aircraft.pushSpeed();
			break;
		}

		else if (selection == 4)
		{
			aircraft.takeOff();
			break;
		}

		else if (selection == 5)
		{
			aircraft.landing();
			break;
		}

		else if (selection == 6)
		{
			aircraft.getName((string)_name, (double)_maxSpeed);
			break;
		}

		else
		{
			cout << "Please Entry Valid Value ! " << endl;
			cout << "Restart The System...";
			break;
		}
	}

	return 0;
}