2293 동전 1
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그 경우의 수를 구하시오. 
각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.



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

int n, k;
int coin[101] = {}, dp[2][10001] = {};   // dp[i][k] = i 번째 코인까지 사용하여 k를 만들 수 있는 경우의 수 / 슬라이딩 윈도우 사용

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &coin[i]);
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (coin[i] > j)
				dp[i % 2][j] = dp[(i - 1) % 2][j];
			else
				dp[i % 2][j] = dp[i % 2][j - coin[i]] + dp[(i - 1) % 2][j];
		}
	}
	printf("%d", dp[n % 2][k]);
}
