#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include <string>

using namespace std;



int main()
{

	int n;
	cin >> n;

	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}