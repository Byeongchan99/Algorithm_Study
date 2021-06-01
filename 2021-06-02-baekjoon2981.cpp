2981 검문
트럭을 타고 이동하던 상근이는 경찰의 검문을 받게 되었다. 경찰은 상근이가 운반하던 화물을 하나하나 모두 확인할 것이기 때문에, 검문하는데 엄청나게 오랜 시간이 걸린다.

상근이는 시간을 때우기 위해서 수학 게임을 하기로 했다.

먼저 근처에 보이는 숫자 N개를 종이에 적는다. 그 다음, 종이에 적은 수를 M으로 나누었을 때, 나머지가 모두 같게 되는 M을 모두 찾으려고 한다. M은 1보다 커야 한다.

N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.



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

int GCD(int a, int b) {
	if (a % b == 0)
		return b;

	return GCD(b, a % b);
}

int main() {
	int N;
	vector<int> arr, ret;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int n;
		scanf("%d", &n);
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	int gcd = arr[1] - arr[0];
	for (int i = 2; i < N; ++i) 
		gcd = GCD(gcd, arr[i] - arr[i - 1]);
	
	for (int i = 2; i * i <= gcd; ++i) {
		if (gcd % i == 0) {
			ret.push_back(i);
			ret.push_back(gcd / i);
		}
	}
	ret.push_back(gcd);
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());

	for (int i = 0; i < ret.size(); ++i) 
		printf("%d ", ret[i]);
}
