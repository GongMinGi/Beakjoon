#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int** arr;
bool** visitCheck;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> virusCell;
vector<int> combinationIndex;
queue<pair<int, int>> bfsQueue;

int virusCount = 0;
int n, m;
int result = 1000000;



//다음 계산을 위해 bfs 및 visitCheck 초기화
void VisitInitialization()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				visitCheck[i][j] = true;
			}
			else
				visitCheck[i][j] = false;
		}
	}

	while (!bfsQueue.empty())
	{
		bfsQueue.pop();
	}
}



//모든 노드가 방문되엇는지 벽은 이미 true이므로 모두 true라면 바이러스가 다 퍼진것
bool IsGameOver()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visitCheck[i][j] == false)
				return false;

		}
	}
	return true;
}

void BFS()
{
	int turnCount = 0;
	int remainVirusMove = bfsQueue.size();
	int addedVirusMove = 0;

	//만약 연구소크기가 1칸이고 바이러스가 바로들어가거나 벽이여서 0턴안에 처리가 가능할 때
	if (IsGameOver())
	{
		result = min(result, turnCount);
		VisitInitialization();
		return;
	}

	while (!bfsQueue.empty())
	{
		int curX = bfsQueue.front().first;
		int curY = bfsQueue.front().second;
		bfsQueue.pop(); 
			remainVirusMove--;

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;

			if ((arr[nx][ny] == 0 || arr[nx][ny] == 2) && visitCheck[nx][ny] == false)
			{
				visitCheck[nx][ny] = true;
				bfsQueue.push(make_pair(nx, ny));
				addedVirusMove++;
			}
		}

		if (remainVirusMove == 0)
		{

			//printf("\n\n");
			//for (int i = 0; i < n; i++)
			//{
			//	for (int j = 0; j < n; j++)
			//	{
			//		printf("%d", visitCheck[i][j]);
			//	}
			//	printf("\n");
			//}


			turnCount++;
			remainVirusMove = addedVirusMove;
			addedVirusMove = 0;
			if (IsGameOver())
			{
				result = min(result, turnCount);
				VisitInitialization();
				return;
			}
		}

	}
	VisitInitialization();

}

void Combination()
{
	vector<bool> temp(virusCell.size(), true);

	for (int i = 0; i < virusCell.size() - m; i++)
	{
		temp[i] = false;
	}

	do {
		for (int i = 0; i < virusCell.size(); ++i)
		{
			if (temp[i])
			{
				int x = virusCell[i].first;
				int y = virusCell[i].second;
				visitCheck[x][y] = true;
				bfsQueue.push(make_pair(x ,y));
				//printf("x : %d, y : %d /", x, y);

			}
		}
		//printf("\n");
		BFS();
	} while (next_permutation(temp.begin(), temp.end()));

}


int main()
{

	scanf("%d %d", &n, &m);

	arr = (int**)malloc(sizeof(int*) * n);
	visitCheck = (bool**)malloc(sizeof(bool*) * n);

	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
		visitCheck[i] = (bool*)malloc(sizeof(bool) * n);
		fill(visitCheck[i], visitCheck[i] + n, false);
		

		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2)
			{
				virusCount++;
				virusCell.emplace_back(i, j);
			}
			if (arr[i][j] == 1)
			{
				visitCheck[i][j] = true; // 벽 공간은 방문 처리
			}
		
		}
	}

	Combination();

	if (result == 1000000)
		printf("-1\n");
	else
		printf("%d", result);


}



/*
* 0 == 빈칸
* 1 == 벽
* 2 == 바이러스를 놓을 수 있는 칸
*/