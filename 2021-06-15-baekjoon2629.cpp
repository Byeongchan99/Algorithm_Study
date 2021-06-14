2629 양팔저울
양팔 저울과 몇 개의 추가 주어졌을 때, 이를 이용하여 입력으로 주어진 구슬의 무게를 확인할 수 있는지를 결정하려고 한다.

무게가 각각 1g과 4g인 두 개의 추가 있을 경우, 주어진 구슬과 1g 추 하나를 양팔 저울의 양쪽에 각각 올려놓아 수평을 이루면 구슬의 무게는 1g이다. 
또 다른 구슬이 4g인지를 확인하려면 1g 추 대신 4g 추를 올려놓으면 된다.

구슬이 3g인 경우 아래 <그림 1>과 같이 구슬과 추를 올려놓으면 양팔 저울이 수평을 이루게 된다. 따라서 각각 1g과 4g인 추가 하나씩 있을 경우 주어진 구슬이 3g인지도 확인해 볼 수 있다.

<그림 2>와 같은 방법을 사용하면 구슬이 5g인지도 확인할 수 있다. 구슬이 2g이면 주어진 추를 가지고는 확인할 수 없다.

추들의 무게와 확인할 구슬들의 무게가 입력되었을 때, 주어진 추만을 사용하여 구슬의 무게를 확인 할 수 있는지를 결정하는 프로그램을 작성하시오.



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

int N, M;
int weight[31] = {}, marble[7] = {};
int dp[31][15001] = {};   // dp[i][j] : i - 1번째 구슬까지를 사용하여 만들 수 있는 무게 j

void func(int idx, int w) {
	if (idx > N)
		return;
	int& ret = dp[idx][w];
	if (ret != -1)
		return;
	dp[idx][w] = 1;
	func(idx + 1, w + weight[idx]);   // 구슬 없는 쪽에 추 추가
	func(idx + 1, w);   // 구슬 안 올림
	func(idx + 1, w - weight[idx]);   // 구슬 쪽에 추 추가
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &weight[i]);
	}

	func(0, 0);

	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d", &marble[i]);
		if (marble[i] > 15000)
			printf("N ");
		else if (dp[N][marble[i]] == 1)
			printf("Y ");
		else
			printf("N ");
	}
}
