11653 소인수분해
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.



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
	int N, n = 2;
	scanf("%d", &N);

	while (N > 1) {
		if (N % n == 0) {
			printf("%d\n", n);
			N /= n;
		}
		else
			n++;
	}
}
