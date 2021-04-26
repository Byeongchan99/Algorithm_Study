11689 GCD(n, k) = 1
자연수 n이 주어졌을 때, GCD(n, k) = 1을 만족하는 자연수 1 ≤ k ≤ n 의 개수를 구하는 프로그램을 작성하시오.



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

long long n;

int main() {
	long long ret;
	scanf("%lld", &n);
	ret = n;

	for (long long i = 2; i * i <= n; ++i) {   // 오일러 파이 함수 구현
		if (n % i == 0) {
			ret -= ret / i;
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		ret -= ret / n;
	printf("%lld", ret);
}
