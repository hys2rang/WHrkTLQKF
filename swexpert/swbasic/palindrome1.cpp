/*
"기러기" 또는 "level" 과 같이 거꾸로 읽어도 앞에서부터 읽은 것과 같은 문장이나 낱말을 회문(回文, palindrome)이라 한다.

주어진 8x8 평면 글자판에서 가로, 세로를 모두 보아 제시된 길이를 가진 회문의 총 개수를 구하는 문제이다.

위와 같은 글자판이 주어졌을 때, 길이가 5인 회문은 붉은색 테두리로 표시된 4개가 있으며 따라서 4를 반환하면 된다.


[제약 사항]

각 칸의 들어가는 글자는 c언어 char type으로 주어지며 'A', 'B', 'C' 중 하나이다.

글자 판은 무조건 정사각형으로 주어진다.

ABA도 회문이며, ABBA도 회문이다. A또한 길이 1짜리 회문이다.

가로, 세로 각각에 대해서 직선으로만 판단한다.

즉, 아래 예에서 노란색 경로를 따라가면 길이 7짜리 회문이 되지만 직선이 아니기 때문에 인정되지 않는다.

[입력]

각 테스트 케이스의 첫 번째 줄에는 찾아야 하는 회문의 길이가 주어지며, 다음 줄에 테스트 케이스가 주어진다.

총 10개의 테스트 케이스가 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 찾은 회문의 개수를 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
const int MAX = 1010;
bool ispal_w(int start, int end, int cur, char str[MAX][MAX]);
bool ispal_h(int start, int end, int cur, char str[MAX][MAX]);
int main()
{
	int tc,n;

	for (int tc = 0; tc < 10; tc++) {
		int length;
		int cnt = 0;
		char str[MAX][MAX] = { "" };
		cin >> length;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {	
				cin >> str[i][j];
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (ispal_w(j, length + j-1,i,str)) {
					cnt++;
				}
			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (ispal_h(j, length + j-1,i,str)) {
					cnt++;
				}
			}
		}
		cout << "#" << tc + 1 << " " << cnt << endl;;
	}
	return 0;
}
bool ispal_w(int start, int end, int cur, char str[MAX][MAX])
{
	bool check = true;
	while (start < end) {
		if (str[cur][start] != str[cur][end]) {
			check = false;
			break;
		}
		start++;
		end--;
	}
	return check;
}
bool ispal_h(int start, int end, int cur, char str[MAX][MAX])
{
	bool check = true;
	while (start < end) {
		if (str[start][cur] != str[end][cur]) {
			check = false;
			break;
		}
		start++;
		end--;
	}
	return check;
}
