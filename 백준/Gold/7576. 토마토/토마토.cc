#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>


using namespace std;

int** arr;
bool** visitCheck;
int m, n; // 가로칸, 세로칸

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool AllTomatoRipe()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visitCheck[i][j] == 0)
				return false;
		}
	}

	return true;
}


void BFS()
{
	queue<pair<int, int>> bfsQueue; 
	int dayCount = 0; 
	int addedTomatoInThisTurn = 0;
	int nowTomato = 0;

	//익어있는 첫 번째 토마토를 찾는다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
			{
				visitCheck[i][j] = true;
				bfsQueue.push(make_pair(i, j)); 
				nowTomato++;
			}
			if (arr[i][j] == -1)	//비어있는 칸은 방문할 필요가 없으므로 그냥 방문 체크해준다.
			{
				visitCheck[i][j] = true;
			}
		}
	}


	//익어있는 토마토가 하나도 없다면, -1 출력하고 끝내기
	if (bfsQueue.empty())
	{
		printf("-1\n");
		return;
	}

	//처음부터 모두 익어 잇다면 0을 출력하고 끝내기
	if (AllTomatoRipe())
	{
		printf("0\n");
		return;
	}


	while (!bfsQueue.empty())
	{
		int curX = bfsQueue.front().first;
		int curY = bfsQueue.front().second; 
		bfsQueue.pop();
		nowTomato--;

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			else if (arr[nx][ny] == 0 && visitCheck[nx][ny] == false)
			{
				visitCheck[nx][ny] = true;
				bfsQueue.push(make_pair(nx, ny));
				addedTomatoInThisTurn++;
			}
		}



		if (nowTomato == 0)
		{
			//for (int i = 0; i < n; i++)
			//{
			//	for (int j = 0; j < m; j++)
			//	{
			//		printf("%d", visitCheck[i][j]);
			//	}
			//	printf("\n");
			//}
			//printf("\n");
			dayCount++;
			nowTomato = addedTomatoInThisTurn;
			addedTomatoInThisTurn = 0;
		}
		



	}

	if (AllTomatoRipe())
	{
		printf("%d\n", dayCount-1);
		return;
	}

	printf("-1\n");
	return;

	
}

int main()
{

	scanf("%d %d", &m, &n); //열 행

	arr = (int**)malloc(sizeof(int*) * n);
	visitCheck = (bool**)malloc(sizeof(bool*) * n); 

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

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		printf("%d", visitCheck[i][j]);
	//	}
	//	printf("\n");
	//}

	BFS(); 
	
	
}