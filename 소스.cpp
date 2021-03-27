#define _CRT_SECURE_NO_WARNINGS
#include <numeric>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>   // �ִ�, �ּڰ�
#include <cmath>   // ���� - min, max ��
#include <cassert>   // assert - ���� �����
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

bool comp1(point a, point b) {   // y��ǥ, x��ǥ ������ ��������
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}

bool comp2(point a, point b) {
	long long c = ccw(p[0], a, b);
	if (c == 0)   // ���Ⱑ ������ ��ǥ�� ���� ��
		return (a.x + a.y) < (b.x + b.y);
	else
		return c > 0;   // ���� ���� ��
}

int main() {
	stack<point> s;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		p.push_back({ x,y });
	}

	sort(p.begin(), p.end(), comp1);   // pivot ã��
	sort(p.begin() + 1, p.end(), comp2);   // �ݽð� ����

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