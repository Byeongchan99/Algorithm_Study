4344 평균은 넘겠지
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.



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
	int C, N;
	vector<int> score;
	scanf("%d", &C);
	for (int c = 0; c < C; ++c) {
		score.clear();
		float sum = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			int n;
			scanf("%d", &n);
			sum += n;
			score.push_back(n);
		}
		sum /= N;
		float cnt = 0;
		for (int i = 0; i < N; ++i) {
			if (score[i] > sum)
				cnt++;
		}
		printf("%.3f%%\n", cnt / N * 100);
	}
}
