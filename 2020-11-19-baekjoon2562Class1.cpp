2562번 최댓값
9개의 서로 다른 자연수가 주어질 때, 이들 중 최댓값을 찾고 그 최댓값이 몇 번째 수인지를 구하는 프로그램을 작성하시오.

예를 들어, 서로 다른 9개의 자연수

3, 29, 38, 12, 57, 74, 40, 85, 61

이 주어지면, 이들 중 최댓값은 85이고, 이 값은 8번째 수이다.



#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

int main() {
	int max = 0, ar[9] = { NULL }, j;
	for (int i = 0; i < 9; ++i) {
		scanf("%d", &ar[i]);
		if (ar[i] > max) {
			max = ar[i];
			j = i;
		}
	}
	printf("%d\n%d", ar[j], j + 1);
}
