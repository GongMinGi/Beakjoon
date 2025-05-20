#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>


using namespace std;

int main()
{
	int n, result;
	result = 0;

	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
	{
		result += i;
	}

	printf("%d\n", result);
}