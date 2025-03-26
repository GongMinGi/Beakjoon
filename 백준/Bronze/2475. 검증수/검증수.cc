#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

int serialNumber[5];


int main()
{
	int result = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &serialNumber[i]); 
		//printf("%d ", serialNumber[i]);
		result += serialNumber[i] * serialNumber[i];

	}

	printf("%d", result % 10);
}