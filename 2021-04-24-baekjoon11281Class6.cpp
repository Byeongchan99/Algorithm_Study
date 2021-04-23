11281 2-SAT - 4
2-SAT은 N개의 불리언 변수 가 있을 때, 2-CNF 식을 true로 만들기위해 를 어떤 값으로 정해야하는지를 구하는 문제이다.

2-CNF식은  와 같은 형태이다. 여기서 괄호로 묶인 식을 절(clause)라고 하는데, 절은 2개의 변수를 한 것으로 이루어져 있다. 는 OR, 는 AND, 은 NOT을 나타낸다.

변수의 개수 N과 절의 개수 M, 그리고 식 가 주어졌을 때, 식 를 true로 만들 수 있는지 없는지를 구하는 프로그램을 작성하시오.

예를 들어, N = 3, M = 4이고,  인 경우에 을 false, 을 false, 를 true로 정하면 식 를 true로 만들 수 있다. 
하지만, N = 1, M = 2이고, 인 경우에는 에 어떤 값을 넣어도 식 f를 true로 만들 수 없다.



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

int N, M, num, cnt = 1;
int ret[20202] = {};
bool visited[20202] = {};
vector<int> g[20202] = {}, rg[20202] = {};
stack<int> s;

void DFS(int n) {
	visited[n] = true;
	for (int i = 0; i < g[n].size(); ++i) {
		if (!visited[g[n][i]])
			DFS(g[n][i]);
	}
	s.push(n);
}

void DFS2(int n) {
	visited[n] = true;
	for (int i = 0; i < rg[n].size(); ++i) {
		if (!visited[rg[n][i]])
			DFS2(rg[n][i]);
	}
	ret[n] = cnt;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int a, b, not_a, not_b;
		scanf("%d %d", &a, &b);
		if (a < 0) {
			not_a = a * -1;
			a = not_a + N;
		}
		else
			not_a = a + N;
		if (b < 0) {
			not_b = b * -1;
			b = not_b + N;
		}
		else
			not_b = b + N;

		g[not_a].push_back(b);
		g[not_b].push_back(a);
		rg[b].push_back(not_a);
		rg[a].push_back(not_b);
	}
	for (int i = 1; i <= 2 * N; ++i) {
		if (!visited[i])
			DFS(i);
	}
	memset(visited, false, sizeof(visited));
	while (!s.empty()) {
		int next = s.top();
		s.pop();
		if (!visited[next]) {
			DFS2(next);
			cnt++;
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (ret[i] == ret[i + N]) {
			printf("0");
			return 0;
		}
	}
	printf("1\n");
	for (int i = 1; i <= N; ++i) {
		if (ret[i] > ret[i + N])
			printf("1 ");
		else
			printf("0 ");
	}
}
