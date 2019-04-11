#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 20;
int dir[3][2] = { {0,1},{1,0},{1,1} };
int map[MAX][MAX];
int N;
int ans = 0;
void DFS(int x, int y, int d);
int main()
{
	cin >> N;

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			map[i][j] = -1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	DFS(1, 2, 0);
	cout << ans;
	return 0;
}
void DFS(int x, int y, int d)
{
	if (x == N && y == N) {
		ans++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (i + d==1) {
			continue;
		}
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (map[xx][yy]) {
			continue;
		}
		if (i == 2 && (map[xx - 1][yy] || map[xx][yy - 1])) {
			continue;
		}
		DFS(xx, yy, i);
	}
}
