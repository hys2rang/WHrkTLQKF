#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

const int MAX = 15;

int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
int main()
{
	int N, M, K;
	int res = 0;
	int map[MAX][MAX];
	int A[MAX][MAX];
	queue<int> dead[MAX][MAX];
	vector<int> trees[MAX][MAX];
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			map[i][j] = -1;
		}
	}

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			map[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	for (int year = 0; year < K; year++) {
		vector<int>::iterator iter;
		res = 0;
		//Spring
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (trees[i][j].size() == 0) {
					continue;
				}
				sort(trees[i][j].begin(), trees[i][j].end());
				vector<int> tmp;
				for (iter = trees[i][j].begin(); iter != trees[i][j].end(); iter++) {
					int cur = *iter;
					if (cur <= map[i][j]) {
						map[i][j] -= cur;
						tmp.push_back(cur+1);
					}
					else {
						dead[i][j].push(cur);
					}
				}
				trees[i][j].clear();
				for (iter = tmp.begin(); iter != tmp.end(); iter++) {
					trees[i][j].push_back(*iter);
				}
			}
		}
		//Summer
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				while (!dead[i][j].empty()) {
					int cur = dead[i][j].front();
					dead[i][j].pop();
					map[i][j] += cur / 2;
				}
			}
		}
		//fall
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (iter = trees[i][j].begin(); iter != trees[i][j].end(); iter++) {
					if (*iter % 5 == 0) {
						for (int k = 0; k < 8; k++) {
							int x = i + dir[k][0];
							int y = j + dir[k][1];
							if (map[x][y] != -1) {
								trees[x][y].push_back(1);
							}
						}
					}
				}
			}
		}
		//winter
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] += A[i][j];
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			res += trees[i][j].size();
		}
	}
	cout << res;

	return 0;
}
