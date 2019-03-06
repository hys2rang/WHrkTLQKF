#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 100100;

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int map[2][MAX] = { 0, };
		int dp[2][MAX] = { 0, };
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		dp[0][0] = map[0][0];
		dp[1][0] = map[1][0];
		dp[0][1] = dp[1][0] + map[0][1];
		dp[1][1] = dp[0][0] + map[1][1];
		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + map[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + map[1][i];
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
	}
	return 0;
}
