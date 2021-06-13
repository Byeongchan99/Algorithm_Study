1520 내리막 길
여행을 떠난 세준이는 지도를 하나 구하였다. 이 지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 
한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 높이가 쓰여 있으며, 각 지점 사이의 이동은 지도에서 상하좌우 이웃한 곳끼리만 가능하다.

현재 제일 왼쪽 위 칸이 나타내는 지점에 있는 세준이는 제일 오른쪽 아래 칸이 나타내는 지점으로 가려고 한다. 
그런데 가능한 힘을 적게 들이고 싶어 항상 높이가 더 낮은 지점으로만 이동하여 목표 지점까지 가고자 한다. 위와 같은 지도에서는 다음과 같은 세 가지 경로가 가능하다.

지도가 주어질 때 이와 같이 제일 왼쪽 위 지점에서 출발하여 제일 오른쪽 아래 지점까지 항상 내리막길로만 이동하는 경로의 개수를 구하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include <numeric>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>   // 최댓값, 최솟값
#include <cmath>   // 수학 - min, max 등
#include <cassert>   // assert - 오류 검출용
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
using namespace std;

int M, N;
int Map[501][501] = {}, visited[501][501] = {};
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

int DFS(int y, int x) {
	if (y == M - 1 && x == N - 1)
		return 1;
	if (visited[y][x] == -1) {
		visited[y][x] = 0;
		for (int i = 0; i < 4; ++i) {
			int nextY = y + dy[i], nextX = x + dx[i];
			if (nextY < 0 || nextY >= M || nextX < 0 || nextX >= N)
				continue;
			if (Map[y][x] > Map[nextY][nextX])
				visited[y][x] += DFS(nextY, nextX);
		}
	}
	return visited[y][x];
}

int main() {
	memset(visited, -1, sizeof(visited));
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j)
			scanf("%d", &Map[i][j]);
	}
	DFS(0, 0);
	printf("%d", visited[0][0]);
}
