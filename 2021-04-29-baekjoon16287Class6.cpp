16287 Parcel
국제대학소포센터(ICPC: International Collegiate Parcel Center)는 전세계 대학생들을 대상으로 소포 무료 배송 이벤트를 진행하고 있다. 
무료 배송 조건은 보낼 소포가 물품 4개로 구성되어야 하며 이들 물품의 무게 합이 정확히 정해진 정수 무게 w 그램이어야 한다는 것이다.

부산대학교에 있는 찬수는 영국 왕립대학에 있는 수환에게 보낼 물품이 매우 많이 있는데, 각 물품의 무게(모두 정수 그램)는 모두 다르다. 
이 이벤트는 한시적으로 진행되는 이벤트이기 때문에 찬수는 자신이 보낼 물품 중에서 이 조건을 만족하는 물품 4개가 있는지 가능하면 빨리 알아내고 싶다. 
다시 말해서 서로 다른 n(n ≥ 4)개의 정수로 이루어진 집합 A에서 4개의 원소만 꺼내어 만든 부분집합 B(|B| = 4)가 ∑b∈B b = w 조건을 만족하는지 판단하려고 한다. 

주어진 w와 A에 대해서, 위 조건을 만족하는 부분집합 B가 존재하면 YES를, 아니면 NO를 출력하는 프로그램을 작성하시오.



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

int w, n, a, tmp;
vector<int> arr;
bool cache[400001] = {};

int main() {
	scanf("%d %d", &w, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());   // 크기 순 정렬
	for (int i = 1; i < n - 2; ++i) {   // ( j ~ i 구간)에서 2개 + ( i + 1 ~ k 구간)에서 2개의 합이 w인지 확인
		for (int j = 0; j < i; ++j)
			cache[arr[i] + arr[j]] = true;
		for (int k = i + 2; k < n; ++k) {
			int tmp = w - arr[i + 1] - arr[k];
			if (tmp < 0)   // 뒷 구간의 합이 더 크면 불가능
				break;
			if (tmp <= 400000 && cache[tmp] == true) {   // 한 원소의 최댓값은 200000
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
}
