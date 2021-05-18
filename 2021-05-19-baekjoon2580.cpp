2580 스도쿠
스도쿠는 18세기 스위스 수학자가 만든 '라틴 사각형'이랑 퍼즐에서 유래한 것으로 현재 많은 인기를 누리고 있다. 
이 게임은 아래 그림과 같이 가로, 세로 각각 9개씩 총 81개의 작은 칸으로 이루어진 정사각형 판 위에서 이뤄지는데, 게임 시작 전 일부 칸에는 1부터 9까지의 숫자 중 하나가 쓰여 있다.

나머지 빈 칸을 채우는 방식은 다음과 같다.

각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
위의 예의 경우, 첫째 줄에는 1을 제외한 나머지 2부터 9까지의 숫자들이 이미 나타나 있으므로 첫째 줄 빈칸에는 1이 들어가야 한다.

또한 위쪽 가운데 위치한 3x3 정사각형의 경우에는 3을 제외한 나머지 숫자들이 이미 쓰여있으므로 가운데 빈 칸에는 3이 들어가야 한다.

이와 같이 빈 칸을 차례로 채워 가면 다음과 같은 최종 결과를 얻을 수 있다.

게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.



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

bool row[9][9], col[9][9], box[9][9];
int sudoku[9][9];

void func(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j)
				printf("%d ", sudoku[i][j]);
			printf("\n");
		}
		exit(0);
	}

	int i = cnt / 9;
	int j = cnt % 9;

	if (sudoku[i][j] == 0) {
		for (int c = 1; c <= 9; ++c) {
			if (!row[i][c] && !col[j][c] && !box[(i / 3) * 3 + (j / 3)][c]) {
				sudoku[i][j] = c;
				row[i][c] = col[j][c] = box[(i / 3) * 3 + (j / 3)][c] = true;
				func(cnt + 1);
				sudoku[i][j] = 0;
				row[i][c] = col[j][c] = box[(i / 3) * 3 + (j / 3)][c] = false;
			}
		}
	}
	else
		func(cnt + 1);
}

int main() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			scanf("%d", &sudoku[i][j]);
			if (sudoku[i][j] != 0) {
				row[i][sudoku[i][j]] = col[j][sudoku[i][j]] = box[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = true;
			}
		}
	}
	func(0);
}
