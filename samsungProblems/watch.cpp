#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//상,우,하,좌
struct Camera {
	int x, y,sort;
	int cnt = 0;
};
int N, M;
int ans = MAX * MAX;
int map[MAX][MAX];
vector<Camera> cameras;
void DFS(int depth, bool(*visited)[MAX]);
void setMark(bool(*visited)[MAX], Camera camera);
void Left(bool(*visited)[MAX], int sx, int sy);
void Right(bool(*visited)[MAX], int sx, int sy);
void Up(bool(*visited)[MAX], int sx, int sy);
void Down(bool(*visited)[MAX], int sx, int sy);
int getblindspots(bool(*visited)[MAX]);
void change(bool(*arr1)[MAX], bool(*arr2)[MAX]);
int main()
{
	cin >> N >> M;
	bool visited[MAX][MAX] = { false, };
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			map[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				Camera camera;
				camera.x = i;
				camera.y = j;
				camera.sort = map[i][j];
				switch (map[i][j])
				{
				case 2:
					camera.cnt = 2;
					break;
				case 5:
					camera.cnt = 1;
					break;
				default:
					camera.cnt = 4;
					break;
				}
				cameras.push_back(camera);
			}
		}
	}

	DFS(0, visited);

	cout << ans;
	return 0;
}
void DFS(int depth, bool (*visited)[MAX])
{
	bool unmarkedmap[MAX][MAX] = { false, };
	if (depth == cameras.size()) {
		ans = min(ans, getblindspots(visited));
		return;
	}
	else {		
		change(unmarkedmap, visited);
		
			int num;			
			switch (cameras[depth].sort)
			{
			case 2:
				num = 2;
				break;
			case 5:
				num = 1;
				break;
			default:
				num = 4;
				break;
			}
			for(int j=0;j<num;j++) {				
				cameras[depth].cnt = j + 1;
				setMark(visited, cameras[depth]);
				DFS(depth + 1, visited);	
				change(visited, unmarkedmap);
			}
		
	}
}
void change(bool(*arr1)[MAX], bool(*arr2)[MAX])
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}
void setMark(bool(*visited)[MAX],Camera camera)
{
	int xx = camera.x;
	int yy = camera.y;
	switch (camera.sort)
	{
	case 1:
		switch (camera.cnt)
		{
		case 1:
			Left(visited, camera.x, camera.y);
			break;
		case 2:
			Right(visited, camera.x, camera.y);
			break;
		case 3:
			Up(visited, camera.x, camera.y);
			break;
		case 4:
			Down(visited, camera.x, camera.y);
			break;
		}
		break;
	case 2:
		if (camera.cnt == 2) {
			Left(visited, xx, yy);
			Right(visited, xx, yy);
		}
		else {
			Up(visited, xx, yy);
			Down(visited, xx, yy);
		}
		break;
	case 3:
		switch (camera.cnt)
		{
		case 1:
			Up(visited, xx, yy);
			Right(visited, xx, yy);
			break;
		case 2:
			Right(visited, xx, yy);
			Down(visited, xx, yy);
			break;
		case 3:
			Down(visited, xx, yy);
			Left(visited, xx, yy);
			break;
		case 4:
			Left(visited, xx, yy);
			Up(visited, xx, yy);
			break;
		}
		break;
	case 4:
		switch (camera.cnt)
		{
		case 1:
			Left(visited, xx, yy);
			Up(visited, xx, yy);
			Right(visited, xx, yy);
			break;
		case 2:
			Up(visited, xx, yy);
			Right(visited, xx, yy);
			Down(visited, xx, yy);
			break;
		case 3:
			Right(visited, xx, yy);
			Down(visited, xx, yy);
			Left(visited, xx, yy);
			break;
		case 4:
			Down(visited, xx, yy);
			Left(visited, xx, yy);
			Up(visited, xx, yy);
			break;
		}
		break;
	case 5:
		Left(visited, xx, yy);
		Up(visited, xx, yy);
		Right(visited, xx, yy);
		Down(visited, xx, yy);
		break;
	}
}
int getblindspots(bool(*visited)[MAX])
{
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j] && map[i][j]==0) {
				cnt++;
			}
		}
	}
	return cnt;
}

void Left(bool(*visited)[MAX], int sx, int sy)
{
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	while (!q.empty()) {
		int xx = q.front().first + dir[3][0];
		int yy = q.front().second+ dir[3][1];
		q.pop();
		if (map[xx][yy] >= 0 && map[xx][yy] <= 5) {
			visited[xx][yy] = true;
			q.push({ xx, yy });
		}
	}
}
void Right(bool(*visited)[MAX], int sx, int sy)
{
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	while (!q.empty()) {
		int xx = q.front().first + dir[1][0];
		int yy = q.front().second+ dir[1][1];
		q.pop();
		if (map[xx][yy] >= 0 && map[xx][yy] <= 5) {
			visited[xx][yy] = true;
			q.push({ xx, yy });
		}
	}
}
void Up(bool(*visited)[MAX], int sx, int sy)
{
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	while (!q.empty()) {
		int xx = q.front().first + dir[0][0];
		int yy = q.front().second + dir[0][1];
		q.pop();
		if (map[xx][yy]>= 0 && map[xx][yy]<=5) {
			visited[xx][yy] = true;
			q.push({ xx, yy });
		}
	}
}
void Down(bool(*visited)[MAX], int sx, int sy)
{
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	while (!q.empty()) {
		int xx = q.front().first + dir[2][0];
		int yy = q.front().second + dir[2][1];
		q.pop();
		if (map[xx][yy] >= 0 && map[xx][yy] <= 5) {
			visited[xx][yy] = true;
			q.push({ xx, yy });
		}
	}
}
