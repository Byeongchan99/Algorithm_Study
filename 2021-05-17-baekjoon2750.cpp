2750 수 정렬하기
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.



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
	int N;
	vector<int> arr;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int n;
		scanf("%d", &n);
		arr.push_back(n);
	}
	for (int i = 0; i < N; ++i) {   // 거품 정렬
		for (int j = 0; j < N; ++j) {		
			if (arr[i] < arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int i = 0; i < N; ++i) 
		printf("%d\n", arr[i]);
	
}
