#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>


using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < n - i; k++)
		{
			printf(" ");
		}
		
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}