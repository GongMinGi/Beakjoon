#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int FindLowerBound(int target, int length, vector<int>& arr)
{
	int mid; 
	int st = 0;
	int en = arr.size();

	while (st < en)
	{
		mid = (st + en) / 2;
		
		if (arr[mid] >= target)
		{
			en = mid;
		}

		else
		{
			st = mid + 1;
		}
	}

	return st;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, temp, cnt;
	vector<int> coords, uniqueCoords;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		coords.push_back(temp);
		uniqueCoords.push_back(temp);
	}

	sort(uniqueCoords.begin(), uniqueCoords.end());

	uniqueCoords.erase(unique(uniqueCoords.begin(), uniqueCoords.end()), uniqueCoords.end());	// unique 전에 반드시 정렬해야 됌

	for (int i = 0; i < coords.size(); i++)
	{
		int lowerBound = FindLowerBound(coords[i], uniqueCoords.size(), uniqueCoords);
		cout << lowerBound << " ";
	}

	return 0;

}