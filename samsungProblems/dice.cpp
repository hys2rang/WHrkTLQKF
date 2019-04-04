#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 30;

int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int dice[6] = { 0, };
int map[MAX][MAX] = { 0, };
void changedice(int now);
int main()
{
	int N, M, x, y, k;
	
	cin >> N >> M >> x >> y >> k;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int order;
		cin >> order;
		
		int xx = x + dir[order - 1][0];
		int yy = y + dir[order - 1][1];

		if (xx >= 0 && xx < N &&yy >= 0 && yy < M) {
			changedice(order);
			if (!map[xx][yy]) {
				map[xx][yy] = dice[5];
			}
			else {
				dice[5] = map[xx][yy];
				map[xx][yy] = 0;
			}
			cout << dice[0] << endl;
			x = xx;
			y = yy;
		}
	}
	return 0;
}
void changedice(int now)
{
	int tmp[6];
	for (int i = 0; i < 6; i++) {
		tmp[i] = dice[i];
	}
	switch (now)
	{
	case 1:
		dice[0] = tmp[3];
		dice[2] = tmp[0];
		dice[3] = tmp[5];
		dice[5] = tmp[2];
		break;
	case 2:
		dice[0] = tmp[2];
		dice[5] = tmp[3];
		dice[2] = tmp[5];
		dice[3] = tmp[0];
		break;
	case 3:
		dice[0] = tmp[4];
		dice[1] = tmp[0];
		dice[4] = tmp[5];
		dice[5] = tmp[1];
		break;
	case 4:
		dice[0] = tmp[1];
		dice[1] = tmp[5];
		dice[4] = tmp[0];
		dice[5] = tmp[4];
		break;
	}
}
