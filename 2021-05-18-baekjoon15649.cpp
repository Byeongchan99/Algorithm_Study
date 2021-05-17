15649 N과 M (1)
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열



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

int N, M, arr[9] = {};
bool visited[9] = {};

void func(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; ++i)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			arr[cnt] = i;
			visited[i] = true;
			func(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	func(0);
}
