2533 사회망 서비스(SNS)
페이스북, 트위터, 카카오톡과 같은 사회망 서비스(SNS)가 널리 사용됨에 따라, 사회망을 통하여 사람들이 어떻게 새로운 아이디어를 받아들이게 되는가를 이해하는 문제가 중요해졌다. 
사회망에서 사람들의 친구 관계는 그래프로 표현할 수 있는데,  이 그래프에서 사람은 정점으로 표현되고, 
두 정점을 잇는 에지는 두 정점으로 표현되는 두 사람이 서로 친구 관계임을 표현한다. 

예를 들어, 철수와 영희, 철수와 만수, 영희와 순희가 서로 친구 관계라면 이를 표현하는 친구 관계 그래프는 다음과 같다. 

친구 관계 그래프를 이용하면 사회망 서비스에서 어떤 새로운 아이디어가 전파되는 과정을 이해하는데 도움을 줄 수 있다. 
어떤 새로운 아이디어를 먼저 받아들인 사람을 얼리 아답터(early adaptor)라고 하는데, 사회망 서비스에 속한 사람들은 얼리 아답터이거나 얼리 아답터가 아니다.
얼리 아답터가 아닌 사람들은 자신의 모든 친구들이 얼리 아답터일 때만 이 아이디어를 받아들인다. 

어떤 아이디어를 사회망 서비스에서 퍼뜨리고자 할 때, 가능한 한 최소의 수의 얼리 아답터를 확보하여 모든 사람이 이 아이디어를 받아들이게 하는  문제는 매우 중요하다. 

일반적인 그래프에서 이 문제를 푸는 것이 매우 어렵다는 것이 알려져 있기 때문에, 친구 관계 그래프가 트리인 경우, 
즉 모든 두 정점 사이에 이들을 잇는 경로가 존재하면서 사이클이 존재하지 않는 경우만 고려한다. 

예를 들어, 8명의 사람으로 이루어진 다음 친구 관계 트리를 생각해보자. 2, 3, 4번 노드가 표현하는 사람들이 얼리 아답터라면, 
얼리 아답터가 아닌 사람들은 자신의 모든 친구가 얼리 아답터이기 때문에 새로운 아이디어를 받아들인다.

친구 관계 트리가 주어졌을 때, 모든 개인이 새로운 아이디어를 수용하기 위하여 필요한 최소 얼리 어답터의 수를 구하는 프로그램을 작성하시오.



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

int N;
bool visited[1000001] = {};
vector<int> edge[1000001];
vector<int> tree[1000001];   // 단방향 트리
int cache[1000001][2];   // N번째 노드의 얼리 아답터 상태가 주어질 때 최소 얼리 아답터의 개수

void make_tree(int n){   // 단방향 트리 만들기
	visited[n] = true;
	for (int i = 0; i < edge[n].size(); ++i) {
		int next = edge[n][i];
		if (visited[next] == false) {
			tree[n].push_back(next);
			make_tree(next);
		}
	}
}

int Earlyadopter(int n, int state) {
	int& ret = cache[n][state];
	if (ret != -1)
		return ret;

	if (state == 0) {   // 자신이 얼리 아답터가 아니라면 친구들은 얼리 아답터야 함
		ret = 0;
		for (int i = 0; i < tree[n].size(); ++i) {
			int next = tree[n][i];
			ret += Earlyadopter(next, 1);
		}
	}
	else {   // 자신이 얼리 아답터라면 친구들은 얼리 아답터여도 되고 아니여도 됨
		ret = 1;
		for (int i = 0; i < tree[n].size(); ++i) {
			int next = tree[n][i];
			ret += min(Earlyadopter(next, 0), Earlyadopter(next, 1));
		}
	}
	return ret;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	make_tree(1);
	memset(cache, -1, sizeof(cache));
	printf("%d", min(Earlyadopter(1, 0), Earlyadopter(1, 1)));
	return 0;
}
