11400 단절선
그래프가 주어졌을 때, 단절선을 모두 구해 출력하는 프로그램을 작성하시오.

단절선이란 그 간선을 제거했을 때, 그래프가 두 개 또는 그 이상으로 나누어지는 간선을 말한다. 즉, 제거했을 때 그래프의 connected component의 개수가 증가하는 간선을 말한다.



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

int V, E, A, B, idx = 1;
int order[100001] = {};
vector<pair<int, int>> isCut;
vector<int> edge[100001] = {};

int DFS(int here, int parent) {
	order[here] = idx++;
	int ret = order[here];

	for (int i = 0; i < edge[here].size(); ++i) {
		int next = edge[here][i];
		if (next == parent)
			continue;
		if (order[next]) {
			ret = min(ret, order[next]);
			continue;
		}
		int low = DFS(next, here);
		if (order[here] < low)
			isCut.push_back({ min(here, next), max(here,next) });
		ret = min(ret, low);	
	}
	return ret;
}

int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; ++i) {
		scanf("%d %d", &A, &B);
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	for (int i = 1; i <= V; ++i) {
		if (!order[i])
			DFS(i, 0);
	}
	sort(isCut.begin(), isCut.end());
	int len = isCut.size();
	printf("%d\n", len);
	for (int i = 0; i < len; ++i) 
		printf("%d %d\n", isCut[i].first, isCut[i].second);
	
}
