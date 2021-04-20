11266 단절점
그래프가 주어졌을 때, 단절점을 모두 구해 출력하는 프로그램을 작성하시오.

단절점이란 그 정점을 제거했을 때, 그래프가 두 개 또는 그 이상으로 나누어지는 정점을 말한다. 즉, 제거했을 때 그래프의 connected component의 개수가 증가하는 정점을 말한다.



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

int V, E, idx = 1;
int order[10001] = {};
bool isCut[10001] = {};
vector<int> edge[10001] = {};

int DFS(int here, bool isRoot) {
	order[here] = idx++;
	int ret = order[here];
	int child = 0;

	for (int i = 0; i < edge[here].size(); ++i) {
		int next = edge[here][i];
		if (order[next]) {
			ret = min(ret, order[next]);
			continue;
		}
		child++;
		int low = DFS(next, false);
		if (!isRoot && low >= order[here])   // here가 루트가 아닐 때 자식 노드가 정점 here 거치지 않고 정점 here보다 빠른 방문번호를 가진 정점으로 갈 수 없다면 단절점
			isCut[here] = true;
		ret = min(ret, low);
	}

	if (isRoot && child >= 2)   //here가 루트일 때 자식이 2명 이상이면 단절점
		isCut[here] = true;
	return ret;
}

int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; ++i) {
		int A, B;
		scanf("%d %d", &A, &B);
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	
	for (int i = 1; i <= V; ++i) {   // 입력으로 주어지는 그래프는 연결 그래프가 아닐 수도 있으므로
		if (!order[i])
			DFS(i, true);
	}
	int ret = 0;
	for (int i = 1; i <= V; ++i) {
		if (isCut[i])
			ret++;
	}
	printf("%d\n", ret);
	for (int i = 1; i <= V; ++i) {
		if (isCut[i])
			printf("%d ", i);
	}
}
