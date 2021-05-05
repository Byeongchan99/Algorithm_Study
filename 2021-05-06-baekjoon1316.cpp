1316 그룹 단어 체커
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 
예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.



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

int N, alphabet[27] = {};
string str;

int main() {
	int ret = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		bool isGroup = true;
		memset(alphabet, 0, sizeof(alphabet));
		cin >> str;
		for (int j = 0; j < str.length(); ++j) {
			if (alphabet[str[j] - 'a'] == 0)
				alphabet[str[j] - 'a']++;
			else if (str[j - 1] != str[j]) {
				isGroup = false;
				break;
			}
		}
		if (isGroup)
			ret++;
	}
	printf("%d", ret);
}
