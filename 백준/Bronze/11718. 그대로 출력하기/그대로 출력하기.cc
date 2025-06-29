#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<algorithm>
#include <string>

using namespace std;

int main()
{
	string a;
	while (1)
	{
		//cin >> a;
		getline(cin, a);
		if (a.length() == 0)
			break;
		else
			cout << a << endl;
	}

}