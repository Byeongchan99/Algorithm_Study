5719 거의 최단 경로
요즘 많은 자동차에서는 GPS 네비게이션 장비가 설치되어 있다. 네비게이션은 사용자가 입력한 출발점과 도착점 사이의 최단 경로를 검색해 준다. 
하지만, 교통 상황을 고려하지 않고 최단 경로를 검색하는 경우에는 극심한 교통 정체를 경험할 수 있다.

상근이는 오직 자기 자신만 사용 가능한 네비게이션을 만들고 있다. 이 네비게이션은 절대로 최단 경로를 찾아주지 않는다. 항상 거의 최단 경로를 찾아준다.

거의 최단 경로란 최단 경로에 포함되지 않는 도로로만 이루어진 경로 중 가장 짧은 것을 말한다. 

예를 들어, 도로 지도가 아래와 같을 때를 생각해보자. 원은 장소를 의미하고, 선은 단방향 도로를 나타낸다. 시작점은 S, 도착점은 D로 표시되어 있다. 굵은 선은 최단 경로를 나타낸다. 
(아래 그림에 최단 경로는 두 개가 있다)거의 최단 경로는 점선으로 표시된 경로이다. 이 경로는 최단 경로에 포함되지 않은 도로로 이루어진 경로 중 가장 짧은 경로이다. 
거의 최단 경로는 여러 개 존재할 수도 있다. 예를 들어, 아래 그림의 길이가 3인 도로의 길이가 1이라면, 거의 최단 경로는 두 개가 된다. 또, 거의 최단 경로가 없는 경우도 있다.



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

int N, M, S, D, U, V, P, MAX = 987654321;
vector<pair<int, int>> edge[501], path[501];   // path[501] : 최단 경로에 사용된 간선들 저장

int dijkstra(int node) {
	vector<int> dist(501, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[node] = 0;
	pq.push({ node,0 });

	while (!pq.empty()) {
		int here = pq.top().first, cost = pq.top().second;
		pq.pop();
		if (dist[here] < cost)   // 저장된 경로보다 비용이 크면 
			continue;
		for (int i = 0; i < edge[here].size(); ++i) {
			int next = edge[here][i].first, next_cost = edge[here][i].second;
			if (next_cost == -1)
				continue;
			if (dist[next] > dist[here] + next_cost) {
				dist[next] = dist[here] + next_cost;
				pq.push({ next,dist[next] });
				path[next].clear();   // 더 짧은 경로가 있으면 새롭게 갱신
				path[next].push_back({ here, dist[next] });
			}
			else if (dist[next] == dist[here] + next_cost)   // 같은 비용의 경로가 있을 경우 추가
				path[next].push_back({ here, dist[next] });
		}
	}
	return dist[D];
}

int main() {
	while (1) {
		memset(edge, 0, sizeof(edge));
		memset(path, 0, sizeof(path));
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0)
			break;
		scanf("%d %d", &S, &D);
		for (int i = 0; i < M; ++i) {
			scanf("%d %d %d", &U, &V, &P);
			edge[U].push_back({ V,P });
		}
		dijkstra(S);
		
    // BFS로 최단 경로에 사용된 간선들 삭제
    
		bool visited[501][501] = {};   // 간선 방문 여부
		queue<int> q;
		q.push(D);
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (int i = 0; i < path[here].size(); ++i) {
				int prev = path[here][i].first;
				if (visited[here][prev] == true)
					continue;
				visited[here][prev] = true;
				for (int j = 0; j < edge[prev].size(); ++j) {
					if (edge[prev][j].first == here)
						edge[prev][j].second = -1;
				}
				q.push(prev);
			}
		}

		int ret = dijkstra(S);
		if (ret == MAX)
			printf("-1\n");
		else
			printf("%d\n", ret);
	}
}
