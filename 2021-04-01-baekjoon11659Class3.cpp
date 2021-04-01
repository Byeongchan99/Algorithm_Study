11659 구간 합 구하기 4
수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.



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

int N, M;
int num[100001] = {}, pnum[100001] = {};

int main() {
	pnum[0] = 0;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &num[i]);
		pnum[i] = pnum[i - 1] + num[i];
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", pnum[b] - pnum[a - 1]);
	}
}
