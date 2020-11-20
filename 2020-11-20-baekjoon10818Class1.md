10818번 최소, 최대
N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int Min = 1000000, Max = -1000000;

int main() {
	int N, a;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &a);
		if (a > Max)
			Max = a;
		if (a < Min)
			Min = a;
	}
	printf("%d %d", Min, Max);
}
