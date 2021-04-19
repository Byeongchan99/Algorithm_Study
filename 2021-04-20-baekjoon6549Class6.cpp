6549 히스토그램에서 가장 큰 직사각형
히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다. 예를 들어, 왼쪽 그림은 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이다.

히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include <numeric>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>   // greater<int>
#include <climits>   // 최댓값, 최솟값
#include <cmath>   // 수학 - min, max 등
#include <cassert>   // assert - 오류 검출용
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
using namespace std;

vector<long long> height;

long long solve(int left, int right) {
	if (left == right)
		return height[left];
	int mid = (left + right) / 2;
	long long ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, hi = mid + 1;
	long long h = min(height[lo], height[hi]);
	ret = max(ret, h * 2);

	while (left < lo || hi < right) {
		if (hi < right && (lo == left || height[lo - 1] < height[hi + 1])) {
			++hi;
			h = min(h, height[hi]);
		}
		else {
			--lo;
			h = min(h, height[lo]);
		}
		ret = max(ret, (hi - lo + 1) * h);
	}
	return ret;
}

int main() {
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		height.clear();
		for (int i = 0; i < n; ++i) {
			long long h;
			scanf("%lld", &h);
			height.push_back(h);
		}
		printf("%lld\n", solve(0, n - 1));
	}
}
