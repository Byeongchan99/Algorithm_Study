11657 타임머신
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 버스가 M개 있다. 
각 버스는 A, B, C로 나타낼 수 있는데, A는 시작도시, B는 도착도시, C는 버스를 타고 이동하는데 걸리는 시간이다. 시간 C가 양수가 아닌 경우가 있다. 
C = 0인 경우는 순간 이동을 하는 경우, C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우이다.

1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성하시오.



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

int main() {
	bool ret = false;
	int N, M, A, B, C, MAX = 987654321;
	long long dist[501] = {};
	vector<pair<int, int>> edge[501] = {};

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i)
		dist[i] = MAX;
	dist[1] = 0;

	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &A, &B, &C);
		edge[A].push_back({ B,C });
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 0; k < edge[j].size(); ++k) {
				int next = edge[j][k].first, cost = edge[j][k].second;
				if (dist[j] == MAX)
					continue;
				if (dist[next] > dist[j] + cost) {
					dist[next] = dist[j] + cost;
					if (i == N) {  // 정점정점의 수 만큼의 시행 이후에도 경로와 거리의 갱신이 일어날 경우, 음수 사이클이 존재한다고 판단
						printf("-1");
						return 0;
					}
				}
			}
		}
	}

	for (int i = 2; i <= N; ++i) {
		if (dist[i] == MAX)
			printf("-1\n");
		else
			printf("%lld\n", dist[i]);
	}
}
