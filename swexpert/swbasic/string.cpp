/*
주어지는 영어 문장에서 특정한 문자열의 개수를 반환하는 프로그램을 작성하여라.

Starteatingwellwiththeseeighttipsforhealthyeating,whichcoverthebasicsofahealthydietandgoodnutrition.

위 문장에서 ti 를 검색하면, 답은 4이다.

[제약 사항]

총 10개의 테스트 케이스가 주어진다.

문장의 길이는 1000자를 넘어가지 않는다.

한 문장에서 검색하는 문자열의 길이는 최대 10을 넘지 않는다.

한 문장에서는 하나의 문자열만 검색한다. 

[입력]

각 테스트 케이스의 첫 줄에는 테스트 케이스의 번호가 주어지고 그 다음 줄에는 찾을 문자열, 그 다음 줄에는 검색할 문장이 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스의 답을 출력한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
const int MAX = 1000;
int main()
{
	int tc,n;
	
	for (int tc = 0; tc < 10; tc++) {
		char str[MAX] = "";
		char buf[MAX] = "";
		int start = 0;
		int cnt = 0;
		char *p;
		cin >> n;
		scanf("%s\n", buf);
		scanf("%s\n", str);
		p = str;
		while (strstr(p, buf) != NULL) {
			cnt++;
			p = strstr(p, buf)+strlen(buf);
		}
		cout << "#" << n << " " << cnt << endl;
	}
	return 0;
}
