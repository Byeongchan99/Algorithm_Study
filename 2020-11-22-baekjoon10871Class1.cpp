10871번 X보다 작은 수
정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include<numeric>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	int N, X, ar[10000], num, j = 0;

	scanf("%d %d", &N, &X);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &num);
		if (num < X) {
			ar[j] = num;
			j++;
		}
	}
	for (int i = 0; i < j; ++i)
		printf("%d ", ar[i]);
}
