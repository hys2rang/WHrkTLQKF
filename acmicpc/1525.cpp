#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int Map[5][5];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int x, y;
int mtoi();
void setmap(string buf)
{
	for (int i = 1, k = 0; i <= 3; i++) {
		for (int j = 1; j <= 3; j++, k++) {
			if (buf.length() < 9 && i == 1 && j == 1) {
				Map[1][1] = 0;
				k = -1;
				x = 1;
				y = 1;
				continue;
			}
			else {
				int n = buf[k] - '0';
				Map[i][j] = n;
				if (n == 0) {
					x = i;
					y = j;
				}
			}

		}
	}
}

int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			Map[i][j] = -1;
		}
	}
	int num = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> Map[i][j];
			num = num * 10 + Map[i][j];
		}
	}

	map<int, int> m;
	queue<int> q;
	m[num] = 0;
	q.push(num);

	while (!q.empty()) {
		num = q.front();
		q.pop();

		if(num == 123456780){
			break;
		}

		string buf = to_string(num);
		
		setmap(buf);		

		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (Map[xx][yy] != -1) {
				swap(Map[x][y], Map[xx][yy]);
				int nn = mtoi();
				if (!m.count(nn)) {
					m[nn] = m[num] + 1;
					q.push(nn);
				}

				swap(Map[x][y], Map[xx][yy]);
			}
		}
	}

	if (!m.count(123456780)) {
		cout << -1;
	}
	else {
		cout << m[123456780];
	}
	

	return 0;
}

int mtoi()
{
	int num = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			num = num * 10 + Map[i][j];
		}
	}
	return num;
}
