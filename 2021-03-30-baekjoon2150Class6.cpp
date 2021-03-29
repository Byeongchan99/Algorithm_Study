2150 Strongly Connected Component
방향 그래프가 주어졌을 때, 그 그래프를 SCC들로 나누는 프로그램을 작성하시오.

방향 그래프의 SCC는 우선 정점의 최대 부분집합이며, 그 부분집합에 들어있는 서로 다른 임의의 두 정점 u, v에 대해서 
u에서 v로 가는 경로와 v에서 u로 가는 경로가 모두 존재하는 경우를 말한다.

예를 들어 위와 같은 그림을 보자. 이 그래프에서 SCC들은 {a, b, e}, {c, d}, {f, g}, {h} 가 있다. 물론 h에서 h로 가는 간선이 없는 경우에도 {h}는 SCC를 이룬다.
  
  
  
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

int V, E;
vector<int> g[10001] = {}, rg[10001] = {}, num;
vector<vector<int>> ret;
stack<int> s;
bool visited[10001] = {};

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
	num.push_back(n);
}

int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; ++i) {
		int A, B;
		scanf("%d %d", &A, &B);
		g[A].push_back(B);
		rg[B].push_back(A);
	}
	for (int i = 1; i <= V; ++i) {
		if (!visited[i])
			DFS(i);
	}
	memset(visited, false, sizeof(visited));
	while (!s.empty()) {
		int next = s.top();
		s.pop();
		if (!visited[next]) {
			DFS2(next);
			sort(num.begin(), num.end());
			ret.push_back(num);
			num.clear();
		}
	}
	printf("%d\n", ret.size());
	sort(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j)
			printf("%d ", ret[i][j]);
		printf("-1\n");
	}
}
