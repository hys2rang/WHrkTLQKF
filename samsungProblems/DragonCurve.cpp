#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 101;
const int MIN = 0;
int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };//우,상,좌,하
bool visited[MAX][MAX] = { false, };
int x, y, d, g;
int getsquares();
int main()
{
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> y >> x >> d >> g;
		vector<int> Dir;
		Dir.push_back(d);
		//gen 0~n;
		for (int G = 0; G < g; G++) {
			for (int i = Dir.size()-1; i >=0; i--) {
				int next = (Dir[i] + 1) % 4;
				Dir.push_back(next);
			}
		}		
		//draw dragoncurve
		visited[x][y] = true;
		for (int i = 0; i < Dir.size(); i++) {
			x += dir[Dir[i]][0];
			y += dir[Dir[i]][1];
			visited[x][y] = true;
		}
	}
	
	cout << getsquares();
	return 0;
}
int getsquares()
{
	int cnt = 0;
	for (int i = 0; i < MAX-1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			if (visited[i][j]) {
				if (visited[i][j + 1] && visited[i + 1][j] && visited[i + 1][j + 1]) {
					cnt++;
				}
			}
		}
	}
	return cnt;
}
