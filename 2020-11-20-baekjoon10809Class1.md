10809번 알파벳 찾기
알파벳 소문자로만 이루어진 단어 S가 주어진다. 
각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	char str[100];
	int alp[26];

	for (int i = 0; i < 26; ++i)
		alp[i] = -1;

	scanf("%s", str);
	int len = strlen(str);

	for (int i = 0; i < len; ++i) {
		if (alp[str[i] - 'a'] == -1)
			alp[str[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; ++i)
		printf("%d ", alp[i]);
}
