10217 KCM Travel
각고의 노력 끝에 찬민이는 2014 Google Code Jam World Finals에 진출하게 되었다. 구글에서 온 초대장을 받고 기뻐했던 것도 잠시, 찬찬히 읽어보던 찬민이는 중요한 사실을 알아차렸다. 
최근의 대세에 힘입어 구글 역시 대기업답게 비용 감축에 열을 내고 있었던 것이다.

초대장 내용에 의하면 구글은 찬민에게 최대 M원까지의 비용만을 여행비로써 부담해주겠다고 한다. 
인천에서 LA행 직항 한 번 끊어주는게 그렇게 힘드냐고 따지고도 싶었지만, 다가올 결승 대회를 생각하면 대회 외적인 곳에 마음을 쓰고 싶지 않은 것 또한 사실이었다. 
그래서 찬민은 인천에서 LA까지 M원 이하로 사용하면서 도착할 수 있는 가장 빠른 길을 차선책으로 택하기로 하였다.

각 공항들간 티켓가격과 이동시간이 주어질 때, 찬민이 인천에서 LA로 갈 수 있는 가장 빠른 길을 찾아 찬민의 대회 참가를 도와주자.



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
int T, N, M, K, u, v, c, d;
int dist[101][10001] = {};   // dist[i][j] : i번째 노드까지 j원을 쓰고 이동할 때 걸리는 가장 짧은 소요시간
vector<pair<int, pair<int, int>>> edge[101] = {};   // 도착공항, 비용, 소요시간

void dijkstra() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	//   소요시간, 공항번호, 비용

	dist[1][0] = 0;
	pq.push({ 0,{1,0} });
	while (!pq.empty()) {
		int time = pq.top().first;
		int here = pq.top().second.first;
		int cost = pq.top().second.second;
		pq.pop();
		if (dist[here][cost] < time)   // 기존에 저장돼 있는 값이 더 작을 때
			continue;
		for (int i = 0; i < edge[here].size(); ++i) {
			int next = edge[here][i].first;
			int next_cost = edge[here][i].second.first;
			int next_time = edge[here][i].second.second;
			if (cost + next_cost <= M) {
				if (dist[next][cost + next_cost] > dist[here][cost] + next_time) {
					dist[next][cost + next_cost] = dist[here][cost] + next_time;
					pq.push({ dist[next][cost + next_cost], {next,cost + next_cost} });
				}
			}
		}
	}

	int ret = MAX;
	for (int i = 1; i <=M; ++i) 
		ret = min(ret, dist[N][i]);
	if (ret == MAX)
		printf("Poor KCM\n");
	else
		printf("%d\n", ret);
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 1; i <= N; ++i) {
			edge[i].clear();
			for (int j = 1; j <= M; ++j)
				dist[i][j] = MAX;
		}

		for (int i = 0; i < K; ++i) {
			scanf("%d %d %d %d", &u, &v, &c, &d);
			edge[u].push_back({ v,{c,d} });
		}

		dijkstra();
	}
}
