#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 120;

int dir[5][2] = { {0,0},{-1,0},{0,1},{1,0},{0,-1} };
struct BC
{
	int x, y, C, P;
};
int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int M, A;
		int ans = 0;
		int moveA[MAX] = { 0, };
		int moveB[MAX] = { 0, };
		cin >> M >> A;

		for (int i = 0; i < M; i++) {
			cin >> moveA[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> moveB[i];
		}

		vector<BC> Chargers;

		for (int i = 0; i < A; i++) {
			int x, y, c, p;
			cin >> y >> x >> c >> p;
			Chargers.push_back({ x,y,c,p });
		}

		int ax = 1, ay = 1;
		int bx = 10, by = 10;

		for (int m = 0; m <= M; m++) {
			int curM = -MAX * MAX; //현재 둘이 합친것의 최댓값
			vector<int> Achargers;
			vector<int> Bchargers;
			for (int i = 0; i < Chargers.size(); i++) {
				int x = Chargers[i].x;
				int y = Chargers[i].y;
				if (abs(x - ax) + abs(y - ay) <= Chargers[i].C) {
					Achargers.push_back(i);
				}
				if (abs(x - bx) + abs(y - by) <= Chargers[i].C) {
					Bchargers.push_back(i);
				}
			}
			ax += dir[moveA[m]][0];
			ay += dir[moveA[m]][1];
			bx += dir[moveB[m]][0];
			by += dir[moveB[m]][1];
			if (!Achargers.size() && !Bchargers.size()) {
				continue;
			}
			else if (!Achargers.size() && Bchargers.size()) {
				for (int i = 0; i < Bchargers.size(); i++) {
					curM = max(curM, Chargers[Bchargers[i]].P);
				}
			}
			else if (Achargers.size() && !Bchargers.size()) {
				for (int i = 0; i < Achargers.size(); i++) {
					curM = max(curM, Chargers[Achargers[i]].P);
				}
			}
			else {
				for (int i = 0; i < Achargers.size(); i++) {
					for (int j = 0; j < Bchargers.size(); j++) {
						if (Achargers[i] == Bchargers[j]) {
							curM = max(curM, Chargers[Achargers[i]].P);
						}
						else {
							curM = max(curM, Chargers[Achargers[i]].P + Chargers[Bchargers[j]].P);
						}
					}
				}
			}
			ans += curM;
		}

		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}
