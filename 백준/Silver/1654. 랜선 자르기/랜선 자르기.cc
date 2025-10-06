#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;		// 현재 랜선 개수, 필요한 개수
vector<long long> arr;		

void Solve()
{
	long long st = 0;			
	long long en = arr[k-1];
	long long mid;
	int lineCnt;

	// n * logn
	while (st < en)
	{
		//cout << "st: " << st << " en: " << en << endl;

		mid = (st + en + 1) / 2;
		lineCnt = 0;

		for (int i = 0; i < arr.size(); i++)
		{
			lineCnt += arr[i] / mid;
		}

		if (lineCnt >= n)		// n개보다 많이 만들어진경우 => 길이가 짧다 
		{
			st = mid;
		}

		else if (lineCnt < n)  // n 개보다 적개 만들어진경우 => 길이가 너무길다
		{
			en = mid - 1;
		}
	}

	//cout << "st: " << st << " en: " << en << endl;
	cout << st;
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long temp;
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	Solve();

	return 0;
}


/*
*  현재 가진 랜선을 전부 벡터에 넣는다.
* 그중 가장 작은 길이를 최대값, 0을 최소값으로 해서 이분탐색
* mid값으로 현재가진 모든 길이를 잘랏을때 나오는 개수가 목표치 n보다 큰지 작은지 비교 
* 
*/