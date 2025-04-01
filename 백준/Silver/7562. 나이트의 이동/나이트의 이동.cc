#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int** arr;
bool** visitCheck;

int l;

void BFS()
{
	queue<pair<int, int>> bfsQueue;
	int count = 0;
	int searchPoints = 0;
	int addedPoints = 0;

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (arr[i][j] == 1 && visitCheck[i][j] == false)
			{
				visitCheck[i][j] = true;
				bfsQueue.push(make_pair(i, j));
				searchPoints++;
			}
		}
	}

	while (!bfsQueue.empty())
	{
		int curX = bfsQueue.front().first;
		int curY = bfsQueue.front().second;
		bfsQueue.pop();
		searchPoints--;

		for (int i = 0; i < 8; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= l || ny >= l)
				continue;

			if (arr[nx][ny] == 0 && visitCheck[nx][ny] == false)
			{
				visitCheck[nx][ny] = true;
				bfsQueue.push(make_pair(nx, ny));
				addedPoints++;
			}

			if (arr[nx][ny] == 2)
			{
				printf("%d\n", count + 1);
				return;
			}
			
		}

		if (searchPoints == 0)
		{
			searchPoints = addedPoints;
			addedPoints = 0;
			count++;
		}
	}
	
}



int main()
{
	int t;
	int curX, curY, destX, destY;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d", &l);

		arr = (int**)malloc(sizeof(int*) * l);
		visitCheck = (bool**)malloc(sizeof(bool*) * l); 

		for (int j = 0; j < l; j++)
		{
			arr[j] = (int*)malloc(sizeof(int) * l);
			visitCheck[j] = (bool*)malloc(sizeof(bool) * l);
			fill(visitCheck[j], visitCheck[j] + l, false);
			fill(arr[j], arr[j] + l, 0);
		}


		//for (int i = 0; i < l ;i++)
		//{
		//	for (int j = 0; j < l; j++)
		//	{
		//		printf("%d", arr[i][j]);
		//	}
		//	printf("\n");
		//}

		scanf("%d %d", &curX, &curY);
		scanf("%d %d", &destX, &destY);

		arr[curX][curY] = 1; // 시작점
		arr[destX][destY] = 2; //목적지

		if (curX == destX && curY == destY)
		{
			printf("0\n");
			continue;
		}

		BFS();
	}

	return 0;


}