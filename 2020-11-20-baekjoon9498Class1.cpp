9498번 시험 성적
시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	if (n >= 90 && n <= 100)
		printf("A");
	else if (n >= 80 && n <= 89)
		printf("B");
	else if (n >= 70 && n <= 79)
		printf("C");
	else if (n >= 60 && n <= 69)
		printf("D");
	else
		printf("F");
}
