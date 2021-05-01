11021 A+B - 7
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

int main() {
	int T, A, B;

	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> A >> B;
		cout << "Case #" << i << ": " << A + B << endl;
	}
}
