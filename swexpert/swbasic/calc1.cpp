/*
문자열로 이루어진 계산식이 주어질 때, 이 계산식을 후위 표기식으로 바꾸어 계산하는 프로그램을 작성하시오.

예를 들어

“3+4+5+6+7”

라는 문자열로 된 계산식을 후위 표기식으로 바꾸면 다음과 같다.

"34+5+6+7+"

변환된 식을 계산하면 25를 얻을 수 있다.

문자열 계산식을 구성하는 연산자는 + 하나뿐이며 피연산자인 숫자는 0 ~ 9의 정수만 주어진다.

[입력]

각 테스트 케이스의 첫 번째 줄에는 문자열 계산식의 길이가 주어진다. 그 다음 줄에 문자열 계산식이 주어진다.

총 10개의 테스트 케이스가 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 답을 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{	
	for (int T = 0; T < 10; T++) {
		int n;
		int ans=0;
		string str;
		cin >> n;
		cin >> str;
		for (int i = 0; i < n; i++) {
			if (str[i] != '+') {
				ans += str[i] - '0';
			}
		}
		
		cout << "#" << T + 1 << " " << ans << endl;
	}
	return 0;
}