#include <iostream>

#include "fighterjet.h"
#include "uav.h"
#include "aeroplane.h"


using namespace std;

int main()
{
	Aircraft* model_1 = new UAV("Bayraktar TB2", 220);
	Aircraft* model_2 = new fighterjet("F-16", 2400);
	Aircraft* model_3 = new Aeroplane("Boing 737", 870);

    model_1->takeOff();
    model_2->engineStart();
    model_3->landing();

    cout << endl;

    model_1->getInfo();     cout << endl;
    model_2->getInfo();     cout << endl;
    model_3->getInfo();     cout << endl;

    delete model_1;
    delete model_2;
    delete model_3;

	return 0;
}