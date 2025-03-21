#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	long long int a, b, c;

	scanf("%lld %lld %lld", &a, &b, &c);

	printf("%lld\n", a + b + c);
	return 0;
}