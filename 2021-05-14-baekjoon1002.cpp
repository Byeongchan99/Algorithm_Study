1002 터렛
조규현과 백승환은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 다음은 조규현과 백승환의 사진이다.

이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.

조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고, 조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 
류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.



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

int main() {
	long long T, x1, y1, r1, x2, y2, r2;
	scanf("%lld", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &r1, &x2, &y2, &r2);
		long long distance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		long long add = (r1 + r2) * (r1 + r2), sub = (r1 - r2) * (r1 - r2);

		if (r1 > r2) 
			swap(r1, r2);

		if (sub > distance)   // 포함
			printf("0\n");
		if (add < distance)   // 멀리 떨어져있음
			printf("0\n");
		if (add == distance)   // 외접
			printf("1\n");
		if (add > distance && sub < distance)   // 두 점에서 만남
			printf("2\n");
		if (sub == distance && distance != 0)   // 내접
			printf("1\n");
		if (distance == 0 && r1 == r2)   // 일치
			printf("-1\n");
	}
}
