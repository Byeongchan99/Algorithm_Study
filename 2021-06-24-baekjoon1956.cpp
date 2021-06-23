1956 운동
V개의 마을와 E개의 도로로 구성되어 있는 도시가 있다. 도로는 마을과 마을 사이에 놓여 있으며, 일방 통행 도로이다. 마을에는 편의상 1번부터 V번까지 번호가 매겨져 있다고 하자.

당신은 도로를 따라 운동을 하기 위한 경로를 찾으려고 한다. 운동을 한 후에는 다시 시작점으로 돌아오는 것이 좋기 때문에, 우리는 사이클을 찾기를 원한다. 
단, 당신은 운동을 매우 귀찮아하므로, 사이클을 이루는 도로의 길이의 합이 최소가 되도록 찾으려고 한다.

도로의 정보가 주어졌을 때, 도로의 길이의 합이 가장 작은 사이클을 찾는 프로그램을 작성하시오. 두 마을을 왕복하는 경우도 사이클에 포함됨에 주의한다.



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
int V, E, a, b, c;
int city[401][401] = {};

int main() {
	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; ++i) {
		for (int j = i + 1; j <= V; ++j) {
			city[i][j] = MAX;
			city[j][i] = MAX;
		}
	}

	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		if (city[a][b] > c)
			city[a][b] = c;
	}

	for (int k = 1; k <= V; ++k) {   // 중간
		for (int i = 1; i <= V; ++i) {   // 시작
			if (city[i][k] == 0)
				continue;
			for (int j = 1; j <= V; ++j) {  // 끝
				if (city[k][j] == 0 || i == j)
					continue;
				if (city[i][j] > city[i][k] + city[k][j])
					city[i][j] = city[i][k] + city[k][j];
			}
		}
	}

	int ret = MAX;
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (i == j)
				continue;
			ret = min(ret, city[i][j] + city[j][i]);
		}
	}
	if (ret == MAX)
		printf("-1");
	else
		printf("%d", ret);
}
