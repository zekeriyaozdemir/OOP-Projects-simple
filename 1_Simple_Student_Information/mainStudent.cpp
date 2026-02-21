
#include <iostream>
#include "studentInfo.h"

using namespace std;

int main()
{

	Student arrStudent[] = { { "Zekeriya", 123123,  " Electrical-Electronic Engineering", 2021},
								{ "Mehmet  ", 741741,  " Electrical-Electronic Engineering", 2022 },
								{ "Yagmur  ", 852852,  " Mechanical Engineering           ", 2020 },
								{ "Selim   ", 369369,  " Computer Engineering             ", 2021 },
								{ "Derya   ", 789987,  " Computer Engineering             ", 2019 },
								{ "Irem    ", 842368,  " Electrical-Electronic Engineering", 2020 },
								{ "Lale    ", 753357,  " Mechanical Engineering           ", 2018 },
								{ "Serkan  ", 951159,  " Electrical-Electronic Engineering", 2021 },
								{ "Salih   ", 752046,  " Electrical-Electronic Engineering", 2020 },
								{ "Fatma   ", 789123,  " Mechanical Engineering           ", 2018 },
								{ "Kemal   ", 451957,  " Computer Engineering             ", 2023 },
								{ "Gizem   ", 748951,  " Mechanical Engineering           ", 2017 },
								{ "Orhan   ", 852132,  " Electrical-Electronic Engineering", 2005 },
								{ "Meryem  ", 845395,  " Mechanical Engineering           ", 2004 },
								{ "Zeynep  ", 954876,  " Electrical-Electronic Engineering", 2015 },
								{ "Ceylin  ", 744456,  " Electrical-Electronic Engineering", 2014 },
								{ "Tulin   ", 745123,  " Mechanical Engineering           ", 2000 },
								{ "Aslan   ", 731645,  " Computer Engineering             ", 2016 },
								{ "Mustafa ", 951033,  " Computer Engineering             ", 2008 },
								{ "Ragip   ", 121301,  " Electrical-Electronic Engineering", 2024 },
								{ "Erkan   ", 321520,  " Mechanical Engineering           ", 2025 } };


	std::cout << "************** Students Informations  **************" << std::endl;


	arrStudent->getInfo(arrStudent, 21);

	return 0;
}