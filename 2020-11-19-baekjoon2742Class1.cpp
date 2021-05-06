2742번 기찍 N
자연수 N이 주어졌을 때, N부터 1까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	for (int i = N; i >= 1; --i)
		printf("%d\n", i);
}
