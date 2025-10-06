#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> cardsToHave;
vector<int> searchTarget;

void BinarySearch(int target, int len)
{
	int st = 0;
	int en = len;
	int mid;

	while (st < en)
	{
		mid = (st + en) / 2;

		if (cardsToHave[mid] < target)
		{
			st = mid + 1;
		}
		else if( cardsToHave[mid] > target)
		{
			en = mid;
		}
		else
		{
			cout << 1 << " ";
			return;
		}
	}

	cout << 0 << " ";
	return;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int temp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		cardsToHave.push_back(temp);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		searchTarget.push_back(temp);
	}

	sort(cardsToHave.begin(), cardsToHave.end());

	for (int i = 0; i < m; i++)
	{
		BinarySearch(searchTarget[i], cardsToHave.size());
	}

	return 0;
}