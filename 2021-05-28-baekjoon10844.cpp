
이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)



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

int N, ret = 0;
int dp[2][12] = {};

int main() {
	scanf("%d", &N);
	for (int i = 2; i < 11; ++i) 
		dp[1][i] = 1;

	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j < 11; ++j) {
			dp[i % 2][j] = (dp[(i - 1) % 2][j - 1] + dp[(i - 1) % 2][j + 1]) % 1000000000;
			if (i == N)
				ret = (ret + dp[N % 2][j]) % 1000000000;
		}
	}
	if (N == 1)
		printf("9");
	else
		printf("%d", ret);
}
