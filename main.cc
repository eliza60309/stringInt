#include <iostream>
#include <string>
#include "stringInt.h"

using namespace std;

int main()
{
	while(!cin.eof())
	{
		string s;
		cin >> s;
		if(s == "print")
		{
			stringInt si;
			cin >> si;
			cout << si << endl;
		}
	}
}
