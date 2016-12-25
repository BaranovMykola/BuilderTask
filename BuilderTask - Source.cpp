#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>

#include "Builder.h"

using namespace std;

void main()
{
	ifstream wash("washing.txt");
	while (!wash.eof())
	{
		string a, b, c;
		int e, d, f;
		wash >> a >> e >> b >> d >> c >> f;
		AllBuilder br(a, b, c, d, e, f);
		Director dr(&br);
		int q;
		wash >> q;
		vector<WashinMachine*> data;
		for (int i = 0;i < q;++i)
		{
			data.push_back(dr.getWashinMachine());
		}
		cout << accumulate(data.begin(), data.end(), 0, [](int a, WashinMachine* v) { return a + v->price(); }) << endl;
	}
	system("pause");
}