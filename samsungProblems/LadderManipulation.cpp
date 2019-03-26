#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 40;
bool visited[MAX][MAX][2] = { false, }; //0:left 1:right
int N, M, H;
int ans = MAX * MAX;
void DFS(int depth, int row, int col);
bool isans();
int main()
{
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		visited[a][b][1] = visited[a][b + 1][0] = true;
	}

	DFS(0,1,1);

	if (ans == MAX * MAX) {
		ans = -1;
	}
	cout << ans;
	return 0;
}
void DFS(int depth, int row, int col)
{
	if (depth >= ans) {
		return;
	}
	if (depth > 3) {
		return;
	}
	if (isans()) {
		ans = min(depth,ans);
		return;
	}
	else {
		for (int i = row; i <= N; i++) {
			for (int j = col; j <= H; j++) {
				if (i - 1 >= 1 && !visited[j][i][0] && !visited[j][i - 1][0]) {
					visited[j][i][0] = true;
					visited[j][i - 1][1] = true;
					DFS(depth + 1,i-1,j);
					visited[j][i][0] = false;
					visited[j][i - 1][1] = false;
				}
				if (i + 1 <= N && !visited[j][i][1] && !visited[j][i + 1][1]) {
					visited[j][i][1] = true;
					visited[j][i + 1][0] = true;
					DFS(depth + 1,i+1,j);
					visited[j][i + 1][0] = false;
					visited[j][i][1] = false;
				}
			}
		}
	}
}
bool isans()
{
	for (int i = 1; i <= N; i++) {
		int now;
		now = i;
		for (int j = 1; j <= H; j++) {
			if (now-1>=1 && visited[j][now][0] && visited[j][now - 1][1]) {
				now = now - 1;
			}
			else if (now+1<=N && visited[j][now][1] && visited[j][now + 1][0]) {
				now = now + 1;
			}
		}
		if (i != now) {
			return false;
		}
	}
	return true;
}
