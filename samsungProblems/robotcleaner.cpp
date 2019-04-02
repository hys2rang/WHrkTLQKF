#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 60;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//북,동,남,서
int map[MAX][MAX] = { 0, };
int visited[MAX][MAX] = { 0, };
int N, M, D,R,C;
void BFS();
int main()
{
	int cnt = 0;
	cin >> N >> M >> R >> C >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	BFS();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j] && visited[i][j]) {
				cnt++;
			}
		}
	}

	cout<<cnt;
	return 0;
}
void BFS()
{
	queue<pair<int, int>> q;
	visited[R][C] = D+1;
	q.push({ R,C });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int d = visited[x][y] - 1;
		q.pop();

		for (int i = 0; i < 4; i++) {
			d--;
			if (d < 0) {
				d = 3;
			}
			int xx = x + dir[d % 4][0];
			int yy = y + dir[d % 4][1];
			if (!visited[xx][yy] && !map[xx][yy]) {
				q.push({ xx,yy });
				visited[xx][yy] = (d % 4) + 1;
				break;
			}
		}

		if (q.empty()) {
			int xx = x - dir[d % 4][0];
			int yy = y - dir[d % 4][1];
			if (map[xx][yy] != 1) {
				q.push({ xx,yy });
				visited[xx][yy] = (d % 4) + 1;
			}
			else {
				return;
			}
		}		
	}
}
