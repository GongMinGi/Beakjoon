#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>


using namespace std;

int main()
{
	int a, b, c;
	int maxLength, last1, last2;

	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0)
			break;

		if (a > b)
		{
			maxLength = a;
			last1 = b;
		}
		else
		{
			maxLength = b;
			last1 = a;
		}
		if (maxLength > c)
		{
			last2 = c;
		}
		else
		{
			last2 = maxLength;
			maxLength = c;
		}

		if (maxLength * maxLength == last1 * last1 + last2 * last2)
			printf("right\n");
		else
			printf("wrong\n");

	}
	return 0;
	
}