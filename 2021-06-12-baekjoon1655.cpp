1655 가운데를 말해요
수빈이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다. 수빈이가 정수를 하나씩 외칠때마다 동생은 지금까지 수빈이가 말한 수 중에서 중간값을 말해야 한다. 
만약, 그동안 수빈이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.

예를 들어 수빈이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다. 
수빈이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.
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

int main() {
	int N, n;
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &n);
		if (pq1.size() == pq2.size()) 
			pq1.push(n);	
		else 
			pq2.push(n);

		if (!pq1.empty() && !pq2.empty()) {
			while (pq1.top() > pq2.top()) {
				int a = pq1.top(), b = pq2.top();
				pq1.pop();
				pq1.push(b);
				pq2.pop();
				pq2.push(a);
			}
		}
		printf("%d\n", pq1.top());
	}
}
