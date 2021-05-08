10757 큰 수 A+B
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include <numeric>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>   // 최댓값, 최솟값
#include <cmath>   // 수학 - min, max 등
#include <cassert>   // assert - 오류 검출용
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
using namespace std;

string A, B;
int a[10002] = {}, b[10002] = {}, ret[10002] = {};

int main() {
	cin >> A >> B;
	if (A.length() < B.length())
		swap(A, B);
	for (int i = 0; i < A.length(); ++i) 
		a[i + 1] = A[i] - '0';
	for (int i = 0; i < B.length(); ++i)
		b[i + 1 + A.length() - B.length()] = B[i] - '0';
	int len = max(A.length(), B.length());
	for (int i = len; i >= 0; --i) {
		int sum = a[i] + b[i];
		if (sum >= 10) {
			a[i - 1]++;
			sum -= 10;
		}
		ret[i] += sum;
	}
	for (int i = 0; i <= len; ++i) {
		if (i == 0 && ret[i] == 0)
			continue;
		printf("%d", ret[i]);
	}
}
