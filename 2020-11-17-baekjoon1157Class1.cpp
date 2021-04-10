1157번 단어 공부
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int cnt[26] = { NULL };
	int max = 0;
	char c;

	cin >> str;
	int len = str.length();

	for (int i = 0; i < len; ++i) {
		if (str[i] >= 'a' && str[i] <= 'z')   // 소문자면 대문자로 바꾸기
			str[i] -= 32; 
		cnt[(str[i] - 'A')]++;   // 개수 세기
	}

	for (int i = 0; i < 26; ++i) {   // 가장 많은 알파벳 개수 구하기
		if (max < cnt[i]) {
			max = cnt[i];
			c = 'A' + i;
		}
		else if (max == cnt[i])   // 같은 숫자가 나오면 ?
			c = '?';
	}

	printf("%c", c);
	return 0;
}
