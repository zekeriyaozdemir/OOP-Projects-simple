#include <iostream>
#include "studentInfo.h"

using namespace std;


void Student::getInfo(Student arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << (arr + i)->Name << "  " << (arr + i)->ID << "  " << (arr + i)->department << "  " << (arr + i)->entryYear << endl;
    }
}
