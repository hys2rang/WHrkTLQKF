#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[12][12] = { -10,-10, };
bool visited[12][12] = { false,false };
void initialize(int n);
void clear_visited(int n);
void DFS(int x, int y, int depth);
int ans = 0;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//상하좌우
int main()
{
	int T;
	freopen("a.txt", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		vector<pair<int, int>> max_pos;
		pair<int, int> pos;
		ans = 0;
		int m = -10;
		int N, k;
		cin >> N >> k;

		initialize(N);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
				m = max(m, map[i][j]);
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == m) {
					pos = make_pair(i, j);
					max_pos.push_back(pos);
				}
			}
		}

		for (int depth = 0; depth <= k; depth++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					map[i][j] -= depth;
					for (int p = 0; p < max_pos.size(); p++) {
						DFS(max_pos[p].first, max_pos[p].second,1);
						clear_visited(N);
					}
					map[i][j] +=depth;
				}
			}
		}
		
		cout << "#" << tc + 1 << " " << ans << endl;
	}
	return 0;
}

void DFS(int x, int y,int depth)
{
	visited[x][y] = true;
	ans = max(ans, depth);
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (map[xx][yy] != -10 && (map[xx][yy] < map[x][y]) && !visited[xx][yy]) {
			DFS(xx, yy,depth+1);
			visited[xx][yy] = false;
		}
	}
}
void initialize(int n)
{
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			map[i][j] = -10;
			visited[i][j] = false;
		}
	}
}
void clear_visited(int n) 
{
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			visited[i][j] = false;
		}
	}
}
