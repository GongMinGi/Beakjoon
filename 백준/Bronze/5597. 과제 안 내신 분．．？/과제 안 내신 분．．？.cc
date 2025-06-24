#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>

using namespace std;
bool* arr;

int main()
{
	arr = (bool*)malloc(sizeof(bool) * 31);
	fill(arr, arr + 31, false);
	int count = 0;
	int temp = 0;
	for (int i = 1; i < 29; i++)
	{
		scanf("%d", &temp);

		arr[temp] = true;
	}

	for (int i = 1; i < 31; i++)
	{
		if (arr[i] == false)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}