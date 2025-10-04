#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N[500001];
int M[500001];

int FindLowerBound(int st, int en, int numToFind)
{
	int mid;

	while (st < en)
	{
		mid = (st + en) / 2;

		if (N[mid] >= numToFind)
		{
			en = mid;
		}

		else if (N[mid] < numToFind)
		{
			st = mid + 1;
		}

	}

	return st;
}

int FindUpperBound(int st, int en, int numToFind)
{
	int mid;

	while (st < en)
	{
		mid = (st + en) / 2;

		if (N[mid] <= numToFind)
		{
			st = mid + 1;
		}

		else if (N[mid] > numToFind)
		{
			en = mid;
		}
	}

	return st;

}

int main()
{
	ios::sync_with_stdio(0);

	int n, m; 
	int lowerIndex, upperIndex;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> N[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> M[i];
	}

	sort(N, N + n); 

	int start = 0;
	int end = n;

	for (int i = 0; i < m; i++)
	{
		lowerIndex = FindLowerBound(start, end, M[i]);
		upperIndex = FindUpperBound(start, end, M[i]);

		cout << upperIndex - lowerIndex << " ";
	}

	return 0;
}