7562 나이트의 이동
체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 나이트가 이동하려고 하는 칸이 주어진다. 
나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?



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

int l, sx, sy, ex, ey;
int moveX[8] = { -2,-1,1,2,-2,-1,1,2 }, moveY[8] = { 1,2,2,1,-1,-2,-2,-1 };
int visited[301][301] = {};

void BFS(int sx, int sy) {
	queue<pair<int, int>> q;
	visited[sx][sy] = 0;
	q.push({ sx,sy });

	while (!q.empty()) {
		int hereX = q.front().first, hereY = q.front().second;
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int nextX = hereX + moveX[i], nextY = hereY + moveY[i];
			if (nextX < 0 || nextX >= l || nextY < 0 || nextY >= l)
				continue;
			if (visited[nextX][nextY] == -1) {
				visited[nextX][nextY] = visited[hereX][hereY] + 1;
				q.push({ nextX, nextY });
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; ++t) {
		memset(visited, -1, sizeof(visited));
		scanf("%d", &l);
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &ex, &ey);
		BFS(sx, sy);
		printf("%d\n", visited[ex][ey]);
	}
}
