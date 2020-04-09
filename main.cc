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
			cin >> s;
			stringInt si(s.c_str());
			cout << si << endl;
		}
	}
}
