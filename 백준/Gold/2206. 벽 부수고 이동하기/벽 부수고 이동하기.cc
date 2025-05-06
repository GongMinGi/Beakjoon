#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <iostream>
#include <queue>
#include <tuple>


using namespace std;

int** arr;
bool*** visitCheck;

//동, 북, 서 ,남
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;



queue<pair<int, int>> wallList; 
pair<int, int> brokenWall;


int BFS(int startX, int startY, int endX, int endY)
{
	queue<tuple<int, int, bool>> bfsQueue;

	int addedElementInThisTurn = 0;
	int lastEleentInThisTurn = 0;
	int turnCount = 1;

	//시작지점은 1,1
	if (arr[startX][startY] == 0 && visitCheck[0][startX][startY] == false)
	{
		visitCheck[0][startX][startY] = true;
		bfsQueue.push(make_tuple(startX, startY, true));
		lastEleentInThisTurn++;
	}
	else if (arr[startX][startY] == 1 && visitCheck[0][startX][startY] == false )
	{
		//visitCheck[1][startX][startY] = true;	// 이제 벽을 부술 수 없음
		visitCheck[0][startX][startY] = true;
		bfsQueue.push(make_tuple(startX, startY, false));
		lastEleentInThisTurn++;
	}

	while (!bfsQueue.empty())
	{
		int curX = get<0>(bfsQueue.front());
		int curY = get<1>(bfsQueue.front());
		bool canBreakWall = get<2>(bfsQueue.front());
		bfsQueue.pop();
		lastEleentInThisTurn--;


		if (curX == endX && curY == endY)
		{
			return turnCount;
		}


		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;


			//벽을 부수지 않고 이동
			if (canBreakWall == true && arr[nx][ny] == 0 && visitCheck[0][nx][ny] == false)
			{

				visitCheck[0][nx][ny] = true;	//방문 체크
				visitCheck[1][nx][ny] = true;	//방문 체크
				bfsQueue.push(make_tuple(nx, ny, true)); // 벽을 부수고 이동하는것이 아니므로 원래 가지고있던 bool 값을 넣음
				addedElementInThisTurn++;
			}

			//벽을 부수고 이동
			if ( canBreakWall == true && arr[nx][ny] == 1 && visitCheck[0][nx][ny] == false )
			{
				visitCheck[0][nx][ny] = true;
				visitCheck[1][nx][ny] = true;
				bfsQueue.push(make_tuple(nx, ny, false));
				addedElementInThisTurn++;
			}

			//벽을 부순 다음 이동
			if (canBreakWall == false && arr[nx][ny] == 0 && visitCheck[1][nx][ny] == false)
			{
				visitCheck[1][nx][ny] = true;	//방문 체크
				bfsQueue.push(make_tuple(nx, ny, false)); 
				addedElementInThisTurn++;
			}
		}

		if (lastEleentInThisTurn == 0)
		{
			turnCount++;
			lastEleentInThisTurn = addedElementInThisTurn;
			addedElementInThisTurn = 0;

			//printf("\n");
			//for (int i = 0; i < n; i++)
			//{
			//	for (int j = 0; j < m; j++)
			//	{
			//		printf("%d", visitCheck[0][i][j]);
			//	}
			//	printf("\n");
			//}


		}
	}

	return -1;

}




int main()
{
	int shortestPath = -1;
	int bfsDistance = 0;

	char tempChar[1001];

	scanf("%d %d", &n, &m);

	//printf("%d %d\n", n, m);

	visitCheck = (bool***)malloc(sizeof(bool**) * 2);

	for (int i = 0; i < 2; i++)
	{
		visitCheck[i] = (bool**)malloc(sizeof(bool*) * n);
	}

	arr = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * m);
		visitCheck[0][i] = (bool*)malloc(sizeof(bool) * m);
		visitCheck[1][i] = (bool*)malloc(sizeof(bool) * m);

		fill(visitCheck[0][i], visitCheck[0][i] + m, false);
		fill(visitCheck[1][i], visitCheck[1][i] + m, false);


		scanf("%s", &tempChar);

		for (int j = 0; j < m; j++)
		{
			arr[i][j] = tempChar[j] - 48;

		}

	}





	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		printf("%d", visitCheck[0][i][j]);
	//	}
	//	printf("\n");
	//}

	bfsDistance = BFS(0, 0, n-1, m-1);

	shortestPath = max(shortestPath, bfsDistance);

	for (int i = 0; i < n; i++)
	{
		fill(visitCheck[0][i], visitCheck[0][i] + m, false);
		fill(visitCheck[1][i], visitCheck[1][i] + m, false);
	}

	//printf("\n\n%d\n\n", shortestPath);

	//printf("\n\n reverse \n\n "); 


	bfsDistance = BFS(n - 1, m - 1, 0, 0);

	if (shortestPath == -1)
	{
		shortestPath = max(shortestPath, bfsDistance);
	}
	else if (bfsDistance != -1)
		shortestPath = min(shortestPath, bfsDistance);


	//printf("\n\n%d\n\n", shortestPath);


	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		printf("%d", visitCheck[0][i][j]);
	//	}
	//	printf("\n");
	//}


	printf("%d\n", shortestPath);


}




/*
* n x m의 맵.
* 0 : 이동가능
* 1 : 이동불가능한 벽
* 1,1 에서 m,n까지 이동하는 최단 경로를 계산한다.
* 만약, 벽을 부수고 이동하는 경우가 더 짧다면 1개까지 부술 수 있음
* 
* 아이디어
* - 벽의 개수만큼 bfs를 실시한다.
* - bfs로 계산한 최단 거리(턴 수)를 이전 값과 min연산을 통해 계속해서 비교한다.
* - 최종값을 출력
*	==> 시간초과. bfs 1번만에 풀 수 있는 방법을 생각해야 한다
* 
* - 1칸짜리 벽은 모두 뚫을 수 있다.
* - 앞 뒤로, 혹은 좌우로 벽이 없다면 뚫을 수 있다.
*	- bfs 진행 전에 한칸짜리 벽을 전부 부숴놓고 시작한다면..
*	=> 벽을 여러개 부수는 루트로 전진하게 됨
* 
* - 해설...
*	=> bfs의 상태까지 고려해야하는 문제
*	visitCHeck를 3차원으로 확장해서 해당칸에서 벽을 부순적이 있는지를 채크 [x][y][벽을 부순적이 있는가?] ㄷㄷ 
* 
* - 시작점에서만 bfs를 실행하면 도달하지 못하는 경우가존재.
*	=> 목적지에서 시작해도 결과는 똑같으니 두 번 실행해서 답을 정하면 됨
* 
* - 도착지점에 1이 있는 경우를 고려하지 않음
*	=> 해결
* 
* - 이미 벽을 부순 경로가 부술 기회를 가지고 있는 경로의 기회를 뺏는 문제 발생
*	=> 큐의 요소끼리 visitcheck 배열을 공유하기 떄문에 발생하는 문제, 
*		따라서, 큐의 구성요소를 튜플로만들자.
*	=> 튜플로 만들어도 visitcheck에 방문을 찍는다는 것은 동일하다
* 
* - 그렇다면, 벽을 부순 element는 [0][x][y] 가아니라 [1][x][y]에만 방문체크를 하자 => 차원의 분리
*	=> 해결
* 
* - ... reverse를 계산할 때 튜플을 초기화해주는 걸 잊지마
*/