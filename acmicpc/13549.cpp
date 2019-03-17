#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100010;
int visited[MAX] = { 0, };
int main()
{
	int n, k;
	queue<int> q;
	cin >> n >> k;

	q.push(n);
    visited[n] = 1;
	while (!q.empty()) {
		int num = q.front();
		q.pop();

		if (num == k) {
			cout << visited[num]-1;
			break;
		}
        if (2*num < MAX && !visited[2 * num]) {
			visited[2 * num] = visited[num];
			q.push(2 * num);
		}
		if (num-1>=0 && !visited[num - 1]) {
			visited[num - 1] = visited[num] + 1;
			q.push(num - 1);
		}
		if (num+1 < MAX && !visited[num + 1]) {
			visited[num + 1] = visited[num] + 1;
			q.push(num + 1);
		}		
	}
	return 0;
}
