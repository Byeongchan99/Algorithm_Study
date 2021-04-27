2675번 문자열 반복
문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오. 
즉, 첫 번째 문자를 R번 반복하고, 두 번째 문자를 R번 반복하는 식으로 P를 만들면 된다. S에는 QR Code "alphanumeric" 문자만 들어있다.

QR Code "alphanumeric" 문자는 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: 이다.



#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

int main() {
	int T, R;
	char str[20] = { NULL };

	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		scanf("%d", &R);
		scanf("%s", str);
		for (int j = 0; j < strlen(str); ++j) {
			for (int k = 0; k < R; ++k)
				printf("%c", str[j]);
		}
		printf("\n");
	}
}
