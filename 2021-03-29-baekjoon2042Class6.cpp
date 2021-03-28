2042 구간 합 구하기
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 
  만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 
  그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.
  
  
  
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

int N, M, K;
vector<long long> arr, tree;

long long make_tree(int node, int start, int end) {
	if (start == end)   // 리프 노드
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = make_tree(node * 2, start, mid) + make_tree(node * 2 + 1, mid + 1, end);
}

long long sum(int node, int start, int end, int left, int right) {
	if (start > right || end < left)
		return 0;
	if (start >= left && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void change(int node, int start, int end, int idx, long long dif) {
	if (start > idx || end < idx)
		return;
	tree[node] += dif;
	if (start != end) {
		int mid = (start + end) / 2;
		change(node * 2, start, mid, idx, dif);
		change(node * 2 + 1, mid + 1, end, idx, dif);
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	tree.resize(4 * N);
	for (int i = 0; i < N; ++i) {
		int n;
		scanf("%d", &n);
		arr.push_back(n);
	}

	make_tree(1, 0, N - 1);   // 세그먼트 트리 만들기

	for (int i = 0; i < M + K; ++i) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {   // 값 바꾸기
			long long dif = c - arr[b - 1];
			arr[b - 1] = c;
			change(1, 0, N - 1, b - 1, dif);
		}
		else if (a == 2) {   // 합 구하기
			printf("%lld\n", sum(1, 0, N - 1, b - 1, c - 1));
		}
	}
}
