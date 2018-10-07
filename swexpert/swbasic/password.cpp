/*
평소에 잔머리가 발달하고 게으른 철수는 비밀번호를 기억하는 것이 너무 귀찮았습니다.

적어서 가지고 다니고 싶지만 누가 볼까봐 걱정입니다. 한가지 생각을 해냅니다.
 
0~9로 이루어진 번호 문자열에서 같은 번호로 붙어있는 쌍들을 소거하고 남은 번호를 비밀번호로 만드는 것입니다.

번호 쌍이 소거되고 소거된 번호 쌍의 좌우 번호가 같은 번호이면 또 소거 할 수 있습니다.

예를 들어 아래의 번호 열을 철수의 방법으로 소거하고 알아낸 비밀 번호입니다.
 
[입력]

10개의 테스트 케이스가 10줄에 걸쳐, 한 줄에 테스트 케이스 하나씩 제공된다.

각 테스트 케이스는 우선 문자열이 포함하는 문자의 총 수가 주어지고, 공백을 둔 다음 번호 문자열이 공백 없이 제공된다.

문자열은 0~9로 구성되며 문자열의 길이 N은 10≤N≤100이다. 비밀번호의 길이는 문자열의 길이보다 작다.
 
[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스에 대한 답(비밀번호)을 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{	
	for (int tc = 0; tc < 10; tc++) {
		int T;
		string str;
		vector<int> res;
		stack<int> stk;
		cin >> T;
		cin >> str;
		stk.push(str[0]-'0');
		for (int i = 1; i < T; i++) {
			if (stk.empty() || stk.top() != str[i]-'0') {
				stk.push(str[i] - '0');
			}
			else {
				stk.pop();
			}
		}
		while (!stk.empty()) {
			res.push_back(stk.top());
			stk.pop();
		}

		cout << "#" << tc + 1 << " ";
		for (int i = res.size() - 1; i >= 0; i--) {
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}
