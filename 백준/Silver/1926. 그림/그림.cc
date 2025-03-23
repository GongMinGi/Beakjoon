#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>


using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int** arr;
bool** visitCheck;
int n, m;


void BFS()
{
	int picCount = 0;
	int maxPicArea = 0;
	queue<pair<int, int>> bfsQueue;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1 && visitCheck[i][j] == false)
			{
				visitCheck[i][j] = true;
				bfsQueue.push(make_pair(i, j));
				picCount++;
				int curArea = 1;
				while (!bfsQueue.empty())
				{
					int curX = bfsQueue.front().first;
					int curY = bfsQueue.front().second;
					bfsQueue.pop();

					for (int k = 0; k < 4; k++)
					{
						int x = curX + dx[k];
						int y = curY + dy[k];

						if (x < 0 || x >= n || y < 0 || y >= m)
							continue;
						else if (arr[x][y] == 1 && visitCheck[x][y] == false)
						{
							visitCheck[x][y] = true;
							curArea++;
							bfsQueue.push(make_pair(x, y));
						}
					}
				}

				maxPicArea = max(maxPicArea, curArea);


			}
		}
	}

	printf("%d\n", picCount);
	printf("%d\n", maxPicArea);
}


int main()
{

	scanf("%d %d", &n, &m);


	arr = (int**)malloc(sizeof(int*) * n);
	visitCheck = (bool**)malloc(sizeof(bool*) * n );

	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * m);
		visitCheck[i] = (bool*)malloc(sizeof(bool) * m);
		fill(visitCheck[i], visitCheck[i] + m, false);


		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		printf("%d", arr[i][j]);
	//	}
	//	printf("\n");
	//}


	BFS();


}