#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 20;

bool map[MAX][MAX] = { false, };
int N, M, D;
int ans = -MAX * MAX;
void DFS(int depth);
vector<pair<int, int>> archers;
void copy(bool arr1[MAX][MAX], bool arr2[MAX][MAX]);
bool isempty();
struct Enemy
{
	int x = -2;
	int y = M - 1;
	int dis = D;
};
int main()
{
	cin >> N >> M >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int n;
			cin >> n;
			map[i][j] = n;
		}
	}

	DFS(0);

	cout << ans;
	return 0;
}
void DFS(int depth)
{
	if (depth == 3) {
		int cnt = 0;
		bool buf[MAX][MAX] = { false, };
		copy(buf, map);
		while (!isempty()) {
			queue<Enemy> q;
			for (int i = 0; i < 3; i++) {
				Enemy enemy;
				for (int a = N - 1; a >= N-D; a--) {
					for (int b = 0; b < M; b++) {
						if (map[a][b]) {
							pair<int, int> now;
							now = archers[i];
							int dist = abs(now.first - a) + abs(now.second - b);
							if (dist < enemy.dis) {
								enemy.x = a;
								enemy.y = b;
								enemy.dis = dist;
							}
							else if (dist == enemy.dis) {
								if (enemy.y >= b) {
									enemy.x = a;
									enemy.y = b;
									enemy.dis = dist;
								}
							}
						}
					}
				}
				if (enemy.x >= 0) {
					q.push(enemy);
				}				
			}
			while (!q.empty()) {
				Enemy enemy = q.front();
				q.pop();
				int x = enemy.x;
				int y = enemy.y;
				if (map[x][y]) {
					map[x][y] = false;
					cnt++;
				}				
			}
			bool tmp[MAX][MAX] = { false, };
			for (int i = 1; i < N; i++) {
				for (int j = 0; j < M; j++) {
					tmp[i][j] = map[i - 1][j];
				}
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					map[i][j] = tmp[i][j];
				}
			}
		}
		ans = max(ans, cnt);
		copy(map, buf);
		return;
	}
	for (int i = depth; i < M; i++) {
		archers.push_back({ N,i });
		DFS(depth + 1);
		archers.pop_back();
	}
}
void copy(bool arr1[MAX][MAX], bool arr2[MAX][MAX])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}
bool isempty()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				return false;
			}
		}
	}
	return true;
}
