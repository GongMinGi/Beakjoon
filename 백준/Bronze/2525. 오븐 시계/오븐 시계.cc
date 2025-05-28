#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>


using namespace std;

int main()
{
	int hour, min, cookingTime;

	scanf("%d %d %d", &hour, &min, &cookingTime);

	hour += cookingTime / 60;
	min += cookingTime % 60;

	if (hour > 23)
	{
		hour = hour - 24;
	}

	if (min > 59)
	{
		hour++;
		if (hour > 23)
		{
			hour = hour - 24;
		}
		min = min - 60;
	}


	printf("%d %d\n", hour, min);

	return 0; 

}