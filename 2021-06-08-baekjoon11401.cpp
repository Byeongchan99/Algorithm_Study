11401 이항 계수 3
자연수N과 정수K가 주어졌을 때 이항 계수(N K)를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.



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

long long N, K, P = 1000000007;
long long fac[4000001] = {};

long long pow(long long a, long long b) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		long long n = pow(a, b / 2);
		return (n * n) % P;
	}
	else {
		long long n = pow(a, (b - 1) / 2);
		return ((n * n) % P * a) % P;
	}
}

int main() {
	scanf("%lld %lld", &N, &K);
	fac[0] = 1;
	for (int i = 1; i <= N; ++i)
		fac[i] = (fac[i - 1] * i) % P;
	
	long long n = (fac[K] * fac[N - K]) % P;
	n = pow(n, P - 2) % P;
	long long ret = (fac[N] * n) % P;
	printf("%lld", ret);
}
