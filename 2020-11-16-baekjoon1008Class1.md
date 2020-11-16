1008번 A/B
두 정수 A와 B를 입력받은 다음, A/B를 출력하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	double A, B;
	scanf("%lf %lf", &A, &B);   // double 형태로 사용하기 위해 lf 사용
	printf("%.9lf", A / B);   // 소수점 9자리까지 
	return 0;
}
