#include <iostream>
#include <list>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
//r,c : 상어의 위치
//s : 속력
//d : 이동방향
//z : 크기
const int MAX = 110;
class Shark {
public:
	int speed;
	pair<int, int> dir;
	int size;
	Shark(int s, pair<int, int> d, int z) {
		speed = s;
		dir = d;
		size = z;
	};
};

Shark* map[MAX][MAX];

int main()
{
	list<Shark*> sharks;

	int R, C, M;
	int ans = 0;
	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		map[r][c] = new Shark(s, { dir[d - 1][0],dir[d - 1][1] }, z);
		sharks.push_back(map[r][c]);
	}

	for (int i = 0; i < C; i++) {
		Shark* tmp[MAX][MAX] = { NULL, };
		//낚시
		for (int j = 1; j <= R; j++) {
			if (map[j][i+1] != NULL) {
				ans += map[j][i+1]->size;
				sharks.remove(map[j][i + 1]);
				map[j][i + 1] = NULL;
				break;
			}
		}
		//상어가 이동함
		for (int r = 1; r <= R; r++) {
			for (int c = 1; c <= C; c++) {
				//상어가 있다면
				if (map[r][c] != NULL) {
					//상어가 이동해야함
					//속도+현재위치가 더 큰경우를 r과 c에 나눠서 고려함
					Shark* shark = map[r][c];
					int nx = c, ny = r;
					if (shark->dir.first == 0) { //동서로 움직임
						int cx = c;
						for (int s = 0; s < shark->speed;s++) {
							nx = cx + shark->dir.second;
							if (nx > C || nx < 1) {
								shark->dir.second *= -1;
								nx = cx + shark->dir.second;
							}
							cx = nx;
						}
					}
					else {//남북으로 움직임
						int cy = r;
						for (int s = 0; s < shark->speed; s++) {
							ny = cy + shark->dir.first;
							if (ny > R || ny < 1) {
								shark->dir.first *= -1;
								ny = cy + shark->dir.first;
							}
							cy = ny;
						}
					}
					if (tmp[ny][nx] != NULL) {
						if (tmp[ny][nx]->size < shark->size) {
							tmp[ny][nx] = NULL;
						}
						else {
							continue;
						}
					}
					tmp[ny][nx] = shark;
				}
			}
		}


		for (int r = 1; r <= R; r++) {
			for (int c = 1; c <= C; c++) {
				map[r][c] = NULL;
				if (tmp[r][c] != NULL) {
					map[r][c] = tmp[r][c];
				}
			}
		}
	}
	cout << ans;
}
