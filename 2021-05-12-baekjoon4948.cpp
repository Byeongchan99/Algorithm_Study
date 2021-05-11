4948 베르트랑 공준
베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.

이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.

예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다. (11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)

자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오. 



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

bool isPrime[250000] = {};

int countPrime(int n) {
	int cnt = 0;
	for (int i = n + 1; i <= 2 * n; ++i) {
		if (isPrime[i])
			cnt++;
	}
	return cnt;
}

int getPrime(int n) {
	int sqrtn = sqrt(2 * n);
	for (int i = 2; i <= sqrtn; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 2 * n; j += i)
				isPrime[j] = false;
		}
	}
	return countPrime(n);
}

int main() {
	int n;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		printf("%d\n", getPrime(n));
	}
}
