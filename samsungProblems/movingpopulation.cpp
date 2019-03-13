#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dir[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
const int MAX = 55;
bool visited[MAX][MAX] = { false, };
int buf[MAX][MAX];
int map[MAX][MAX];
void init();
bool issame();
int n;
int main()
{
	int L, R;
	queue<pair<int, int>> q;
	int cnt = 0;
	cin >> n >> L >> R;

	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			buf[i][j] = map[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			buf[i][j] = 0;
		}
	}

	while (1) {
		int N = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				queue<pair<int, int>> unions;
				int res;
				if (buf[i][j] == 0) {	
					int uni_sum = map[i][j];
					buf[i][j] = N;
					q.push({ i,j });
					unions.push({ i,j });
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						
						for (int k = 0; k < 4; k++) {
							int xx = x + dir[k][0];
							int yy = y + dir[k][1];
							if (map[xx][yy] != -1 && buf[xx][yy] == 0) {
								int num = abs(map[x][y] - map[xx][yy]);
								if (num >= L && num <= R) {		
									buf[xx][yy] = N;
									q.push({ xx,yy });
									unions.push({ xx,yy });
									uni_sum += map[xx][yy];
								}
							}
						}
					}
					
					res = uni_sum / unions.size();					
				}				
				while (!unions.empty()) {
					int x = unions.front().first;
					int y = unions.front().second;
					unions.pop();
					buf[x][y] = res;
				}
				N++;
			}
		}

		if (issame()) {
			break;
		}
		init();
		cnt++;
	}

	cout << cnt;
	return 0;
}
void init()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = buf[i][j];
			buf[i][j] = 0;
		}
	}
}
bool issame()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != buf[i][j]) {
				return false;
			}
		}
	}
	return true;
}
