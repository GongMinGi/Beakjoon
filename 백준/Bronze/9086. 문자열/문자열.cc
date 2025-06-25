#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		//getline(cin, a);
		cin >> a;
		cout << a.front() << a.back() << endl;
	}

}