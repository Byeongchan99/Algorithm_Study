3176 도로 네트워크
N개의 도시와 그 도시를 연결하는 N-1개의 도로로 이루어진 도로 네트워크가 있다. 

모든 도시의 쌍에는 그 도시를 연결하는 유일한 경로가 있고, 각 도로의 길이는 입력으로 주어진다.

총 K개의 도시 쌍이 주어진다. 이때, 두 도시를 연결하는 경로 상에서 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 구하는 프로그램을 작성하시오.



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

int N, K;
int parent[100001][20] = {}, min_dist[100001][20] = {}, max_dist[100001][20] = {};
int depth[100001] = {};
vector<pair<int, int>> edge[100001] = {};

void DFS(int here, int p, int dist) {
	depth[here] = depth[p] + 1;
	parent[here][0] = p;
	min_dist[here][0] = dist;
	max_dist[here][0] = dist;

	for (int i = 1; i <= 16; ++i) {
		int tmp = parent[here][i - 1];
		parent[here][i] = parent[tmp][i - 1];
	}

	int len = edge[here].size();
	for (int i = 0; i < len; ++i) {
		int next = edge[here][i].first, cost = edge[here][i].second;
		if (next != p)
			DFS(next, here, cost);
	}
}

void get_dist() {
	for (int i = 1; i <= 16; ++i) {
		for (int j = 1; j <= N; ++j) {
			int tmp = parent[j][i - 1];
			min_dist[j][i] = min(min_dist[j][i - 1], min_dist[tmp][i - 1]);
			max_dist[j][i] = max(max_dist[j][i - 1], max_dist[tmp][i - 1]);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		edge[A].push_back({ B,C });
		edge[B].push_back({ A,C });
	}

	DFS(1, 0, 0);
	get_dist();

	scanf("%d", &K);
	for (int c = 0; c < K; ++c) {
		int D, E, min_ret = 987654321, max_ret = 0;
		scanf("%d %d", &D, &E);

		if (depth[D] > depth[E])
			swap(D, E);

		for (int i = 16; i >= 0; --i) {
			if (depth[D] <= depth[parent[E][i]]) {
				min_ret = min(min_ret, min_dist[E][i]);
				max_ret = max(max_ret, max_dist[E][i]);
				E = parent[E][i];
			}
		}

		if (D != E) {
			for (int i = 16; i >= 0; --i) {
				if (parent[D][i] != parent[E][i]) {
					min_ret = min(min_ret, min(min_dist[D][i], min_dist[E][i]));
					max_ret = max(max_ret, max(max_dist[D][i], max_dist[E][i]));
					D = parent[D][i];
					E = parent[E][i];
				}
			}
			min_ret = min(min_ret, min(min_dist[D][0], min_dist[E][0]));
			max_ret = max(max_ret, max(max_dist[D][0], max_dist[E][0]));
		}
		printf("%d %d\n", min_ret, max_ret);
	}
}
