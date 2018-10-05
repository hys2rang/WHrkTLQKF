/*
문자열로 이루어진 계산식이 주어질 때, 이 계산식을 후위 표기식으로 바꾸어 계산하는 프로그램을 작성하시오.

예를 들어

“3+(4+5)*6+7”

라는 문자열로 된 계산식을 후위 표기식으로 바꾸면 다음과 같다.

"345+6*+7+"

변환된 식을 계산하면 64를 얻을 수 있다.

문자열 계산식을 구성하는 연산자는 +, * 두 종류이며 문자열 중간에 괄호가 들어갈 수 있다.

이 때 괄호의 유효성 여부는 항상 옳은 경우만 주어진다.

피연산자인 숫자는 0 ~ 9의 정수만 주어진다.

[입력]

각 테스트 케이스의 첫 번째 줄에는 테스트 케이스의 길이가 주어진다. 그 다음 줄에 바로 테스트 케이스가 주어진다.

총 10개의 테스트 케이스가 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 답을 출력한다.
*/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int priority(char c);
int main()
{
	for (int T = 0; T < 10; T++) {
		stack<char> stk;
		stack<int> calc;
		vector<char> arr;
		int n;
		int ans = 0;
		string str;
		cin >> n;
		cin >> str;
		for (int i = 0; i < n; i++) {
			if (str[i] != '+' && str[i] != '*' && str[i] != '(' && str[i] != ')') {
				arr.push_back(str[i]);
			}
			else {
				if (stk.empty()) {
					stk.push(str[i]);
				}
				else {
					switch (str[i]) {
					case '+':
						while (!stk.empty() && stk.top() != '(') {
							arr.push_back(stk.top());
							stk.pop();
						}
						stk.push(str[i]);
						break;
					case '*':
						if (priority(stk.top()) == priority('*')) {
							arr.push_back(stk.top());
							stk.pop();
							stk.push('*');
						}
						else if (priority(stk.top()) > priority('*')) {
							stk.push('*');
						}
						else {
							stk.push('*');
						}
						break;
					case '(':
						stk.push(str[i]);
						break;
					case ')':
						while (stk.top() != '(') {
							arr.push_back(stk.top());
							stk.pop();
						}
						stk.pop();
						break;
					}
				}

			}
		}
		while (!stk.empty()) {
			arr.push_back(stk.top());
			stk.pop();
		}

		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] != '*' && arr[i] != '+') {
				calc.push(arr[i] - '0');
			}
			else if (arr[i] == '+') {
				int a = calc.top();
				calc.pop();
				int b = calc.top();
				calc.pop();
				b += a;
				calc.push(b);
			}
			else {
				int a = calc.top();
				calc.pop();
				int b = calc.top();
				calc.pop();
				b *= a;
				calc.push(b);

			}
		}

		cout << "#" << T + 1 << " "  <<calc.top()<< endl;
	}
	return 0;
}
int priority(char c)
{
	switch (c)
	{
	case '(':
	case ')':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '+':
		return 3;
		break;
	default:
		return 0;
	}
}
