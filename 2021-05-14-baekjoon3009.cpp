3009 네 번째 점
세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.



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
	int x, y;
	vector<int> X, Y;

	for (int i = 0; i < 3; ++i) {
		scanf("%d %d", &x, &y);
		X.push_back(x);
		Y.push_back(y);
	}
	if (X[0] == X[1])
		printf("%d ", X[2]);
	else if (X[0] == X[2])
		printf("%d ", X[1]);
	else
		printf("%d ", X[0]);
	if (Y[0] == Y[1])
		printf("%d ", Y[2]);
	else if (Y[0] == Y[2])
		printf("%d ", Y[1]);
	else
		printf("%d ", Y[0]);
}
