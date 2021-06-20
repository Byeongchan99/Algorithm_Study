9370 미확인 도착지
(취익)B100 요원, 요란한 옷차림을 한 서커스 예술가 한 쌍이 한 도시의 거리들을 이동하고 있다. 너의 임무는 그들이 어디로 가고 있는지 알아내는 것이다. 
우리가 알아낸 것은 그들이 s지점에서 출발했다는 것, 그리고 목적지 후보들 중 하나가 그들의 목적지라는 것이다. 
그들이 급한 상황이기 때문에 목적지까지 우회하지 않고 최단거리로 갈 것이라 확신한다. 이상이다. (취익)

어휴! (요란한 옷차림을 했을지도 모를) 듀오가 어디에도 보이지 않는다. 다행히도 당신은 후각이 개만큼 뛰어나다. 
이 후각으로 그들이 g와 h 교차로 사이에 있는 도로를 지나갔다는 것을 알아냈다.

이 듀오는 대체 어디로 가고 있는 것일까?

예제 입력의 두 번째 케이스를 시각화한 것이다. 이 듀오는 회색 원에서 두 검은 원 중 하나로 가고 있고 점선으로 표시된 도로에서 냄새를 맡았다. 따라서 그들은 6으로 향하고 있다.



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
int T, n, m, t, s, g, h, a, b, d, x;
vector<int> ret;
vector<pair<int, int>> edge[2001] = {};   // 노드 번호, 거리

vector<int> dijkstra(int start) {
	vector<int> dist(n + 1, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   // 거리, 노드 번호

	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int here = pq.top().second;
		pq.pop();
		for (int i = 0; i < edge[here].size(); ++i) {
			int next = edge[here][i].first, next_cost = edge[here][i].second;
			if (dist[next] > dist[here] + next_cost) {
				dist[next] = dist[here] + next_cost;
				pq.push({ dist[next],next });
			}
		}
	}
	return dist;
} 

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &a, &b, &d);
			edge[a].push_back({ b,d });
			edge[b].push_back({ a,d });
		}
		for (int i = 0; i < t; ++i) {
			scanf("%d", &x);
			ret.push_back(x);
		}
		sort(ret.begin(), ret.end());

		vector<int> dist_s = dijkstra(s);   // s에서 시작
		vector<int> dist_g = dijkstra(g);   // g에서 시작
		vector<int> dist_h = dijkstra(h);   // h에서 시작

		for (int i = 0; i < t; ++i) {
			int dest = ret[i];
			if (dist_s[dest] == dist_s[g] + dist_g[h] + dist_h[dest] || dist_s[dest] == dist_s[h] + dist_h[g] + dist_g[dest])
				printf("%d ", dest);
		}   // s-g-h-t, s-h-g-t
		printf("\n");
		ret.clear();
		for (int i = 0; i <= n; ++i)
			edge[i].clear();
	}
}
