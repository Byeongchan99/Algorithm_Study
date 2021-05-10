2581 소수
자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.

예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최솟값은 61이 된다.



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
	int M, N;
	bool isPrime[10001] = {};
	scanf("%d\n%d", &M, &N);
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int n = sqrt(N);
	for (int i = 2; i <= n; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j <= N; j += i)
				isPrime[j] = false;
		}
	}
	int sum = 0, ret = 10001;
	for (int i = M; i <= N; ++i) {
		if (isPrime[i]) {
			ret = min(ret, i);
			sum += i;
		}
	}
	if (sum = 0)
		printf("-1");
	else
		printf("%d\n%d", sum, ret);
}
