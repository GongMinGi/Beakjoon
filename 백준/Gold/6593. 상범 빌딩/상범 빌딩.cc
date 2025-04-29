#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <tuple>
//#include <algorithm>

using namespace std;

char*** building;
bool*** visitCheck;

int L, R, U;

int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };



void BFS()
{

	queue<tuple<int, int, int>> bfsQueue;

	int turnCount = 0;
	int addedElementNowTurn = 0;
	int lastElement = 0;
	//시작 지점 정하기
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < U; k++)
			{
				if (building[i][j][k] == 'S' && visitCheck[i][j][k] == false)
				{
					visitCheck[i][j][k] = true;
					bfsQueue.push(make_tuple(i, j ,k));
					lastElement++;
				}
			}
		}
	}


	while (!bfsQueue.empty())
	{
		int curX = get<0>(bfsQueue.front());
		int curY = get<1>(bfsQueue.front());
		int curZ = get<2>(bfsQueue.front());

		bfsQueue.pop();
		lastElement--;

		for (int i = 0; i < 6; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			int nz = curZ + dz[i];

			if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= U)
				continue;

			if (building[nx][ny][nz] == 'E')
			{
				turnCount++;
				printf("Escaped in %d minute(s).\n", turnCount);
				return;
			}

			if (building[nx][ny][nz] == '.' && visitCheck[nx][ny][nz] == false)
			{
				visitCheck[nx][ny][nz] = true;
				bfsQueue.push(make_tuple(nx, ny, nz)); 
				addedElementNowTurn++;
			}
		}

		if (lastElement == 0)
		{
			turnCount++;
			lastElement = addedElementNowTurn;
			addedElementNowTurn = 0;
		}


	}

	printf("Trapped!\n");
	return;

}


int main()
{
	char temp;

	while (1)
	{
		scanf("%d %d %d", &L, &R, &U);

		if (L == 0 && R == 0 && U == 0)
			break;

		//printf("%d %d %d\n", L, R, U);

		building = (char***)malloc(sizeof(char**) * L);
		visitCheck = (bool***)malloc(sizeof(bool***) * L);
		for (int i = 0; i < L; i++)
		{
			building[i] = (char**)malloc(sizeof(char*) * R);
			visitCheck[i] = (bool**)malloc(sizeof(bool*) * R);
			for (int j = 0; j < R; j++)
			{
				building[i][j] = (char*)malloc(sizeof(char) * U);
				visitCheck[i][j] = (bool*)malloc(sizeof(bool) * U);
				fill(visitCheck[i][j], visitCheck[i][j] + U, false);

				for (int k = 0; k < U; k++)
				{
					scanf(" %c", &building[i][j][k]);
				}
			}
			scanf("%c", &temp); 
		}

		//for (int i = 0; i < L; i++)
		//{
		//	for (int j = 0; j < R; j++)
		//	{
		//		for (int k = 0; k < U; k++)
		//		{
		//			printf("%c", building[i][j][k]);
		//		}
		//		printf("\n");
		//	}
		//	printf("\n");
		//}

		BFS();
	}

	return 0;

}



/*
* # : 지나갈 수 없는 칸
* . : 비어잇는 칸
* s : 시작 지점
* E : 탈출구
* 
* 각 층 사이에는 빈 줄이 존재,
* 입력의 끝에서는 L,R,C 가 모두 0으로 표현
* 
* 동서남북 상하로 이동 가능
*/