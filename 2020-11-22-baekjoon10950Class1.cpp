10950번 A+B - 3
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include<numeric>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}
