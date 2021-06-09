2110 공유기 설치
도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.

도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 
최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에, 한 집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.

C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.



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

int N, C;
vector<int> house;

int calculate(int n) {
	int cnt = 1, tmp = house[0];
	
	for (int i = 1; i < N; ++i) {
		if (house[i] - tmp >= n) {
			cnt++;
			tmp = house[i];
		}
	}
	return cnt;
}

int main() {
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; ++i) {
		int n;
		scanf("%d", &n);
		house.push_back(n);
	}
	sort(house.begin(), house.end());

	int start = 1, end = house[N - 1], ret = 0;

	while (start <= end) {
		int mid = (start + end) / 2, cnt;
		cnt = calculate(mid);

		if (cnt >= C) {
			ret = max(ret, mid);
			start = mid + 1;
		}
		else 
			end = mid - 1;	
	}
	printf("%d", ret);
}
