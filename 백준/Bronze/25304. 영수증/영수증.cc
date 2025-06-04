#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<iostream>

using namespace std;

int main()
{
    long long int x, n, a, b, result;
    result = 0;

    scanf("%lld", &x);
    scanf("%lld", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &a, &b);
        //printf("%d %d\n", a, b);

        result += a * b;
    }

    //printf("%d\n", result);


    if (result == x)
        printf("Yes\n");
    else
        printf("No\n");



    return 0;
}
