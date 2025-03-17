#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

using namespace std;

int dp[1001][10];  // [자리수][오름수의 첫 번째 숫자]


int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				dp[i][j] = (dp[i][j] % 10007 + dp[i - 1][k] % 10007) % 10007;
			}
		}
	}


	int result = 0;

	for (int i = 0; i < 10; i++)
	{
		result = (dp[n][i] % 10007 + result % 10007) % 10007;
	}


	printf("%d\n", result);
	
	
}

/*
* n이 주어졌을때 오르막 수를 구하는 방법
* dp[1][i]에서는 1자리수로 만들 수 있는 오름수의 개수가 적히고 i하나로 만들수 있는 수는 하나이기에 그 수는 모두 1이다.
* dp[2][i]에서는 2자리로 만들수 있는 오름수의 개수
*	i가 만일 0이라면 뒤에 올 수 있는 오름수는 dp[1][0]~dp[1][9]이기 때문에 
*	오름수의 개수는 dp[2-1][i] ~ dp[2-1][9]까지의 값을 모두 합한 값이 됀다.
* 
* 이후로도 마찬가지 dp[i][j] 는 dp[i-1][j]~dp[i-1][9]까지의 값을 모두 합하는 방식으로 계산
* 결과값은 dp[n][0]~dp[n][9]까지의 값을 더한 값을 출력해주면 됀다.
*/