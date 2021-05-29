1912 연속합
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.



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

int n, arr[100001] = {}, dp[100001] = {};   // dp[idx] = idx까지의 최대합

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	dp[0] = arr[0];
	int ret = dp[0];
	for (int i = 1; i < n; ++i) {
		if (dp[i - 1] < 0) {
			dp[i] = arr[i];
			ret = max(ret, dp[i]);
		}
		else {
			dp[i] = arr[i] + dp[i - 1];
			ret = max(ret, dp[i]);
		}
	}
	printf("%d", ret);
}
