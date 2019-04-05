#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 110;

int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { false, };
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
queue<pair<int, int>> tails;
int cx, cy, cd;
int tx, ty;//꼬리 위치
int ans = 0;
void BFS();
int main()
{
	int N, K, L;
	cin >> N >> K;

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			map[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}

	cin >> L;
	cx = 1;
	cy = 1;
	cd = 0;
	tx = cx;
	ty = cy;
	tails.push({ 1,1 });
	visited[1][1] = true;
	BFS();
	cout << ans+1;
	return 0;
}
void BFS()
{		
	int x;
	char c;
	cin >> x >> c;
	while(1){			
		if (ans == x) {				
			if (c == 'L') {
				cd--;
				if (cd < 0) {
					cd = 3;
				}
			}
			else {
				cd++;
				cd %= 4;
			}	
			cin >> x >> c;
		}
		int xx = cx + dir[cd][0];
		int yy = cy + dir[cd][1];		
		if (map[xx][yy] != -1 && !visited[xx][yy]) {
			ans++;
			tails.push({ xx,yy });
			visited[xx][yy] = true;
			cx = xx;
			cy = yy;
			switch (map[xx][yy])
			{
			case 0:
				visited[tx][ty] = false;
				tails.pop();
				tx = tails.front().first;
				ty = tails.front().second;
				break;
			case 1:
				map[xx][yy] = 0;
				break;
			}
		}
		else {
			return;
		}	
	}
}
