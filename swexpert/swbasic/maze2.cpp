/*
아래 그림과 같은 미로가 있다. 100*100 행렬의 형태로 만들어진 미로에서 흰색 바탕은 길, 노란색 바탕은 벽을 나타낸다.

가장 좌상단에 있는 칸을 (0, 0)의 기준으로 하여, 가로방향을 x 방향, 세로방향을 y 방향이라고 할 때, 미로의 시작점은 (1, 1)이고 도착점은 (13, 13)이다.

주어진 미로의 출발점으로부터 도착지점까지 갈 수 있는 길이 있는지 판단하는 프로그램을 작성하라.

아래의 예시에서는 도달 가능하다.

아래의 예시에서는 출발점이 (1, 1)이고, 도착점이 (11, 11)이며 도달이 불가능하다. 

위의 예시는 공간상의 이유로 100x100이 아닌 16x16으로 주어졌음에 유의한다.

[입력]

각 테스트 케이스의 첫 번째 줄에는 테스트케이스의 번호가 주어지며, 바로 다음 줄에 테스트 케이스가 주어진다.

총 10개의 테스트 케이스가 주어진다.

테스트 케이스에서 1은 벽을 나타내며 0은 길, 2는 출발점, 3은 도착점을 나타낸다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 도달 가능 여부를 1 또는 0으로 표시한다 (1 - 가능함, 0 - 가능하지 않음).
*/
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
int flag = 0;
int map[102][102];
bool visited[102][102];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
pair<int, int> s_pos, e_pos;
void initialize();
void BFS();
int main()
{
	for (int tc = 0; tc < 10; tc++) {
		int T;
		flag = 0;
		scanf("%d\n", &T);
		initialize();
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					s_pos = make_pair(i, j);
				}
				if (map[i][j] == 3) {
					e_pos = make_pair(i, j);
				}
			}
		}
		
		BFS();

		printf("#%d %d\n", T, flag);
	}
	
	return 0;
}
void BFS()
{
	queue<pair<int, int>> q;
	pair<int, int> pos;
	visited[s_pos.first][s_pos.second] = true;
	q.push(s_pos);
	while (!q.empty() && flag == 0) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (map[xx][yy] != -1 && map[xx][yy] != 1 && !visited[xx][yy]) {
				pos = make_pair(xx, yy);
				visited[xx][yy] = true;
				q.push(pos);
				if (map[xx][yy] == 3) {
					flag = 1;
					break;
				}
			}
		}
	}
}
void initialize()
{
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			map[i][j] = -1;
			visited[i][j] = false;
		}
	}
}
