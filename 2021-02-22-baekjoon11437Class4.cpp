11437 LCA
N(2 ≤ N ≤ 50,000)개의 정점으로 이루어진 트리가 주어진다. 트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 루트는 1번이다.

두 노드의 쌍 M(1 ≤ M ≤ 10,000)개가 주어졌을 때, 두 노드의 가장 가까운 공통 조상이 몇 번인지 출력한다.



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

int MAX = 987654321;

int N, M;
int parent[50001] = {};
int depth[50001] = {};
vector<int> tree[50001];

void BFS() {
	queue<int > q;

	parent[1] = 1;
	depth[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < tree[here].size(); ++i) {
			int next = tree[here][i];
			if (!depth[next]) {
				parent[next] = here;
				depth[next] = depth[here]+1;
				q.push(next);
			}
		}
	}
}

int main() {
	int a, b;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	BFS();
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);
		if (depth[a] < depth[b])
			swap(a, b);
		while (depth[a] != depth[b]) 
			a = parent[a];
		while (a != b) {
			a = parent[a];
			b = parent[b];
		}
		printf("%d\n", a);
	}
}
