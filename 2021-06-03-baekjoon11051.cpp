11051 이항 계수 2
자연수N과 정수K가 주어졌을 때 이항 계수 (N K)를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.



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

int dp[1001][1001] = {};

int func(int n, int k) {
	int& ret = dp[n][k];

	if (k == 0 || n == k)
		return ret = 1;
	if (ret != -1)
		return ret;

	return ret = (func(n - 1, k) + func(n - 1, k - 1)) % 10007;
}

int main() {
	int N, K;
	memset(dp, -1, sizeof(dp));

	scanf("%d %d", &N, &K);
	printf("%d", func(N, K) % 10007);
}
