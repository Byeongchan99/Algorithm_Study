2357 최솟값과 최댓값
N(1 ≤ N ≤ 100,000)개의 정수들이 있을 때, a번째 정수부터 b번째 정수까지 중에서 제일 작은 정수, 또는 제일 큰 정수를 찾는 것은 어려운 일이 아니다. 
하지만 이와 같은 a, b의 쌍이 M(1 ≤ M ≤ 100,000)개 주어졌을 때는 어려운 문제가 된다. 이 문제를 해결해 보자.

여기서 a번째라는 것은 입력되는 순서로 a번째라는 이야기이다. 예를 들어 a=1, b=3이라면 입력된 순서대로 1번, 2번, 3번 정수 중에서 최소, 최댓값을 찾아야 한다. 
각각의 정수들은 1이상 1,000,000,000이하의 값을 갖는다.
  
  
 
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

int N, M, a, b;
long long MAX = LLONG_MAX;
vector<pair<long long, long long>> tree, arr;

void make_tree(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	make_tree(node * 2, start, mid);
	make_tree(node * 2 + 1, mid + 1, end);
	tree[node].first = min(tree[2 * node].first, tree[2 * node + 1].first);
	tree[node].second = max(tree[2 * node].second, tree[2 * node + 1].second);
	return;
}

pair<long long, long long> find(int node, int start, int end, int left, int right) {
	if (start > right || end < left)
		return { MAX,0 };
	if (start >= left && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	pair<long long, long long> l, r;
	l = find(node * 2, start, mid, left, right);
	r = find(node * 2 + 1, mid + 1, end, left, right);
	return { min(l.first, r.first), max(l.second, r.second) };
}

int main() {
	scanf("%d %d", &N, &M);

	tree.resize(4 * N);
	for (int i = 0; i < N; ++i) {
		long long n;
		scanf("%lld", &n);
		arr.push_back({ n,n });
	}

	make_tree(1, 0, N - 1);

	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);
		pair<long long, long long> ret = find(1, 0, N - 1, a - 1, b - 1);
		printf("%lld %lld\n", ret.first, ret.second);
	}
} 
