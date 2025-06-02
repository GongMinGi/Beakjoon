#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int a, b, c, k;

	scanf("%d %d %d", &a, &b, &c);

	if (a == b  && b == c)
	{
		printf("%d\n", (10000 + a * 1000));
		return 0;
	}

	else if (a == b)
	{
		printf("%d\n", 1000 + a * 100);
		return 0;
	}

	else if (c == b)
	{
		printf("%d\n", 1000 + b * 100);
		return 0;
	}

	else if (a == c)
	{
		printf("%d\n", 1000 + c * 100);
		return 0;
	}

	else
	{
		k = max(a, max(b, c));
		printf("%d\n", k * 100);
		return 0;
	}


}