#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
const int MAX = 60;
struct Point {
	int y, x;
};
int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} }; //동북서남
int clkwise[2][4] = { {0,1,2,3},{0,3,2,1} };
int main()
{
	int r, c, T;
	int map[MAX][MAX] = { 0, };
	int pos = 0;
	int ans = 0;
	Point ac[2] = { {0,0},{0,0} };
	queue<Point> q;

	cin >> r >> c >> T;

	for (int i = 0; i <= r + 1; i++) {
		for (int j = 0; j <= c + 1; j++) {
			map[i][j] = -1;
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) {
				q.push({ i,j });
			}else if (map[i][j] == -1) {
				ac[pos++] = { i,j };
			}
		}
	}

	for (int t = 0; t < T; t++) {
		int spreadmap[MAX][MAX] = { 0, };
		int res[MAX][MAX] = { 0, };

		//미세먼지 확산
		while (!q.empty()) {
			Point cur = q.front();
			int quantity = map[cur.y][cur.x];
			q.pop();
			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int yy = cur.y + dir[d][0];
				int xx = cur.x + dir[d][1];
				if (map[yy][xx] != -1) {
					spreadmap[yy][xx] += quantity / 5;
					cnt++;
				}
			}
			spreadmap[cur.y][cur.x] += quantity - (quantity / 5) * cnt;
		}
		//공기청정기 순환
		for (int i = 0; i < 2; i++) {
			//시작점 : 공기청정기 바로 옆부터
			int cy = ac[i].y;
			int cx = ac[i].x + 1;
			for (int j = 0; j < 4;) {
				int ny = cy + dir[clkwise[i][j]][0];
				int nx = cx + dir[clkwise[i][j]][1];
				if (map[ny][nx] == -1) {
					j++;
					ny = cy + dir[clkwise[i][j]][0];
					nx = cx + dir[clkwise[i][j]][1];
					if (j == 4) {
						spreadmap[cy][cx] = 0;
						break;
					}
				}
				res[ny][nx] = spreadmap[cy][cx];
				spreadmap[cy][cx] = 0;
				cy = ny;
				cx = nx;
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				map[i][j] = spreadmap[i][j] + res[i][j];
				if (map[i][j] > 0) {
					q.push({ i,j });
				}
			}
		}

		map[ac[0].y][ac[0].x] = -1;
		map[ac[1].y][ac[1].x] = -1;
	}

	

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] > 0) {
				ans += map[i][j];
			}
		}
	}

	cout << ans;
}
