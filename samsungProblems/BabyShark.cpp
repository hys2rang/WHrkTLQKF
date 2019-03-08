#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

const int MAX = 25;

int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int map[MAX][MAX] = { 0, };
int dist[MAX][MAX] = { 0, };
int time = 0;
int cnt = 0;
int shark = 2;
int n;
int s_x, s_y;
queue<pair<int, int>> q;
void initiailize();
void initiailize_dist();
pair<int, int> find_fish();
int main()
{
	cin >> n;

	initiailize();

	while (1) {
		initiailize_dist();
		pair<int, int> pos;
		pos = find_fish();
		int x, y;
		x = pos.first;
		y = pos.second;

		if (x == -1 && y == -1) {
			break;
		}
		else {
			cnt++;
			if (cnt >= shark) {
				shark++;
				cnt = 0;
			}
			time += dist[x][y];
			map[x][y] = 0;
			q.push({ x,y });
		}
	}

	cout << time;

	return 0;
}
void initiailize()
{
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			map[i][j] = -1;
			dist[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			dist[i][j] = 0;
			if (map[i][j] == 9) {
				q.push({ i,j });
				map[i][j] = 0;
			}
		}
	}
}
void initiailize_dist() 
{
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			dist[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 0;
		}
	}
}
pair<int, int> find_fish()
{
	int m_dis = n*n;
	list<pair<int, int>> mposes;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] > shark) {
				dist[i][j] = -1;
			}
		}
	}

	s_x = q.front().first;
	s_y = q.front().second;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (xx != s_x || yy != s_y) {
				if (map[xx][yy] >= 0 && dist[xx][yy] == 0) {
					dist[xx][yy] = dist[x][y] + 1;
					q.push({ xx,yy });
				}
			}			
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] < shark && map[i][j] > 0 && dist[i][j]>0) {
				m_dis = min(m_dis, dist[i][j]);
			}			
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == m_dis && map[i][j]<shark && map[i][j] > 0) {
				mposes.push_back({ i,j });
			}
		}
	}
	if (mposes.size() == 0) {
		return { -1,-1 };
	}
	else {
		return mposes.front();
	}
}
