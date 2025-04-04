#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int** arr;
bool** visitCheck;

int n, m, k;

queue<pair<int, int>> bfsQueue; 
vector<int> areaSizes;
void FindArea()
{
	int areaSize = 1;

	while (!bfsQueue.empty())
	{
		int curX, curY;
		curX = bfsQueue.front().first;
		curY = bfsQueue.front().second;
		bfsQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;

			if (arr[nx][ny] == 0 && visitCheck[nx][ny] == false)
			{
				visitCheck[nx][ny] = true;
				bfsQueue.push(make_pair(nx, ny));
				areaSize++;
			}
		}
	}

	areaSizes.emplace_back(areaSize);

}

void BFS()
{
	int count = 0;
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0 && visitCheck[i][j] == false)
			{
				visitCheck[i][j] = true;
				bfsQueue.push(make_pair(i, j)); 
				FindArea();
				count++;
			}
		}
	}

	sort(areaSizes.begin(), areaSizes.end());

	printf("%d\n", count);
	for (int i = 0; i < count; i++)
	{
		printf("%d ", areaSizes[i]);
	}

}

int main()
{

	scanf("%d %d %d", &m, &n, &k);

	arr = (int**)malloc(sizeof(int*) * m);
	visitCheck = (bool**)malloc(sizeof(bool*) * m);

	for (int i = 0; i < m; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
		visitCheck[i] = (bool*)malloc(sizeof(bool) * n); 

		fill(arr[i], arr[i] + n, 0);
		fill(visitCheck[i], visitCheck[i] + n, false);
	}

	for (int i = 0; i < k; i++)
	{
		int firstX, firstY, lastX, lastY;

		scanf("%d %d", &firstX, &firstY);
		scanf("%d %d", &lastX, &lastY);

		for (int p = firstY; p < lastY; p++)
		{
			for (int q = firstX; q < lastX; q++)
			{
				arr[p][q] = 1;
			}
		}
	}

	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		printf("%d", arr[i][j]);
	//	}
	//	printf("\n");
	//}

	BFS();

	return 0;
}