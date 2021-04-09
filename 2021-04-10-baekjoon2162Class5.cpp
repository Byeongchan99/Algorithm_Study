2162 선분 그룹
N개의 선분들이 2차원 평면상에 주어져 있다. 선분은 양 끝점의 x, y 좌표로 표현이 된다.

두 선분이 서로 만나는 경우에, 두 선분은 같은 그룹에 속한다고 정의하며, 그룹의 크기는 그 그룹에 속한 선분의 개수로 정의한다. 
두 선분이 만난다는 것은 선분의 끝점을 스치듯이 만나는 경우도 포함하는 것으로 한다.

N개의 선분들이 주어졌을 때, 이 선분들은 총 몇 개의 그룹으로 되어 있을까? 또, 가장 크기가 큰 그룹에 속한 선분의 개수는 몇 개일까? 이 두 가지를 구하는 프로그램을 작성해 보자.



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

int N;
int parent[3001] = {};
pair<pair<int, int>, pair<int, int>> line[3001];

int find(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	int xParent = find(x);
	int yParent = find(y);
	parent[yParent] = xParent;
}

int ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	long long ret = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
	if (ret > 0)
		return 1;
	else if (ret == 0)
		return 0;
	else
		return -1;
}

bool cross_Line(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C, pair<long long, long long> D) {
	int abc = ccw(A, B, C);
	int abd = ccw(A, B, D);
	int cda = ccw(C, D, A);
	int cdb = ccw(C, D, B);
 
	if (abc * abd == 0 && cda * cdb == 0) {
		if (A > B)
			swap(A, B);
		if (C > D)
			swap(C, D);
		if (A > D || B < C)
			return false;
		else
			return true;
	}

	if (abc * abd <= 0 && cda * cdb <= 0)
		return true;
	else
		return false;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) 
		parent[i] = i;
	
	for (int i = 0; i < N; ++i) 
		scanf("%d %d %d %d", &line[i].first.first, &line[i].first.second, &line[i].second.first, &line[i].second.second);
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j)
				continue;
			int aParent = find(i);
			int bParent = find(j);
			if (aParent != bParent) {
				if (cross_Line(line[i].first, line[i].second, line[j].first, line[j].second) == true) {
					merge(i, j);
				}
			}
		}
	}

	int group_cnt[3001] = {};

	for (int i = 0; i < N; ++i) {
		group_cnt[parent[i]]++;
	}

	int ret = 0, cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (group_cnt[i] != 0) {
			cnt++;
			ret = max(ret, group_cnt[i]);
		}
	}

	printf("%d\n%d", cnt, ret);
	return 0;
}
