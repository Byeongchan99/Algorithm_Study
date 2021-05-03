1065 한수
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 
N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 



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

int N;
bool hansu[1001] = {};

void func(int N) {
	if (N < 10) {
		hansu[N] = true;
		return;
	}

	int n = N, dif = (n % 10) - ((n / 10) % 10), a, b;
	while (n) {
		if (n < 10) 
			break;	
		a = n % 10;
		n /= 10;
		b = n % 10;
		if (a - b != dif) {
			hansu[N] = false;
			return;
		}
	}
	hansu[N] = true;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		func(i);
	}
	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		if (hansu[i])
			ret++;
	}
	printf("%d", ret);
}
