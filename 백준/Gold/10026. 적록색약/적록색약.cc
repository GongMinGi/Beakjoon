#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;


char** arr;
bool** visitCheckNormal;
bool** visitCheckRedGreen;


int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n;
queue<pair<int, int>> bfsQueue;



void findConnectedRedGreen(char col1, char col2)
{
	while (!bfsQueue.empty())
	{
		int curX = bfsQueue.front().first;
		int curY = bfsQueue.front().second;
		bfsQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;

			if ((arr[nx][ny] == col1 || arr[nx][ny] == col2) && visitCheckRedGreen[nx][ny] == false)
			{
				visitCheckRedGreen[nx][ny] = true;
				bfsQueue.push(make_pair(nx, ny));
			}


		}
	}

	return;
}

void FindConnectedNormal(char col)
{
	while (!bfsQueue.empty())
	{
		int curX = bfsQueue.front().first;
		int curY = bfsQueue.front().second;
		bfsQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;

			if (arr[nx][ny] == col && visitCheckNormal[nx][ny] == false)
			{
				visitCheckNormal[nx][ny] = true;
				bfsQueue.push(make_pair(nx, ny));
			}

			
		}
	}

	return;
}


void BFS()
{
	int count = 0;
	int countRedGreen = 0;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'R' && visitCheckNormal[i][j] == false)
			{
				visitCheckNormal[i][j] = true;
				count++;
				bfsQueue.push(make_pair(i, j));
				FindConnectedNormal('R');

			}
			if (arr[i][j] == 'G' && visitCheckNormal[i][j] == false)
			{
				visitCheckNormal[i][j] = true;
				count++;
				bfsQueue.push(make_pair(i, j));
				FindConnectedNormal('G');


			}
			if (arr[i][j] == 'B' && visitCheckNormal[i][j] == false)
			{
				visitCheckNormal[i][j] = true;
				count++;
				bfsQueue.push(make_pair(i, j));
				FindConnectedNormal('B');

			}

			if ((arr[i][j] == 'R' || arr[i][j] == 'G') && visitCheckRedGreen[i][j] == false)
			{
				visitCheckRedGreen[i][j] = true;
				countRedGreen++;
				bfsQueue.push(make_pair(i, j));
				findConnectedRedGreen('R', 'G');
			}
			if (arr[i][j] == 'B' && visitCheckRedGreen[i][j] == false)
			{
				visitCheckRedGreen[i][j] = true;
				countRedGreen++;
				bfsQueue.push(make_pair(i, j));
				findConnectedRedGreen('B', 'B');
			}
		}
	}

	printf("%d %d\n", count, countRedGreen);



}


int main()
{
	scanf("%d", &n);

	arr = (char**)malloc(sizeof(char*) * n);
	visitCheckNormal = (bool**)malloc(sizeof(bool*) * n);
	visitCheckRedGreen = (bool**)malloc(sizeof(bool*) * n); 

	for (int i = 0; i < n; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * n);
		visitCheckNormal[i] = (bool*)malloc(sizeof(bool) * n);
		visitCheckRedGreen[i] = (bool*)malloc(sizeof(bool) * n);
		fill(visitCheckNormal[i], visitCheckNormal[i] + n, false);
		fill(visitCheckRedGreen[i], visitCheckRedGreen[i] + n, false);


		for (int j = 0; j < n; j++)
		{
			scanf(" %c", &arr[i][j]);
		}
	}


	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		printf("%c", arr[i][j]);
	//	}
	//	printf("\n");
	//}

	BFS();

	return 0;
}