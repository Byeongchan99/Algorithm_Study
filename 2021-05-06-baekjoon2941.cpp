2941 크로아티아 알파벳
예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 다음과 같이 크로아티아 알파벳을 변경해서 입력했다.

크로아티아 알파벳	변경
č	c=
ć	c-
dž	dz=
đ	d-
lj	lj
nj	nj
š	s=
ž	z=
예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 이루어져 있다. 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

dž는 무조건 하나의 알파벳으로 쓰이고, d와 ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.



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

string str;

int func(int idx) {
	if (idx == str.length() - 1)
		return 0;
	if (str[idx] == 'c') {
		if (str[idx + 1] == '=')
			return 1;
		else if (str[idx + 1] == '-')
			return 1;
		else
			return 0;
	}
	else if (str[idx] == 'd') {
		if (str[idx + 1] == 'z' && str[idx + 2] == '=')
			return 2;
		else if (str[idx + 1] == '-')
			return 1;
		else
			return 0;
	}
	else if (str[idx] == 'l') {
		if (str[idx + 1] == 'j')
			return 1;
		else
			return 0;
	}
	else if (str[idx] == 'n') {
		if (str[idx + 1] == 'j')
			return 1;
		else
			return 0;
	}
	else if (str[idx] == 's') {
		if (str[idx + 1] == '=')
			return 1;
		else
			return 0;
	}
	else if (str[idx] == 'z') {
		if (str[idx + 1] == '=')
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

int main() {
	int ret = 0;
	cin >> str;
	for (int i = 0; i < str.length(); ++i) {
		int n = func(i);
		if (n > 0) {
			i += n;
			ret++;
		}
		else
			ret++;
	}
	printf("%d", ret);
}
