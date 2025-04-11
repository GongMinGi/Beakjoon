#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long int* arr;
int* searchTargets;

int main()
{
	int n, m, target;
	int low, high, mid;
	bool targetFound = false;

	scanf("%d", &n);
	
	arr = (long long int*)malloc(sizeof(long long int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	scanf("%d", &m);

	searchTargets = (int*)malloc(sizeof(int) * m);

	for (int i= 0; i < m; i++)
	{
		scanf("%d", &searchTargets[i]);
	}

	sort(arr, arr + n);


	for (int i = 0; i < m; i++)
	{
		target = searchTargets[i];
		targetFound = false;

		low = 0;
		high = n;
		
		while (low <= high)
		{
			mid = (low + high) / 2;

			if (target == arr[mid])
			{
				targetFound = true;
				break;
			}

			if (target > arr[mid])
			{
				low = mid + 1;
			}

			if (target < arr[mid])
			{
				high = mid - 1;
			}

		}

		if (targetFound == true)
		{
			printf("1\n");
		}

		else
			printf("0\n");
	}




}