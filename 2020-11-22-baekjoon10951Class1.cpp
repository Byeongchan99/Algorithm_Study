10951번 A+B - 4
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오. 



#define _CRT_SECURE_NO_WARNINGS
#include<numeric>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	int a, b;
	
	while (scanf("%d %d", &a, &b) != EOF) {   // 프로그램에서 파일의 끝을 만났음을 알리기 위해 매크로로 정의된 EOF 값을 리턴
		cout << a + b << endl;
	}
	
	/*
	while (cin >> a >> b)   // 이 형태도 가능
		cout << a + b << endl;
	*/ 
}
