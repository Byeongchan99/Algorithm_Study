12015 가장 긴 증가하는 부분 수열 2
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.



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
int cache[1000001];   // cache[idx] = 부분 수열의 가장 오른쪽 수
vector<int> arr;

int Lower_bound(int start, int end, int e) {
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (cache[mid] < e)
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}

int LIS(int idx) {
	cache[idx] = arr[idx];

	for (int i = 1; i < N; ++i) {
		if (cache[idx] < arr[i]) 
			cache[++idx] = arr[i];
		else {
			int idx2 = Lower_bound(0, idx, arr[i]);
			cache[idx2] = arr[i];
		}
	}
	return idx + 1;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int n;
		scanf("%d", &n);
		arr.push_back(n);
	}
	int len = LIS(0);
	printf("%d", len);
}
