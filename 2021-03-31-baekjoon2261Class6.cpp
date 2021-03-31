2261 가장 가까운 두 점
2차원 평면상에 n개의 점이 주어졌을 때, 이 점들 중 가장 가까운 두 점을 구하는 프로그램을 작성하시오.
  
  
  
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

int N;
vector<pair<int, int>> v;

int dist(int Ax, int Ay, int Bx, int By) {
	return (Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By);
}

int getMinDist(int start, int end) {
	int ret = 987654321;
	if (end - start <= 2) {
		for (int i = start; i < end; ++i) {
			for (int j = i + 1; j <= end; ++j)
				ret = min(ret, dist(v[i].first, v[i].second, v[j].first, v[j].second));
		}
	}
	else {
		int mid = (start + end) / 2;
		int left_ret = getMinDist(start, mid - 1);
		int right_ret = getMinDist(mid + 1, end);
		ret = min(left_ret, right_ret);

		vector<pair<int, int>> tmp;
		tmp.push_back({ v[mid].second, v[mid].first });

		for (int i = mid - 1; i >= start; --i) {
			if (dist(v[mid].first, 0, v[i].first, 0) >= ret)
				break;
			tmp.push_back({ v[i].second, v[i].first });
		}

		for (int i = mid + 1; i <= end; ++i) {
			if (dist(v[mid].first, 0, v[i].first, 0) >= ret)
				break;
			tmp.push_back({ v[i].second, v[i].first });
		}
		sort(tmp.begin(), tmp.end());

		for (int i = 0; i < tmp.size() - 1; ++i) {
			for (int j = i + 1; j < tmp.size(); ++j) {
				if (dist(tmp[i].first, 0, tmp[j].first, 0) >= ret)
					break;
				ret = min(ret, dist(tmp[i].first, tmp[i].second, tmp[j].first, tmp[j].second));
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	printf("%d", getMinDist(0, N - 1));
}
