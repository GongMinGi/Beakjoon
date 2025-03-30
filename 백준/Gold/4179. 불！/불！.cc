#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char** arr;
bool** visitCheck;
int r, c;


int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> playerQueue;
queue<pair<int, int>> fireQueue;

int Fire(int fireTrace)
{
	int addedFireTrace = 0;			//이번턴에 찾아서 다음턴에 추가할 불의 자취



	for (int j = 0; j < fireTrace; j++)
	{
		int fireX = fireQueue.front().first;
		int fireY = fireQueue.front().second;
		fireQueue.pop();
		//printf("x: %d y : %d\n", fireX, fireY);
		//불이 번질 차례. 사방으로 불이 번진다.
		for (int i = 0; i < 4; i++)
		{
			int nx = fireX + dx[i];
			int ny = fireY + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
			{
			
				continue;
			}

			else if (arr[nx][ny] == 'J' || arr[nx][ny] == '.')
			{
				arr[nx][ny] = 'F';
				fireQueue.push(make_pair(nx, ny));
				addedFireTrace++;
			}

		}


	}

	return addedFireTrace;


}


void BFS()
{
	//printf("inBFS\n");
	int count = 0;

	int addedPlayerTrace = 0;		//이번턴에 찾아서 다음턴에 추가할 플레이어의 발자취
	int playerTrace = 0;			//이번턴에 탐색해야할 플레이어의 발자취
	int fireTrace = 0;				//이번턴에 탐색해야할 불의 자취
	bool fireIsSpread = false;		//이번 턴에 불이 번졌는지 여부 

	//printf("%d %d\n", r, c);

	//배열을 돌면서 플레이어와 불의 초기좌표를 찾아 큐에 넣는다
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			//printf("%d,%d\n", i, j);
			if (arr[i][j] == 'J')
			{
				visitCheck[i][j] = true;
				playerQueue.push(make_pair(i, j));
				playerTrace++;
				//printf("added\n");
			}

			else if (arr[i][j] == 'F')
			{
				fireQueue.push(make_pair(i, j));
				fireTrace++;
			}
		}
	}
	//printf("inBFS2\n");


	while (!playerQueue.empty())
	{
		int curX = playerQueue.front().first;
		int curY = playerQueue.front().second;
		playerQueue.pop();
		playerTrace--;

		//printf("playertrace: %d\n", playerTrace);



		//플레이어 주변 4방위에 갈 수 있는 길이 있다면, 간다.
		for (int i = 0; i < 4; i++)
		{

			// 플레이어가 있던 자리가 불타버린 경우, 생략한다.
			if (arr[curX][curY] == 'F')
			{
				break;
			}


			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
			{
				count++;
				printf("%d\n", count);
				return;
			}

			if (arr[nx][ny] == '.' && visitCheck[nx][ny] == false)
			{
				visitCheck[nx][ny] = true;
				arr[nx][ny] = 'J';
				playerQueue.push(make_pair(nx, ny));
				addedPlayerTrace++;
				//printf("added player trace: %d\n", addedPlayerTrace);
			}

		}


		//지난 턴에 추가한 플레이어의 자취를 전부 탐색했다면, count를 올린다.
		if (playerTrace == 0)
		{
			//printf("턴 종료\n");

			fireTrace = Fire(fireTrace);	//턴이 끝날 때마다 불이 한 칸씩 번진다.
			playerTrace = addedPlayerTrace;
			addedPlayerTrace = 0;
			count++;

			//printf("firetrace : %d\n", fireTrace);
			//printf("added player trace: %d\n", addedPlayerTrace);
			//printf("playertrace: %d\n", playerTrace);



		}
		//else {
		//	printf("턴 진행중\n");
		//	printf("firetrace : %d\n", fireTrace);
		//	printf("added player trace: %d\n", addedPlayerTrace);
		//	printf("playertrace: %d\n", playerTrace);
		//}


		//printf("\n");
		//for (int i = 0; i < r; i++)
		//{
		//	for (int j = 0; j < c; j++)
		//	{
		//		printf("%c", arr[i][j]);
		//	}
		//	printf("\n");
		//}

		//printf("\n");
		//printf("\n");


		
	}

	//미로의 끝을 찾지 못했다면, 출력
	printf("IMPOSSIBLE\n");
	return;
	
}


int main()
{
	scanf("%d %d", &r, &c);

	//printf("%d %d\n", r, c);

	arr = (char**)malloc(sizeof(char*) * (r +1));
	visitCheck = (bool**)malloc(sizeof(bool*) * (r + 1));

	for (int i = 0; i < r; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * (c + 1));
		visitCheck[i] = (bool*)malloc(sizeof(bool) * (c + 1));
		fill(visitCheck[i], visitCheck[i] + c + 1, false);

		for (int j = 0; j < c; j++)
		{
			scanf(" %c", &arr[i][j]);

		}
	}


	//for (int i = 0; i < r; i++)
	//{
	//	for (int j = 0; j < c; j++)
	//	{
	//		printf("%c", arr[i][j]);
	//	}
	//	printf("\n");
	//}

	BFS();


	return 0;
}

/*
* 
* 불이 먼저 번지나 사람이 먼저 이동하나?
* 불은 한 턴에 한번만 진행되어야 한다.
*/