17298 오큰수
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. 
Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.



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

int main() {
	int N;
	vector<int> arr, ret;
	stack<int> s;

	scanf("%d", &N);
	ret.resize(N);

	for (int i = 0; i < N; ++i) {
		int n;
		scanf("%d", &n);
		arr.push_back(n);
	}

	for (int i = N - 1; i >= 0; --i) {
		while (!s.empty() && s.top() <= arr[i])
			s.pop();
		if (s.empty()) {
			ret[i] = -1;
			s.push(arr[i]);
			continue;
		}
		ret[i] = s.top();
		s.push(arr[i]);
	}
	for (int i = 0; i < N; ++i)
		printf("%d ", ret[i]);
}
