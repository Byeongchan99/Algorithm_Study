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

struct point {
	long long x, y;
};

int N;
vector<point> p;

long long ccw(point a, point b, point c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool comp1(point a, point b) {   // y좌표, x좌표 순으로 오름차순
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}

bool comp2(point a, point b) {
	long long c = ccw(p[0], a, b);
	if (c == 0)   // 기울기가 같으면 좌표가 작은 순
		return (a.x + a.y) < (b.x + b.y);
	else
		return c > 0;   // 각도 작은 순
}

int main() {
	stack<point> s;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		p.push_back({ x,y });
	}

	sort(p.begin(), p.end(), comp1);   // pivot 찾기
	sort(p.begin() + 1, p.end(), comp2);   // 반시계 정렬

	s.push(p[0]);
	s.push(p[1]);

	for (int i = 2; i < N; ++i) {
		while (s.size() >= 2) {
			point second = s.top();
			s.pop();
			point first = s.top();

			if (ccw(first, second, p[i]) > 0) {
				s.push(second);
				break;
			}
		}
		s.push(p[i]);
	}
	printf("%d", s.size());
}