2618 경찰차
어떤 도시의 중심가는 N개의 동서방향 도로와 N개의 남북방향 도로로 구성되어 있다.

모든 도로에는 도로 번호가 있으며 남북방향 도로는 왼쪽부터 1에서 시작하여 N까지 번호가 할당되어 있고 동서방향 도로는 위부터 1에서 시작하여 N까지 번호가 할당되어 있다. 
또한 동서방향 도로 사이의 거리와 남 북방향 도로 사이의 거리는 모두 1이다. 
동서방향 도로와 남북방향 도로가 교차하는 교차로의 위치는 두 도로의 번호의 쌍인 (동서방향 도로 번호, 남북방향 도로 번호)로 나타낸다. N이 6인 경우의 예를 들면 다음과 같다.

이 도시에는 두 대의 경찰차가 있으며 두 차를 경찰차1과 경찰차2로 부른다. 처음에는 항상 경찰차1은 (1, 1)의 위치에 있고 경찰차2는 (N, N)의 위치에 있다. 
경찰 본부에서는 처리할 사건이 있으면 그 사건이 발생된 위치를 두 대의 경찰차 중 하나에 알려 주고, 연락 받은 경찰차는 그 위치로 가장 빠른 길을 통해 이동하여 사건을 처리한다. 
(하나의 사건은 한 대의 경찰차가 처리한다.) 그리고 사건을 처리 한 경찰차는 경찰 본부로부터 다음 연락이 올 때까지 처리한 사건이 발생한 위치에서 기다린다. 
경찰 본부에서는 사건이 발생한 순서대로 두 대의 경찰차에 맡기려고 한다. 
처리해야 될 사건들은 항상 교차로에서 발생하며 경찰 본부에서는 이러한 사건들을 나누어 두 대의 경찰차에 맡기되, 
두 대의 경찰차들이 이동하는 거리의 합을 최소화 하도록 사건을 맡기려고 한다.

예를 들어 앞의 그림처럼 N=6인 경우, 처리해야 하는 사건들이 3개 있고 그 사건들이 발생된 위치 를 순서대로 (3, 5), (5, 5), (2, 3)이라고 하자. 
(3, 5)의 사건을 경찰차2에 맡기고 (5, 5)의 사건도 경찰차2에 맡기며, (2, 3)의 사건을 경찰차1에 맡기면 두 차가 이동한 거리의 합은 4 + 2 + 3 = 9가 되 고, 더 이상 줄일 수는 없다.

처리해야 할 사건들이 순서대로 주어질 때, 두 대의 경찰차가 이동하는 거리의 합을 최소화 하도록 사건들을 맡기는 프로그램을 작성하시오.



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

int N, W, MAX = 987654321;
int cache[1001][1001];
vector<pair<int, int>> Apath, Bpath;

int get_dist(int A, int B) {
	if (A == W || B == W)
		return 0;

	int& ret = cache[A][B];
	if (ret != -1)
		return ret;
	ret = MAX;
	int next = max(A, B) + 1;
	int distA = abs(Apath[next].first - Apath[A].first) + abs(Apath[next].second - Apath[A].second);
	int distB = abs(Bpath[next].first - Bpath[B].first) + abs(Bpath[next].second - Bpath[B].second);

	ret = min(ret, get_dist(next, B) + distA);
	ret = min(ret, get_dist(A, next) + distB);

	return ret;
}

void reconstruct(int A, int B) {
	if (A == W || B == W)
		return;

	int next = max(A, B) + 1;
	int distA = abs(Apath[next].first - Apath[A].first) + abs(Apath[next].second - Apath[A].second);
	int distB = abs(Bpath[next].first - Bpath[B].first) + abs(Bpath[next].second - Bpath[B].second);

	int retA = get_dist(next, B) + distA;
	int retB = get_dist(A, next) + distB;

	if (retA < retB) {
		printf("1\n");
		reconstruct(next, B);
	}
	else {
		printf("2\n");
		reconstruct(A, next);
	}
}

int main() {
	scanf("%d\n%d", &N, &W);
	memset(cache, -1, sizeof(cache));
	Apath.push_back({ 1,1 });
	Bpath.push_back({ N,N });
	for (int i = 0; i < W; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		Apath.push_back({ a,b });
		Bpath.push_back({ a,b });
	}
	printf("%d\n", get_dist(0, 0));
	reconstruct(0, 0);
}
