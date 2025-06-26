#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>


using namespace std;

int main() 
{
	int a;

	cin >> a;

	for (int i = 0; i < a/4; i++)
	{
		cout << "long ";
	}

	cout << "int" << endl;

	return 0;
}