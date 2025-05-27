#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>


using namespace std;

int main()
{
	int h, m;

	scanf("%d %d", &h, &m);

	m = m - 45;

	if (m < 0)
	{
		if (h == 0)
			h = 23;
		else
			h--;
	}

	if (m < 0)
	{
		m = 60 + m;
	}

	printf("%d %d\n", h, m);
}