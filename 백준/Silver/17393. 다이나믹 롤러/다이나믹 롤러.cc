#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long int* ink;
long long int* vicosity;

vector<int> result;

int main()
{
	int n;

	scanf("%d", &n);

	ink = (long long int*)malloc(sizeof(long long int) * n);
	vicosity = (long long int*)malloc(sizeof(long long int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld" ,&ink[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &vicosity[i]);
	}

	//printf("<Ai>\n");

	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d ", ink[i]);
	//}
	//printf("\n");
	//printf("<Bi>\n");
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d ", vicosity[i]);
	//}
	//printf("\n");


	for (int i = 0; i < n; i++)
	{

		//printf("<ink %d>\n", i);

		int upperBoundIndex = upper_bound(vicosity + i, vicosity + n , ink[i]) -vicosity;

		result.emplace_back(upperBoundIndex - i -1);

	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", result[i]); 
	}

	return 0;
	


}

/*
* Ai >Bi 이다.
* 점도지수(bi)는 항상 오름차순으로 정렬되어 있다.
* 잉크지수(Ai)가 점도지수보다 크거나 같아야 칠할 수 있다.
* 어디까지 칠할 수 있는지를 각각 출력해주면 됀다.
*/