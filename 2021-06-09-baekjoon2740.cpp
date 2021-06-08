2740 행렬 곱셈
N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.



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
	int N, M, K;
	int matrix1[101][101], matrix2[101][101], ret[101][101] = {};

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			scanf("%d", &matrix1[i][j]);
	}

	scanf("%d %d", &M, &K);
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < K; ++j)
			scanf("%d", &matrix2[i][j]);
	}

	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < K; ++k) {
			for (int j = 0; j < M; ++j) {
				ret[i][k] += matrix1[i][j] * matrix2[j][k];
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < K; ++k)
			printf("%d ", ret[i][k]);
		printf("\n");
	}
}
