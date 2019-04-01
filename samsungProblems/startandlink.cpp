#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 30;

int map[MAX][MAX] = { 0, };
bool visited[MAX] = { false, };
int N;
int ans = MAX * MAX;
void DFS(int cur, int depth);
int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	DFS(1, 1);

	cout << ans;
	return 0;
}
void DFS(int cur, int depth)
{
	visited[cur] = true;
	if (depth == N / 2) {
		int sum1, sum2;
		sum1 = sum2 = 0;
		vector<int> team1, team2;
		for (int i = 1; i <= N; i++) {
			if (visited[i]) {
				team1.push_back(i);
			}
			else {
				team2.push_back(i);
			}
		}

		for (int i = 0; i < team1.size()-1; i++) {
			int a = team1[i];
			for (int j = i + 1; j < team1.size(); j++) {
				int b = team1[j];
				sum1 += map[a][b] + map[b][a];
			}
		}

		for (int i = 0; i < team2.size() - 1; i++) {
			int a = team2[i];
			for (int j = i + 1; j < team2.size(); j++) {
				int b = team2[j];
				sum2 += map[a][b] + map[b][a];
			}
		}
		
		ans = min(ans, abs(sum1 - sum2));
		return;
	}	

	for (int i = cur; i <= N; i++) {
		if (!visited[i]) {
			DFS(i, depth + 1);
			visited[i] = false;
		}
	}
}
