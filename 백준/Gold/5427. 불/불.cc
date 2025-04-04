#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int w, h; 

char** arr;
bool** visitCheckPlayer;
bool** visitCheckFire;

queue<pair<int, int>> bfsQueueFire;


int FiresTurn(int remainFireMove)
{
	int addedFireMove = 0;	//다음턴에 번질 불의 개수

	for(int i = 0; i<remainFireMove ; i++)
	{
		int curX = bfsQueueFire.front().first;
		int curY = bfsQueueFire.front().second;
		bfsQueueFire.pop();

		for (int j = 0; j < 4; j++)
		{
			int nx = curX + dx[j];
			int ny = curY + dy[j];

			if (nx < 0 || ny <0 || nx >= h || ny >= w)
				continue;

			if ((arr[nx][ny] == '.' || arr[nx][ny] == '@') && visitCheckFire[nx][ny] == false)
			{
				visitCheckFire[nx][ny] = true;
				arr[nx][ny] = '*';
				bfsQueueFire.push(make_pair(nx, ny));
				addedFireMove++;
			}

			
		}

	}
	return addedFireMove;
}

void BFS()
{
	while (!bfsQueueFire.empty())
	{
		bfsQueueFire.pop(); 
	}
	queue<pair<int, int>> bfsQueuePlayer;


	int remainFireMove = 0;	//이번턴에 번저야할 불의 개수
	int remainPlayerMove=0;	//이번턴에 움직여야하는 플레이어위치
	int addedPlayerMove=0;	//다음 턴에 움직일 플레이어의 위치
	int count = 0;

	//플레이어와 불의 초기 위치를 기록한다. 
	for (int i = 0; i < h ; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] == '@' && visitCheckPlayer[i][j] == false)
			{
				visitCheckPlayer[i][j] = true;
				bfsQueuePlayer.push(make_pair(i, j));
				remainPlayerMove++;
			}

			if (arr[i][j] == '*' && visitCheckFire[i][j] == false)
			{
				visitCheckFire[i][j] = true;
				bfsQueueFire.push(make_pair(i, j));
				remainFireMove++;

			}
		}
	}

	while (!bfsQueuePlayer.empty())
	{
		int curX = bfsQueuePlayer.front().first;
		int curY = bfsQueuePlayer.front().second;
		bfsQueuePlayer.pop();
		remainPlayerMove--;



		for (int i = 0; i < 4; i++)
		{
			//플레이어가 있던 자리가 불타버렸다면 생략한다.
			if (arr[curX][curY] == '*')
				break;

			int nx = curX + dx[i];
			int ny = curY + dy[i];



			//플레이어가 미로의 끝에 도달했다면
			if (nx < 0 || ny < 0 || nx >= h || ny >= w)
			{
				printf("%d\n", count + 1);
				return;
			}

			if (arr[nx][ny] == '.' && visitCheckPlayer[nx][ny] == false)
			{
				visitCheckPlayer[nx][ny] = true;
				arr[nx][ny] = '@';
				bfsQueuePlayer.push(make_pair(nx, ny));
				addedPlayerMove++;
			}
		}

		//printf("remainPlayerMove= %d\n", remainPlayerMove);

		//플레이어의 턴이 끝남
		if (remainPlayerMove == 0)
		{
			remainPlayerMove = addedPlayerMove;
			addedPlayerMove = 0;
			remainFireMove = FiresTurn(remainFireMove);	//불이 번질 차례다
			count++;


			//for (int j = 0; j < h; j++)
			//{
			//	for (int k = 0; k < w; k++)
			//	{
			//		printf("%c", arr[j][k]);
			//	}
			//	printf("\n");
			//}
		}



	}

	printf("IMPOSSIBLE\n");
	return;


}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &w, &h);

		arr = (char**)malloc(sizeof(char*) * h);
		visitCheckPlayer = (bool**)malloc(sizeof(bool*) * h);
		visitCheckFire = (bool**)malloc(sizeof(bool*) * h);

		for (int j = 0; j < h; j++)
		{
			arr[j] = (char*)malloc(sizeof(char) * h);
			visitCheckPlayer[j] = (bool*)malloc(sizeof(bool) * h);
			visitCheckFire[j] = (bool*)malloc(sizeof(bool) * h);
			fill(visitCheckPlayer[j], visitCheckPlayer[j] + w, false);
			fill(visitCheckFire[j], visitCheckFire[j] + w, false);

			for (int k = 0; k < w; k++)
			{
				scanf(" %c", &arr[j][k]);
			}

		}


		//for (int j = 0; j < h; j++)
		//{
		//	for (int k = 0; k < w; k++)
		//	{
		//		printf("%c", arr[j][k]);
		//	}
		//	printf("\n");
		//}

		BFS();


	}
	return 0;

}