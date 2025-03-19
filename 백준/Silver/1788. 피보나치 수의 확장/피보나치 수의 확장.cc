#define _CRT_SECURE_NO_WARNINGS

#define MOD 1000000000
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int* dp;

int main()
{
	int n;
	scanf("%d", & n); 

	if (n < 0 && n % 2 == 0)
	{
		printf("-1\n");
	}
	else if (n != 0)
	{
		printf("1\n");
	}
	else
		printf("0\n");


	if (n >= 0)
	{
		dp = new int[n + 1];

		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD;

		}
		printf("%d", dp[n]);
	}


	else if (n < 0)
	{
		n = -n;
		//printf("%d\n", n);
		dp = new int[n + 1];
		dp[0] = 0; 
		dp[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			dp[i] = (dp[i - 2] % MOD - dp[i - 1] % MOD) % MOD;
		}

		printf("%d\n", abs(dp[n]));
	}


	
	


}