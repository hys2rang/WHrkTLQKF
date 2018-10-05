/*
문제
아래와 같이 이동할 수 있는 길, 그리고 이동할 수 없는 벽으로 이루어진 크기 N x M 의 지도가 주어진다. 
이 때, (N-1, 0) 에서 출발하여 (0, M-1) 까지 도착하는 최단거리를 출력하는 프로그램을 작성하시오. 
아래 그림에 대하여 S에서 E까지 가는 최단거리는 22이다.

입력
첫째 줄에 지도의 세로 길이 N과 지도의 가로 길이 M이 주어진다. ( 1 ≤ N, M ≤ 1,000 ) 둘째 줄부터 지도의 정보가 주어진다. 
0은 이동할 수 있는 부분, 1은 이동할 수 없는 부분을 나타낸다. 

출력
(N-1, 0) 에서 출발하여 (0, M-1) 까지 이동하는 데 필요한 최단거리를 출력한다. 

예제 입력
10 10
0 0 0 0 0 0 1 1 0 0
0 1 1 1 0 0 1 0 1 0
0 1 1 1 0 0 1 0 1 0
0 0 0 0 0 0 0 0 1 0
0 0 1 1 1 1 0 0 1 0
0 0 0 0 0 0 1 1 0 0
0 0 1 1 1 0 1 1 0 0
0 0 1 1 1 0 0 0 0 0
0 0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 1 0 0

예제 출력
22
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

const int MAX = 1010;
pair<int, int> pos;
int map[MAX][MAX];
int check[MAX][MAX];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int n, m;
void BFS();
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	BFS();

	cout << check[1][m] - 1;
	return 0;
}
void BFS()
{
	queue<pair<int, int> > q;
	pos = make_pair(n, 1);
	q.push(pos);
	check[n][1] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
				if (!check[xx][yy] && map[xx][yy] == 0) {
					map[xx][yy] = map[x][y] + 1;
					check[xx][yy] = check[x][y] + 1;
					pos = make_pair(xx, yy);
					q.push(pos);
				}
			}
		}
	}
}
