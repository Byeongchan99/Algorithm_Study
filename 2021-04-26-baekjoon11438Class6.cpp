11438 LCA 2
N(2 ≤ N ≤ 100,000)개의 정점으로 이루어진 트리가 주어진다. 트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 루트는 1번이다.

두 노드의 쌍 M(1 ≤ M ≤ 100,000)개가 주어졌을 때, 두 노드의 가장 가까운 공통 조상이 몇 번인지 출력한다.



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

int N, M, a, b;
int parent[100001][19] = {}, depth[100001] = {};
vector<int> tree[100001] = {};

void DFS(int here, int p) {
	depth[here] = depth[p] + 1;
	parent[here][0] = p;

	for (int i = 1; i <= 18; ++i) {
		int tmp = parent[here][i - 1];
		parent[here][i] = parent[tmp][i - 1];
	}
	int len = tree[here].size();
	for (int i = 0; i < len; ++i) {
		int next = tree[here][i];
		if (next != p)
			DFS(next, here);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1, 0);

	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);
		if (depth[a] > depth[b])
			swap(a, b);
		for (int i = 18; i >= 0; --i) {
			if (depth[a] <= depth[parent[b][i]])
				b = parent[b][i];
		}
		int ret = a;
		if (a != b) {
			for (int i = 18; i >= 0; --i) {
				if (parent[a][i] != parent[b][i]) {
					a = parent[a][i];
					b = parent[b][i];
				}
			}
			ret = parent[a][0];
		}
		printf("%d\n", ret);
	}
}
