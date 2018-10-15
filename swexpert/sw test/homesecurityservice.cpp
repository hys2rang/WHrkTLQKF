/*
N*N 크기의 도시에 홈방범 서비스를 제공하려고 한다.

홈방범 서비스는 운영 상의 이유로 [Fig. 1]의 파란색 부분과 같이 마름모 모양의 영역에서만 제공된다.

[Fig. 1]

또한, 홈방범 서비스를 제공하기 위해서는 운영 비용이 필요하다.

[Fig. 2]와 같이 서비스 영역의 크기 K 가 커질수록 운영 비용이 커진다.

운영 비용은 서비스 영역의 면적과 동일하며, 아래와 같이 구할 수 있다.

운영 비용 = K * K + (K - 1) * (K - 1)

운영 영역의 크기 K 는 1 이상의 정수이다.

 - K = 1 일 때, 운영 비용은 1 이다.

 - K = 2 일 때, 운영 비용은 5 이다.

 - K = 3 일 때, 운영 비용은 13 이다.

 - K = 4 일 때, 운영 비용은 25 이다. 

[Fig. 2]

[Fig. 3]과 같이 도시를 벗어난 영역에 서비스를 제공해도 운영 비용은 변경되지 않는다.

[Fig. 3]의 경우 K = 3 이므로, 운영 비용은 13 이다. 

 [Fig. 3]

홈방범 서비스를 제공받는 집들은 각각 M의 비용을 지불할 수 있어, 보안회사에서는 손해를 보지 않는 한 최대한 많은 집에 홈방범 서비스를 제공하려고 한다.

도시의 크기 N과 하나의 집이 지불할 수 있는 비용 M, 도시의 정보가 주어진다.

이때, 손해를 보지 않으면서 홈방범 서비스를 가장 많은 집들에 제공하는 서비스 영역을 찾고,

그 때의 홈방범 서비스를 제공 받는 집들의 수를 출력하는 프로그램을 작성하라.


[예시]

예를 들어, [Fig. 4]과 같이 N이 8인 도시의 정보가 주어지고, 하나의 집이 지불할 수 있는 비용 M이 3이라고 생각해 보자.

 

[Fig. 4]


[Fig. 5]와 같이 서비스 영역 K = 2로 하여 홈방범 서비스를 제공할 때는 최대 3개의 집까지 서비스 제공이 가능하다.

이 경우 보안회사의 이익은 4가 되어 손해를 보지 않고 서비스 제공이 가능하다.

보안회사의 이익(4) = 서비스 제공받는 집들을 통해 얻는 수익(3*3) - 운영 비용(5)

 

[Fig. 5]


[Fig. 6]은 서비스 영역 K = 3으로 하여 홈방범 서비스를 제공할 때에 최대 5개의 집까지 서비스 제공이 가능한 경우 중 하나이다.

보안회사의 이익(2) = 서비스 제공받는 집들을 통해 얻는 수익(3*5) - 운영 비용(13)
 

[Fig. 6]


위의 예에서, 보안회사가 손해를 보지 않고 서비스 가능한 최대 집의 수는 5이며, 5가 정답이 된다.


[제약사항]

1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 3초

2. 도시의 크기 N은 5 이상 20 이하의 정수이다. (5 ≤ N ≤ 20)

3. 하나의 집이 지불할 수 있는 비용 M은 1 이상 10 이하의 정수이다. (1 ≤ M ≤ 10)

4. 홈방범 서비스의 운영 비용은 서비스 영역의 면적과 동일하다.

5. 도시의 정보에서 집이 있는 위치는 1이고, 나머지는 0이다.

6. 도시에는 최소 1개 이상의 집이 존재한다.


[입력]

입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 도시의 크기 N과 하나의 집이 지불할 수 있는 비용 M이 주어진다.

그 다음 줄부터 N*N 크기의 도시정보가 주어진다. 지도에서 1은 집이 위치한 곳이고, 나머지는 0이다.


[출력]

테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.

각 줄은 "#x"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)

출력해야 할 정답은 손해를 보지 않으면서 홈방범 서비스를 가장 많은 집들에 제공하는 서비스 영역을 찾았을 때,

그 때의 서비스를 제공 받는 집들의 수이다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 30;
int map[MAX][MAX] = { 0,0, };
int mask[MAX][MAX] = { 0,0, };
int n, m;
void DFS(int x, int y, int depth);
void mark(int x, int y, int depth);
void initialize();
int gethouses();
bool is_full();
int res = -10;
int main()
{
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		res = -10;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				DFS(i, j, 1);
			}
		}
		cout << "#" << tc + 1 << " " << res << endl;
	}

	return 0;
}
void DFS(int x, int y, int depth)
{
	int cnt = 0;
	initialize();
	mark(x, y, depth);
	cnt = gethouses();
	if (m*cnt - (depth*depth + ((depth - 1)*(depth - 1))) >= 0) {
		res = max(res, cnt);
	}
	if (is_full()) {
		return;
	}
	else {
		DFS(x, y, depth + 1);
	}

}
bool is_full()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!mask[i][j]) {
				return false;
			}
		}
	}
	return true;
}
int gethouses()
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mask[i][j] & map[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}
void mark(int x, int y, int depth)
{
	for (int i = 0; i < depth; i++) {
		for (int j = 0; j < depth - i; j++) {
			if (y - i >= 0 && y - i < n) {
				if (x - j >= 0 && x - j < n) {
					mask[x - j][y - i] = 1;
				}
				if (x + j >= 0 && x + j < n) {
					mask[x + j][y - i] = 1;
				}
			}
		}
	}
	for (int i = 1; i < depth; i++) {
		for (int j = 0; j < depth - i; j++) {
			if (y + i >= 0 && y + i < n) {
				if (x + j >= 0 && x + j < n) {
					mask[x + j][y + i] = 1;
				}
				if (x - j >= 0 && x - j < n) {
					mask[x - j][y + i] = 1;
				}
			}
		}
	}
}
void initialize()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mask[i][j] = 0;
		}
	}
}
