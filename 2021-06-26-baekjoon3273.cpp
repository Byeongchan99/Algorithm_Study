3273 두 수의 합
n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다. 
자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.



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
	int n, a, x;
	vector<int> arr;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	scanf("%d", &x);

	int start = 0, end = n - 1, cnt = 0;
	while (start < end) {
		if (arr[start] + arr[end] == x) {
			cnt++;
			start++;
		}
		else if (arr[start] + arr[end] < x)
			start++;
		else
			end--;
	}
	printf("%d", cnt);
}
