#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int* arr;
int* dp;

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	arr = new int[n + 1];
	dp = new int[k + 1];

	fill(dp, dp + k + 1, 0);
	dp[0] = 1;

	//for (int i = 0; i <= k ; i++)
	//{
	//	printf("%d ", dp[i]);
	//}
	//printf("\n");


	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr + 1, arr + n + 1);

	for (int i = 1; i <= n; i++)
	{
		//if (arr[i] == 1) continue;	//1원의 경우는 이미 세팅해놓음

		for (int j = arr[i]; j <= k; j++)
		{
			dp[j] = dp[j] + dp[j - arr[i]];
		}

		//for (int l = 0; l <= k; l++)
		//{
		//	printf("%d ", dp[l]);
		//}
		//printf("\n");
	}

	printf("%d\n", dp[k]);

}


/*
* n가지 동전을 조합해 k원을 만들어낼 수 있는 경우의 수
* dp[i] = i원을 구하는 경우의 수라고 가정할 때 
* dp[0] = 0; 
* dp[1] = 1원이 있다면 1
* dp[2] = 2원이 있다면 1, 
* 
* dp[i][j] 는 i번째 동전 추가 시 j원을 만드는 경우의 수
* 
* 
* 1, 2, 5원이 있다고 할 때 1원만 써서 1~k원을 만들 수 있는 경우의 수는 모두 1이다.
* - 2원을 추가로 가지고 1~k 원을 만드는수
*	- 2원으로는 2원 이하의 수는 만들 수 없으므로 2원부터 고려하면 된다.
*	- 예를들어 3원을 만들 수 있는 경우의 수는 1원으로 3원을 만드는 경우의 수 + 
*		1원을 만들 수있는 경우의 수가 된다.(1원을 만들 수 있는 경우의수에 2원을 더하면 3원이 됨)
*	- 따라서 dp[i] = dp[i] + dp[i-price[i]] ; 공식이 성립한다.
*/