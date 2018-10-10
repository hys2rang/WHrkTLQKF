/*
문제
많은 공장에서 로봇이 이용되고 있다. 우리 월드 공장의 로봇은 바라보는 방향으로 궤도를 따라 움직이며, 
움직이는 방향은 동, 서, 남, 북 가운데 하나이다. 로봇의 이동을 제어하는 명령어는 다음과 같이 두 가지이다.

명령 1. Go k

k는 1, 2 또는 3일 수 있다. 현재 향하고 있는 방향으로 k칸 만큼 움직인다.
명령 2. Turn dir

dir은 left 또는 right 이며, 각각 왼쪽 또는 오른쪽으로 90° 회전한다.
공장 내 궤도가 설치되어 있는 상태가 아래와 같이 0과 1로 이루어진 직사각형 모양으로 로봇에게 입력된다. 
0은 궤도가 깔려 있어 로봇이 갈 수 있는 지점이고, 1은 궤도가 없어 로봇이 갈 수 없는 지점이다. 
로봇이 (4, 2) 지점에서 남쪽을 향하고 있을 때, 이 로봇을 (2, 4) 지점에서 동쪽으로 향하도록 이동시키는 것은 아래와 같이 9번의 명령으로 가능하다.

로봇의 현재 위치와 바라보는 방향이 주어졌을 때, 로봇을 원하는 위치로 이동시키고, 
원하는 방향으로 바라보도록 하는데 최소 몇 번의 명령이 필요한지 구하는 프로그램을 작성하시오. 

입력
첫째 줄에 공장 내 궤도 설치 상태를 나타내는 직사각형의 세로 길이 M과 가로 길이 N이 빈칸을 사이에 두고 주어진다. 
이때 M과 N은 둘 다 100이하의 자연수이다. 이어 M줄에 걸쳐 한 줄에 N개씩 각 지점의 궤도 설치 상태를 나타내는 
숫자 0 또는 1이 빈칸을 사이에 두고 주어진다. 다음 줄에는 로봇의 출발 지점의 위치 (행과 열의 번호)와 바라보는 방향이 빈칸을 사이에 두고 주어진다. 
마지막 줄에는 로봇의 도착 지점의 위치 (행과 열의 번호)와 바라보는 방향이 빈칸을 사이에 두고 주어진다. 
방향은 동쪽이 1, 서쪽이 2, 남쪽이 3, 북쪽이 4로 주어진다. 출발지점에서 도착지점까지는 항상 이동이 가능하다. 

출력
첫째 줄에 로봇을 도착 지점에 원하는 방향으로 이동시키는데 필요한 최소 명령 횟수를 출력한다. 

예제 입력
5 6
0 0 0 0 0 0
0 1 1 0 1 0
0 1 0 0 0 0
0 0 1 1 1 0
1 0 0 0 0 0
4 2 3
2 4 1
예제 출력
9
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
enum DIR { E, W, S, N };
const int MAX = 105;
int map[MAX][MAX];
int check[MAX][MAX] = { 0,0, };
bool visited[MAX][MAX][4] = { false,false,false, };
int n, m;
int s_x, s_y, s_d, e_x, e_y, e_d;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void BFS();
void initialize();
struct Pos {
	int x, y, dir, cnt;
};
int main()
{
	cin >> n >> m;

	initialize();
	BFS();

	return 0;
}
void BFS()
{
	visited[s_x][s_y][s_d-1] = true;
	Pos pos;
	queue<Pos> q;
	pos.x = s_x;
	pos.y = s_y;
	pos.dir = s_d-1;
	pos.cnt = 0;
	q.push(pos);
	while (!q.empty()) {
		int d = q.front().dir;
		int x = q.front().x;
		int y = q.front().y;
		int c = q.front().cnt;
		q.pop();
		if (x == e_x && y == e_y && d == e_d-1) {
			cout << c;
			return;
		}
		for (int i = 1; i <= 3; i++) {
			int xx = x + dir[d][0] * i;
			int yy = y + dir[d][1] * i;
			if (xx>=1 && xx<=n && yy>=1 && yy<=m) {
				if (map[xx][yy] == 0) {
					if (!visited[xx][yy][d]) {
						pos.x = xx;
						pos.y = yy;
						pos.dir = d;
						pos.cnt = c + 1;
						q.push(pos);
						visited[xx][yy][d] = true;
					}					
				}
				else {
					break;
				}
			}		
		}
		int cc;
		for (int i = 0; i < 4; i++) {
			if (!visited[x][y][i] && i != d) {
				if (d == E) {
					if (i == W) {
						cc = 2;
					}
					else {
						cc = 1;
					}
				}
				else if (d == W) {
					if (i == E) {
						cc = 2;
					}
					else {
						cc = 1;
					}
				}
				else if (d == S) {
					if (i == N) {
						cc = 2;
					}
					else {
						cc = 1;
					}
				}
				else if (d == N) {
					if (i == S) {
						cc = 2;
					}
					else {
						cc = 1;
					}
				}
				visited[x][y][i] = true;
				pos.cnt = c + cc;
				pos.x = x;
				pos.y = y;
				pos.dir = i;
				q.push(pos);
			}
		}
	}
}
void initialize()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	cin >> s_x >> s_y >> s_d >> e_x >> e_y >> e_d;
}
