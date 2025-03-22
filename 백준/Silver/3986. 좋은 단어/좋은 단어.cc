#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n, cntA, cntB;
	string s;
	stack<char> abStack = {};

	//scanf("%d", &n);
	cin >> n;
	cin.ignore(); 
	int result = 0;
	for (int i = 0; i < n; i++)
	{

		getline(cin, s);


		for (int j = 0; j < s.length(); j++)
		{
			if (abStack.empty() || abStack.top() != s[j])
			{
				abStack.push(s[j]);

			}
			else if (!abStack.empty() && abStack.top() == s[j])
			{
				abStack.pop();
			}
			//printf("now s[%d]:%c\n", j, s[j]);
			//if(!abStack.empty())
			//	printf("stacktop: %c\n", abStack.top());
		}

		//스택이 비었을때만 추가
		if (abStack.empty())
		{
			//printf("현재 스택이 비어있음\n");
			result++;

			//printf("현재 result: %d\n", result);

		}
		
		abStack = {};

	}

	printf("%d\n", result);

}

/*
* 
* A와 B의 개수가 짝수여야 한다.
* A 와 A사이에 B가 홀수 게 있어서는 안됀다?
* - 그 반대 또한 마찬가지?
* 
* - STRING으로 한글 자씩 스택에 넣는다. 
* - 다르면 계속 쌓고 같으면 빼낸다.
* - 만약 스택 안에 같은 글자가 2개 이상있으면 안됌
* - 마지막에 스택 안에 남은게 있어도 안됌
*/