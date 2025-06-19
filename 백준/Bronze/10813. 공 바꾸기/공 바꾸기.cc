#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>

using namespace std;
int* arr;

int main()
{

	int n, m;

	scanf("%d %d", &n, &m);

	arr = (int*)malloc(sizeof(int) * (n + 1));

	for (int i = 1; i < n+1; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		swap(arr[a], arr[b]);
	}

	for (int i = 1; i < n+1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}