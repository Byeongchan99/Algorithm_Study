1208 부분수열의 합 2
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include <numeric>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>   // greater<int>
#include <climits>   // 최댓값, 최솟값
#include <cmath>   // 수학 - min, max 등
#include <cassert>   // assert - 오류 검출용
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
using namespace std;

int N, S, n;
vector<int> arr, arrSum1, arrSum2;

int main() {
	int sum = 0;

	scanf("%d %d", &N, &S);

	int arrlen1 = (1 << (N / 2)), arrlen2 = (1 << (N - N / 2));   // 부분 수열의 개수
	arrSum1.resize(arrlen1);
	arrSum2.resize(arrlen2);

	for (int i = 0; i < N; ++i) {		
		scanf("%d", &n);
		arr.push_back(n);
	}
	for (int i = 0; i < arrlen1; ++i) {   // 비트마스킹으로 부분 수열의 합 계산
		for (int j = 0; j < N / 2; ++j)
			if (i & (1 << j))
				arrSum1[i] += arr[j];
	}
	for (int i = 0; i < arrlen2; ++i) {
		for (int j = 0; j < N - N / 2; ++j)
			if (i & (1 << j))
				arrSum2[i] += arr[j + N / 2];
	}

	sort(arrSum1.begin(), arrSum1.end());
	sort(arrSum2.begin(), arrSum2.end(), greater<int>());

	int start = 0, end = 0;
	long long ret = 0;

	while (start < arrlen1 && end < arrlen2) {
		if (arrSum1[start] + arrSum2[end] == S) {   //  합이 같으면
			long long cnt1 = 1, cnt2 = 1;
			start++;
			end++;
			while (start < arrlen1 && arrSum1[start] == arrSum1[start - 1]) {   // 같은 숫자 개수 세기
				cnt1++;
				start++;
			}
			while (end < arrlen2 && arrSum2[end] == arrSum2[end - 1]) {
				cnt2++;
				end++;
			}
			ret += cnt1 * cnt2;   // 경우의 수
		}
		else if (arrSum1[start] + arrSum2[end] < S)  
			start++;
		else if (arrSum1[start] + arrSum2[end] > S)
			end++;
	}
	if (S == 0)   // 0일 때 중복 1개 빼주기
		ret--;
	printf("%lld", ret);
}
