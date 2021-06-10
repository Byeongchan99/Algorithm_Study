1300 K번째 수
세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다. 이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. 
B를 오름차순 정렬했을 때, B[k]를 구해보자.

배열 A와 B의 인덱스는 1부터 시작한다.



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

long long N, k;

int main() {
	scanf("%lld\n%lld", &N, &k);

	long long start = 1, end = N * N, ret;

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long cnt = 0;
		for (int i = 1; i <= N; ++i) 
			cnt += min(mid / i, N);
		
		if (cnt >= k) {
			ret = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	printf("%lld", ret);
}
