#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, m; // n : 바구니개수, m: 교환 횟수
	int a, b;
	cin >> n >> m;

	int* arr = new int[n + 1];

	for (int i = 0; i < n+1; i++)
	{
		arr[i] = i;

	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		reverse(arr + a , arr + b +1 );

		//for (int i = 1; i < n + 1; i++)
		//{
		//	cout << arr[i] << " ";
		//}

		//cout << endl;

	}

	for (int i = 1; i < n+1; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;


}