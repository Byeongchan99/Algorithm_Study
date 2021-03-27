1761 정점들의 거리
N(2 ≤ N ≤ 40,000)개의 정점으로 이루어진 트리가 주어지고 M(1 ≤ M ≤ 10,000)개의 두 노드 쌍을 입력받을 때 두 노드 사이의 거리를 출력하라.



#define _CRT_SECURE_NO_WARNINGS
#include <numeric>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>   // greater<int>
#include <climits>   // 최댓값, 최솟값
#include <cmath>   // 수학 - min, max 등
#include <cassert>   // assert - 오류 검출용
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
using namespace std;

int N, M;
int u, v, c;
int dist[40001] = {};
int depth[40001] = {};
int parent[40001] = {};
vector<pair<int, int>> tree[40001];

void BFS() {
	queue<int> q;

	depth[1] = 1;
	parent[1] = 1;
	dist[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < tree[here].size(); ++i) {
			int next = tree[here][i].first, cost = tree[here][i].second;
			if (depth[next] == 0) {
				depth[next] = depth[here] + 1;
				parent[next] = here;
				dist[next] = dist[here] + cost;
				q.push(next);
			}
		}
	}
}

int LCA(int u, int v) {
	if (depth[u] > depth[v])
		swap(u, v);
	while (depth[u] != depth[v])
		v = parent[v];
	while (u != v) {
		u = parent[u];
		v = parent[v];
	}
	return u;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		scanf("%d %d %d", &u, &v, &c);
		tree[u].push_back({ v,c });
		tree[v].push_back({ u,c });
	}
	scanf("%d", &M);

	BFS();

	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &u, &v);
		int p = LCA(u, v);
		printf("%d\n", dist[u] + dist[v] - 2 * dist[p]);
	}
}
