14888 연산자 끼워넣기
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 
연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.

우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.

예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 덧셈(+) 2개, 뺄셈(-) 1개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 60가지의 식을 만들 수 있다. 
예를 들어, 아래와 같은 식을 만들 수 있다.

1+2+3-4×5÷6
1÷2+3+4-5×6
1+2÷3×4-5+6
1÷2×3-4+5+6
식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는 C++14의 기준을 따른다. 
즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.

1+2+3-4×5÷6 = 1
1÷2+3+4-5×6 = 12
1+2÷3×4-5+6 = 5
1÷2×3-4+5+6 = 7
N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.



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

int N;
int cal_cnt[4], cal[12], arr[12];
int min_ret = 987654321, max_ret = -987654321;

void calculate() {
	int ret = arr[0];
	for (int i = 0; i < N - 1; i++) {
		if (cal[i] == 0)
			ret += arr[i + 1];
		else if (cal[i] == 1)
			ret -= arr[i + 1];
		else if (cal[i] == 2)
			ret *= arr[i + 1];
		else if (cal[i] == 3)
			ret /= arr[i + 1];
	}
	min_ret = min(min_ret, ret);
	max_ret = max(max_ret, ret);
}

void func(int idx) {
	if (idx == N - 1)
		calculate();
	for (int i = 0; i < 4; ++i) {
		if (cal_cnt[i] > 0) {
			cal_cnt[i]--;
			cal[idx] = i;
			func(idx + 1);
			cal_cnt[i]++;
			cal[idx] = -1;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) 
		scanf("%d", &arr[i]);
	for (int i = 0; i < 4; ++i)
		scanf("%d", &cal_cnt[i]);
	func(0);
	printf("%d\n%d", max_ret, min_ret);
}
