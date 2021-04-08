17387 선분 교차 2
2차원 좌표 평면 위의 두 선분 L1, L2가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자. 한 선분의 끝 점이 다른 선분이나 끝 점 위에 있는 것도 교차하는 것이다.

L1의 양 끝 점은 (x1, y1), (x2, y2), L2의 양 끝 점은 (x3, y3), (x4, y4)이다.



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

int ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	long long ret = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
	if (ret > 0)
		return 1;
	else if (ret == 0)
		return 0;
	else
		return -1;
}

int main() {
	pair<long long, long long> A;
	pair<long long, long long> B;
	pair<long long, long long> C;
	pair<long long, long long> D;
	scanf("%lld %lld %lld %lld", &A.first, &A.second, &B.first, &B.second);
	if (A > B)
		swap(A, B);
	scanf("%lld %lld %lld %lld", &C.first, &C.second, &D.first, &D.second);
	if (C > D)
		swap(C, D);

	int abc = ccw(A, B, C);
	int abd = ccw(A, B, D);
	int cda = ccw(C, D, A);
	int cdb = ccw(C, D, B);

	if (abc * abd == 0 && cda * cdb == 0) {
		if (A > D || B < C)
			printf("0");
		else
			printf("1");
		return 0;
	}

	if (abc * abd <= 0 && cda * cdb <= 0)
		printf("1");
	else
		printf("0");
	return 0;
}
