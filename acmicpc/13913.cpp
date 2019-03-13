#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
const int MIN = 0;
int main()
{
	int n, k, end;
	int map[MAX] = { 0, }; //방문횟수
	int visited[MAX]; //이전 좌표
	queue<int> q;
	vector<int> tmp;

	for (int i = 0; i < MAX; i++) {
		visited[i] = -1;
	}
	cin >> n >> k;
	end = k;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == k) {
			break;
		}

		if (now - 1 >= MIN && visited[now - 1] == -1) {
			q.push(now - 1);
			visited[now - 1] = now;
			map[now - 1] = map[now] + 1;
		}
		if (now + 1 < MAX && visited[now + 1] == -1) {
			q.push(now + 1);
			visited[now + 1] = now;
			map[now + 1] = map[now] + 1;
		}
		if (2 * now < MAX && visited[2 * now] == -1) {
			q.push(2 * now);
			visited[2 * now] = now;
			map[2 * now] = map[now] + 1;
		}		
	}
	cout << map[k] << endl;
	while (k != n) {
		tmp.push_back(visited[k]);
		k = visited[k];
	}

	reverse(tmp.begin(), tmp.end());

	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i] << " ";
	}
	cout << end;
	return 0;
}
