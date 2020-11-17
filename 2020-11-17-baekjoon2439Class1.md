2439번 별 찍기 - 2
첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

하지만, 오른쪽을 기준으로 정렬한 별(예제 참고)을 출력하시오.



#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - i - 1; ++j)
			printf(" ");	
		for (int k = 0; k < i + 1; ++k)
			printf("*");
		printf("\n");
	}
}
