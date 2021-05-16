1427 소트인사이드
배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.



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
	string str;
	vector<int> arr;
	cin >> str;
	for (int i = 0; i < str.length(); ++i) 
		arr.push_back(str[i] - '0');
	sort(arr.begin(), arr.end(), greater<int>());
	for (int i = 0; i < str.length(); ++i)
		printf("%d", arr[i]);
}
