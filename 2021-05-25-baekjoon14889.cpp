14889 스타트와 링크
오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 축구는 평일 오후에 하고 의무 참석도 아니다. 축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 
이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.

BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. 
능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. 
Sij는 Sji와 다를 수도 있으며, i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.

N=4이고, S가 아래와 같은 경우를 살펴보자.

i\j	1	2	3	4
1	 	1	2	3
2	4	 	5	6
3	7	1	 	2
4	3	4	5	 
예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 능력치는 아래와 같다.

스타트 팀: S12 + S21 = 1 + 4 = 5
링크 팀: S34 + S43 = 2 + 5 = 7
1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.

스타트 팀: S13 + S31 = 2 + 7 = 9
링크 팀: S24 + S42 = 6 + 4 = 10
축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 
위의 예제와 같은 경우에는 1, 4번이 스타트 팀, 2, 3번 팀이 링크 팀에 속하면 스타트 팀의 능력치는 6, 링크 팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 최소이다.



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

int N, team_start, team_link, start_ret, link_ret, ret = 987654321;
int st[21][21], arr_start[21], arr_link[21];
bool choice[21];

void calculate() {
	team_link = (1 << N) - 1;
	team_link ^= team_start;

	int idx_start = 0, idx_link = 0;
	for (int i = 0; i < N; ++i) {
		if (team_start & (1 << i))
			arr_start[idx_start++] = i;
		if (team_link & (1 << i))
			arr_link[idx_link++] = i;
	}

	start_ret = 0, link_ret = 0;
	for (int i = 0; i < N / 2; ++i) {
		for (int j = i + 1; j < N / 2; ++j) {
			start_ret += st[arr_start[i]][arr_start[j]];
			start_ret += st[arr_start[j]][arr_start[i]];
			link_ret += st[arr_link[i]][arr_link[j]];
			link_ret += st[arr_link[j]][arr_link[i]];
		}
	}

	ret = min(ret, abs(start_ret - link_ret));
}

void func(int idx, int cnt) {
	if (cnt == N / 2) {
		calculate();
		return;
	}

	for (int i = idx; i < N; ++i) {
		if (!choice[i]) {
			team_start |= (1 << i);
			choice[i] = true;
			func(i, cnt + 1);
			team_start &= ~(1 << i);
			choice[i] = false;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) 
			scanf("%d", &st[i][j]);

	func(0, 0);
	printf("%d", ret);
}
