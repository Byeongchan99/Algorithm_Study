1152번 단어의 개수
영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오. 
단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	int i, cnt = 0;
	
	for (i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && str[i + 1] == ' ')
			cnt++;
	}
	if (str[i - 1] != ' ')
		cout << cnt + 1;
	else
		cout << cnt;
	return 0;
}



C++ 에서 띄어쓰기를 포함한 문자열을 입력받을 수  getline 함수
