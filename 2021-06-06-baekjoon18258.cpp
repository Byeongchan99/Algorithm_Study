18258 큐 2
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.



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
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	int N, x;
	deque<int> q;
	
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string c;
		cin >> c;
		if (c == "push") {
			cin >> x;
			q.push_back(x);
		}
		else if (c == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if (c == "size") {
			cout << q.size() << "\n";
		}
		else if (c == "empty") {
			cout << q.empty() << "\n";
		}
		else if (c == "front") {
			if (!q.empty()) 
				cout << q.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (c == "back") {
			if (!q.empty())
				cout << q.back() << "\n";
			else
				cout << -1 << "\n";
		}
	}
}
