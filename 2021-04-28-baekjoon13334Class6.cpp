13334 철로
집과 사무실을 통근하는 n명의 사람들이 있다. 각 사람의 집과 사무실은 수평선 상에 있는 서로 다른 점에 위치하고 있다. 
임의의 두 사람 A, B에 대하여, A의 집 혹은 사무실의 위치가 B의 집 혹은 사무실의 위치와 같을 수 있다. 
통근을 하는 사람들의 편의를 위하여 일직선 상의 어떤 두 점을 잇는 철로를 건설하여, 기차를 운행하려고 한다. 
제한된 예산 때문에, 철로의 길이는 d로 정해져 있다. 집과 사무실의 위치 모두 철로 선분에 포함되는 사람들의 수가 최대가 되도록, 철로 선분을 정하고자 한다.

양의 정수 d와 n 개의 정수쌍, (hi, oi), 1 ≤ i ≤ n,이 주어져 있다. 여기서 hi와 oi는 사람 i의 집과 사무실의 위치이다. 
길이 d의 모든 선분 L에 대하여, 집과 사무실의 위치가 모두 L에 포함되는 사람들의 최대 수를 구하는 프로그램을 작성하시오.

그림 1. 8 명의 집과 사무실의 위치

그림 1 에 있는 예를 고려해보자. 
여기서 n = 8, (h1, o1) = (5, 40), (h2, o2) = (35, 25), (h3, o3) = (10, 20), (h4, o4) = (10, 25), (h5, o5) = (30, 50), (h6, o6) = (50, 60), 
(h7, o7) = (30, 25), (h8, o8) = (80, 100)이고, d = 30이다. 
이 예에서, 위치 10 과 40 사이의 빨간색 선분 L이, 가장 많은 사람들에 대하여 집과 사무실 위치 모두 포함되는 선분 중 하나이다. 따라서 답은 4 이다.



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

struct info {
	long long H, O;
};

struct cmp {
	bool operator()(info &A, info &B) {
		if (A.O == B.O)
			return A.H > B.H;   // 사무실 위치가 같다면 집 위치가 작은 순
		else
			return A.O > B.O;   // 사무실 위치가 작은 순
	}
};

int n, ret = 0;
long long d;
priority_queue<info, vector<info>, cmp> pq;   // 사무실 위치가 작은 순서
priority_queue<long long, vector<long long>, greater<long long>> pq2;   // 사무실 위치

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		long long h, o;
		info tmp;
		scanf("%lld %lld", &h, &o);
		tmp.H = min(h, o);
		tmp.O = max(h, o);
		pq.push(tmp);
	}
	scanf("%lld", &d);
	while (!pq.empty()) {
		int here_h = pq.top().H, here_o = pq.top().O;
		pq.pop();
		if (here_o - here_h <= d)   // 집과 사무실의 위치 모두 철로 선분에 포함되면
			pq2.push(here_h);
		while (!pq2.empty()) {   // 이전의 선분들 확인
			int prev_h = pq2.top();
			if (prev_h < here_o - d)   // 포함안되면 지우기
				pq2.pop();
			else
				break;
		}
		int len = pq2.size();   // pq2의 크기 = L에 포함되는 사람들의 최대 수
		ret = max(ret, len);
	}
	printf("%d", ret);
}
