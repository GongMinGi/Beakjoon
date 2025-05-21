#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>


using namespace std;

int main()
{
	int n, temp;

	scanf("%d", &n);

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &temp);
		n -= temp;
	}
	printf("%d\n", n);
}