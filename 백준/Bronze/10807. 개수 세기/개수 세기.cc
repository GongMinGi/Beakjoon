#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>

using namespace std;

int* arr;

int main()
{
	int n, v;
	int cnt = 0;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	scanf("%d", &v);


	for (int i = 0; i < n; i++)
	{
		if (arr[i] == v)
			cnt++;
	}

	printf("%d\n", cnt);
	return 0;
}