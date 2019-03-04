#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 45;

int main() {
	int T, n;
	freopen("a.txt", "r", stdin);

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int dp[MAX][2] = { 0, };
		dp[0][0] = dp[1][1] = 1;
		dp[0][1] = dp[1][0] = 0;

		cin >> n;

		for (int i = 2; i <= n; i++) {
			dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
			dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
		}

		cout << dp[n][0] << " " << dp[n][1] << endl;
	}
	return 0;
}
