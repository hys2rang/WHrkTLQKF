#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 60;
int n, m;
int ans = MAX * MAX;
bool visited[MAX] = { false, };
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
void DFS(int start, int depth);
int getchickendist();
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;

			switch (num)
			{
			case 1:
				houses.push_back({ i,j });
				break;
			case 2:
				chickens.push_back({ i,j });
				break;
			}
		}
	}

	DFS(0, 0);

	cout << ans;
	return 0;
}
void DFS(int start, int depth)
{
	if (start > chickens.size()) {
		return;
	}
	if (depth == m) {
		ans = min(ans, getchickendist());
		return;
	}
		visited[start] = true;
		DFS(start + 1, depth + 1);
		visited[start] = false;
		DFS(start + 1, depth);
}
int getchickendist()
{
	vector<pair<int, int>> selected;
	int cnt[MAX][MAX] = { 0, };
	int sum = 0;

	for (int i = 0; i < chickens.size(); i++) {
		if (visited[i]) {
			selected.push_back({ chickens[i].first,chickens[i].second });
		}
	}
	for (int i = 0; i < houses.size(); i++) {
		int x = houses[i].first;
		int y = houses[i].second;
		cnt[x][y] = MAX * MAX;
	}

	for (int j = 0; j < selected.size(); j++) {
		int x = selected[j].first;
		int y = selected[j].second;

		for (int i = 0; i < houses.size(); i++) {
			int xx = houses[i].first;
			int yy = houses[i].second;

			int num = abs(xx - x) + abs(yy - y);

			cnt[xx][yy] = min(cnt[xx][yy], num);
		}
	}

	for (int i = 0; i < houses.size(); i++) {
		int x = houses[i].first;
		int y = houses[i].second;
		sum += cnt[x][y];
	}

	return sum;
}
