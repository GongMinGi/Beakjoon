#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int** arr;
bool** visitCheck; 

int m, n;	//가로, 세로

queue<pair<int, int>> bfsQueue;


void FindConnectedComponent()
{
	while (!bfsQueue.empty()) {
		int curX = bfsQueue.front().first;
		int curY = bfsQueue.front().second;
		bfsQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			else if (arr[nx][ny] == 1 && visitCheck[nx][ny] == false)
			{
				visitCheck[nx][ny] = true;
				bfsQueue.push(make_pair(nx, ny));
			}
		}
		
	}
}


void BFS()
{
	int count = 0; 

	//bfs큐를 비운다.
	while (!bfsQueue.empty())
	{
		bfsQueue.pop();
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1 && visitCheck[i][j] == false)
			{
				visitCheck[i][j] = true;
				bfsQueue.push(make_pair(i, j));
				count++;
				FindConnectedComponent();
			}
		}
	}

	printf("%d\n", count);


}




int main()
{
	int t, k;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d", &m, &n, &k);
		//printf("%d %d %d\n", m, n, k);
		arr = (int**)malloc(sizeof(int*) * n);
		visitCheck = (bool**)malloc(sizeof(bool*) * n);

		for (int j = 0; j < n; j++)
		{
			arr[j] = (int*)malloc(sizeof(int) * m); 
			visitCheck[j] = (bool*)malloc(sizeof(bool) * m); 
			fill(visitCheck[j], visitCheck[j] + m, false);
			fill(arr[j], arr[j] + m, 0);

		}




		for (int q = 0; q < k; q++)
		{
			int curX, curY;
			scanf("%d %d", &curY, &curX);

			//printf("%d %d\n", curX, curY);

			arr[curX][curY] = 1;

		}


		//for (int ix = 0; ix < n; ix++)
		//{
		//	for (int iy = 0; iy < m; iy++)
		//	{
		//		printf("%d", arr[ix][iy]);
		//	}
		//	printf("\n");
		//}

		
		BFS();


	}


	return 0;
}