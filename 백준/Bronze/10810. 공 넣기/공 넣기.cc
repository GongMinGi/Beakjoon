#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int* arr;

int main()
{
	int n, m; 
	int a, b, c; 

	scanf("%d %d", &n, &m);
	
	arr = (int*)malloc(sizeof(int) * (n + 1));
	fill(arr, arr + n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);

		for (int i = a; i <= b; i++)
		{
			arr[i] = c;
		}

	}

	for (int i = 1	; i < n+1; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0; 

}