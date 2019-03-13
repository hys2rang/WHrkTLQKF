#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10000;
int visited[MAX];
char map[MAX];
int a, b;
string str;
void BFS();
void init()
{
	for (int i = 0; i < MAX; i++) {
		visited[i] = -1;
		map[i] = ' ';
	}
	str = "";
}
int main()
{
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> a >> b;
		init();
		BFS();
		int now = b;
		while (now != a)
		{
			str += map[now];
			now = visited[now];
		}
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	return 0;
}
void BFS()
{
	queue<int> q;

	q.push(a);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == b) {
			break;
		}
		int d1 = now / 1000;
		int d2 = (now - d1 * 1000) / 100;
		int d3 = (now - d1 * 1000 - d2 * 100) / 10;
		int d4 = (now - d1 * 1000 - d2 * 100 - d3 * 10);

		//D
		int n = (now * 2) % MAX;
		if (visited[n] == -1) {
			visited[n] = now;
			map[n] = 'D';
			q.push(n);
		}
		//S
		if (now == 0) {
			if (visited[9999] == -1) {
				visited[9999] = now;
				map[9999] = 'S';
				q.push(9999);
			}
		}
		else {
			if (visited[now - 1] == -1) {
				visited[now - 1] = now;
				map[now - 1] = 'S';
				q.push(now - 1);
			}
		}
		//L
		int num = (d2 * 1000 + d3 * 100 + d4 * 10 + d1);
		if (visited[num] == -1) {
			visited[num] = now;
			map[num] = 'L';
			q.push(num);
		}
		//R
		num = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
		if (visited[num] == -1) {
			visited[num] = now;
			map[num] = 'R';
			q.push(num);
		}
	}
}
