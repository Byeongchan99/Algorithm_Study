2004 조합 0의 개수
(n m)의 끝자리 의 개수를 출력하는 프로그램을 작성하시오.



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

vector<pair<long long, long long>> zero_cnt;

void get_cnt(long long n) {
	long long  two = 0, five = 0;

	for (long long i = 2; i <= n; i *= 2) 
		two += n / i;
	for (long long i = 5; i <= n; i *= 5)
		five += n / i;

	zero_cnt.push_back({ two, five });
}

int main() {
	long long n, m;

	scanf("%lld %lld", &n, &m);

	get_cnt(n);
	get_cnt(m);
	get_cnt(n - m);

	printf("%lld", min(zero_cnt[0].first - zero_cnt[1].first - zero_cnt[2].first, zero_cnt[0].second - zero_cnt[1].second - zero_cnt[2].second));
}
