#define _CRT_SECURE_NO_WARNINGS

#define MOD 10007

#include <stdio.h>
#include <iostream>

using namespace std;
int dp[1001][1001];

int main()
{
	int n, k;
	int numerator, denominator;
	scanf("%d %d", &n, &k);

	//if (k > n / 2)
	//{
	//	k = n - k;
	//}

	//if (k == 0)
	//{
	//	printf("1\n");
	//	return 0;
	//}

	//numerator = n;
	//denominator = 1;
	//for (int i = n -1; i > n - k; i--)
	//{
	//	numerator = ((numerator % MOD) * (i % MOD)) % MOD;
	//}

	//for (int j = 1; j <= k; j++)
	//{
	//	denominator = ((denominator % MOD) * (j % MOD)) % MOD;
	//}

	//int result = 1;

	//result = ((numerator % MOD) / (denominator % MOD)) % MOD;

	//printf("%d\n", result);


	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j == 0 || j == n)
			{
				dp[i][j] = 1;
			}

			else
			{
				dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] %MOD) %MOD;
			}
		}
	}

	printf("%d\n", dp[n][k]);
	
}