#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>


using namespace std;

int** a;
int** b;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	a = (int**)malloc(sizeof(int*) *n);
	b = (int**)malloc(sizeof(int*) *n);

	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * m);
		b[i] = (int*)malloc(sizeof(int) * m);

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);

		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &b[i][j]);

			a[i][j] += b[i][j];
		}

	}





	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}


	return 0;
}