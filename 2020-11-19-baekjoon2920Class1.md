2920번 상수
다장조는 c d e f g a b C, 총 8개 음으로 이루어져있다. 이 문제에서 8개 음은 다음과 같이 숫자로 바꾸어 표현한다. c는 1로, d는 2로, ..., C를 8로 바꾼다.

1부터 8까지 차례대로 연주한다면 ascending, 8부터 1까지 차례대로 연주한다면 descending, 둘 다 아니라면 mixed 이다.

연주한 순서가 주어졌을 때, 이것이 ascending인지, descending인지, 아니면 mixed인지 판별하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

int main() {
	int ar[9] = { NULL };
	bool ascending = true, descending = true;
	for (int i = 0; i < 8; ++i) {
		scanf("%d", &ar[i]);
		if (ar[i] != i + 1)
			ascending = false;
		if (ar[i] != 8 - i)
			descending = false;
	}
	if (ascending == true)
		printf("ascending");
	else if (descending == true)
		printf("descending");
	else
		printf("mixed");
}
