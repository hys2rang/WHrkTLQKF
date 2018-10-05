/*
문제
아래와 같이 이동할 수 있는 길, 그리고 이동할 수 없는 벽으로 이루어진 크기 N x M 의 지도가 주어진다. 
이 때, (N-1, 0) 에서 출발하여 (0, M-1) 까지 도착하는 최단거리를 찾으려 한다. 그런데 목수는 도끼 하나를 갖고 있으며, 
이 도끼를 이용하여 벽을 깨부술 수 있다. 하지만 이 도끼는 내구성이 그렇게 좋지 않기 때문에, 벽을 최대 1개밖에 깰 수 없다. 
목수가 출발점에서 도착점까지 이동하기 위한 최단거리를 출력하는 프로그램을 작성하시오. 물론, 벽은 최대 1개까지 깰 수 있다. 
아래 예제의 경우 ‘X’ 로 표시된 벽을 깰 경우 거리 18만에 출발점에서 도착점으로 이동할 수 있다.

입력
첫째 줄에 지도의 세로 길이 N과 지도의 가로 길이 M이 주어진다. ( 1 ≤ N, M ≤ 1,000 ) 둘째 줄부터 지도의 정보가 주어진다. 
0은 이동할 수 있는 부분, 1은 이동할 수 없는 부분을 나타낸다. 

출력
목수가 (N-1, 0) 에서 출발하여 (0, M-1) 까지 이동하는 데 필요한 최단거리를 출력한다. 목수는 미로를 항상 탈출할 수 있다고 가정한다. 

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
18

예제 입력
10 10
0 0 0 0 0 0 1 1 0 0
0 1 1 1 0 0 1 1 1 0
0 1 1 1 0 0 1 1 1 0
0 0 0 0 0 0 0 1 1 0
0 0 1 1 1 1 0 1 1 0
0 0 0 0 0 0 1 1 0 0
0 0 1 1 1 0 1 1 0 0
0 0 1 1 1 0 0 1 0 0
0 0 0 0 0 1 1 1 1 1
0 0 0 0 0 0 0 1 0 0

예제 출력
22
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

const int MAX = 1010;
pair<int, int> pos;
int map[MAX][MAX];
int check1[MAX][MAX];
int check2[MAX][MAX];
int mark[MAX][MAX] = { 0, };
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//상, 하, 좌, 우
int n, m;
bool splited = false;
void BFS();
void BFS1();
int getmin();
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	BFS();
	BFS1();

	if (check1[n][1] && check2[n][1] == 0) {
		splited = true;
	}

	cout << getmin();
	return 0;
}
int getmin()
{
	int mm = 1015132;
	if (splited) {
		mm = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mark[i][j] != 0) {
				if (!splited) {
					mm = min(mm, mark[i][j]);
				}
				else {
					mm = max(mm, mark[i][j]);
				}
			}
		}
	}

	return mm;
}
void BFS()
{
	queue<pair<int, int> > q;
	pos = make_pair(n, 1);
	q.push(pos);
	check1[n][1] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
				if (!check1[xx][yy] && map[xx][yy] == 0) {
					check1[xx][yy] = check1[x][y] + 1;
					pos = make_pair(xx, yy);
					q.push(pos);
				}
				else if (!mark[xx][yy] && map[xx][yy] == 1) {
					mark[xx][yy] = check1[x][y];
				}
			}
		}
	}
}
void BFS1()
{
	queue<pair<int, int> > q;
	int visited[MAX][MAX] = { false };
	pos = make_pair(1, m);
	q.push(pos);
	check2[1][m] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
				if (!check2[xx][yy] && map[xx][yy] == 0) {
					check2[xx][yy] = check2[x][y] + 1;
					pos = make_pair(xx, yy);
					q.push(pos);
				}
				else if (!visited[xx][yy] && map[xx][yy] == 1) {
					mark[xx][yy] += check2[x][y];
					visited[xx][yy] = true;
				}
			}
		}
	}
}

