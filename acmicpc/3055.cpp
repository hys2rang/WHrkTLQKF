#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 60;
int map[MAX][MAX];
int visited[MAX][MAX] = { 0, };
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; //상 하 좌 우
int r, c;
int s_x, s_y, d_x, d_y;
int main()
{
	queue<pair<int, int>> wq;
	queue<pair<int, int>> sq;
	cin >> r >> c;
	for (int i = 0; i <= r + 1; i++) {
		for (int j = 0; j <= c + 1; j++) {
			map[i][j] = -1;
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char c;
			cin >> c;
			switch (c)
			{
			case '.':
				map[i][j] = 0;
				break;
			case '*':
				map[i][j] = 1;
				wq.push({ i,j });
				visited[i][j] = true;
				break;
			case 'X':
				map[i][j] = -1;
				break;
			case 'D':
				map[i][j] = -2;
				d_x = i;
				d_y = j;
				break;
			case 'S':
				map[i][j] = 0;
				s_x = i;
				s_y = j;
				sq.push({ i,j });
				break;
			}
		}
	}
	while (!sq.empty()  || !wq.empty()) {
		int ws = wq.size();
		for (int s = 0; s < ws; s++) {
			int x = wq.front().first;
			int y = wq.front().second;
			wq.pop();

			for (int i = 0; i < 4; i++) {
				int xx = x + dir[i][0];
				int yy = y + dir[i][1];

				if (map[xx][yy] >= 0 && !visited[xx][yy]) {
					visited[xx][yy] = true;
					wq.push({ xx,yy });
				}
			}
		}

		int ss = sq.size();
		
		for (int s = 0; s < ss; s++) {
			int x = sq.front().first;
			int y = sq.front().second;
			sq.pop();

			for (int i = 0; i < 4; i++) {
				int xx = x + dir[i][0];
				int yy = y + dir[i][1];

				if ((map[xx][yy] == 0 || map[xx][yy] == -2) && !visited[xx][yy]) {
					map[xx][yy] = map[x][y] + 1;
					sq.push({ xx,yy });
				}
			}
		}		
		
	}

	if (map[d_x][d_y] == -2) {
		cout << "KAKTUS";
	}
	else {
		cout << map[d_x][d_y];
	}
	
	return 0;
}
