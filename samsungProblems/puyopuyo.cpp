#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int map[12][6] = { 0, };
queue<pair<int, int>> q;
int BFS(int x, int y);
void pushdown(int n);
bool issame(int arr1[12][6], int arr2[12][6]);
void copy(int arr1[12][6], int arr2[12][6]);
int main()
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			char c;
			cin >> c;
			switch (c)
			{
			case '.':
				map[i][j] = 0;
				break;
			case 'R':
				map[i][j] = 1;
				break;
			case 'G':
				map[i][j] = 2;
				break;
			case 'B':
				map[i][j] = 3;
				break;
			case 'P':
				map[i][j] = 4;
				break;
			case 'Y':map[i][j] = 5;
				break;
			}
		}
	}
	int ans = 0;
	while (1) {
		int buf[12][6] = { 0, };
		copy(buf, map);	
		bool moved[6] = { false, };
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j]) {
					if (BFS(i, j) >= 4) {						
						while(!q.empty()) {
							int x = q.front().first;
							int y = q.front().second;
							q.pop();
							map[x][y] = 0;
							moved[y] = true;
						}
					}
				}
			}
		}
		for (int i = 0; i < 6; i++) {
			if (moved[i]) {
				pushdown(i);
			}
		}		
		if (issame(buf,map)) {
			break;
		}
		else {
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}
int BFS(int x, int y)
{
	bool visited[12][6] = { false, };
	queue<pair<int, int>> buf;
	q.push({ x,y });
	buf.push({ x,y });
	int cur = map[x][y];
	visited[x][y] = true;
	int cnt = 1;
	while (!buf.empty()) {
		int xx = buf.front().first;
		int yy = buf.front().second;
		buf.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dir[i][0];
			int ny = yy + dir[i][1];

			if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6 && map[nx][ny] == cur && !visited[nx][ny]) {
				buf.push({ nx,ny });
				q.push({ nx,ny });
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}
	if (cnt < 4) {
		while (!q.empty()) {
			q.pop();
		}
	}
	return cnt;
}
void pushdown(int n)
{
	queue<int> buf;
	for (int i = 11; i >=0; i--) {
		if (map[i][n]) {
			buf.push(map[i][n]);
			map[i][n] = 0;
		}
	}
	for (int i = 11; !buf.empty(); i--) {
		map[i][n] = buf.front();
		buf.pop();
	}
}
bool issame(int arr1[12][6], int arr2[12][6])
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr1[i][j] != arr2[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void copy(int arr1[12][6], int arr2[12][6])
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}
