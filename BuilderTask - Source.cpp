#include <iostream>
#include "Builder.h"

using namespace std;

void main()
{
	Director d(new AllBuilder("mech", "elec", "electron", 10, 20, 30));
	for (int i = 0;i < 10;++i)
	{
		//cout << d.getWashinMachine()
	}
	system("pause");
}