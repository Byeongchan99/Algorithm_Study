1707 이분 그래프
그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.



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

bool ret;
int K, V, E, s, e;
int visited[20001] = {};
vector<int> graph[20001] = {};

void BFS(int start) {
	queue<int> q;
	visited[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < graph[here].size(); ++i) {
			int next = graph[here][i];
			if (visited[next] == -1) {
				visited[next] = visited[here] + 1;
				q.push(next);
			}
			else if (visited[next] <= visited[here]) {
				if (visited[next] % 2 == visited[here] % 2) {
					ret = false;
					break;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &K);
	for (int k = 0; k < K; ++k) {
		ret = true;
		memset(visited, -1, sizeof(visited));

		scanf("%d %d", &V, &E);
		for (int i = 0; i < E; ++i) {
			scanf("%d %d", &s, &e);
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		for (int i = 1; i <= V; ++i) {
			if (visited[i] == -1)
				BFS(i);
		}

		if (ret)
			printf("YES\n");
		else
			printf("NO\n");

		for (int i = 1; i <= V; ++i)
			graph[i].clear();
	}
}
