11444 피보나치 수 6
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.



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

long long n;

vector<vector<long long>> multi(vector<vector<long long>> matrix1, vector<vector<long long>> matrix2) {
	vector<vector<long long>> ret(2, vector<long long>(2));

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				ret[i][j] += matrix1[i][k] * matrix2[k][j];
			}
			ret[i][j] %= 1000000007;
		}
	}
	return ret;
}

vector<vector<long long>> pow(vector<vector<long long>> matrix, long long N) {
	vector<vector<long long>> ret(2, vector<long long>(2));

	for (int i = 0; i < 2; ++i)
		ret[i][i] = 1;

	while (N > 0) {
		if (N % 2 > 0) {
			ret = multi(ret, matrix);
		}
		N /= 2;
		matrix = multi(matrix, matrix);
	}
	return ret;
}

int main() {
	scanf("%lld", &n);
	vector<vector<long long>> ret = { {1,1},{1,0} };

	ret = pow(ret, n);
	printf("%lld", ret[1][0]);
	return 0;
}
