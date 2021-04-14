2438번 별 찍기 - 1
첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
