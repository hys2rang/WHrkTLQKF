#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 1010;

int main() {
	int n;
	int Max;
	int map[MAX] = { 0, };
	int dp[2][MAX] = { 0, };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	dp[0][0] = Max = 1;
	dp[1][0] = 1;
	for (int i = 1; i < n; i++) {
		dp[0][i] = 1;
		for (int j = 0; j < i; j++) {
			if ((map[i]>map[j]) && dp[0][j] + 1>dp[0][i]) {
				dp[0][i] = dp[0][j] + 1;
			}
		}
	}

	for (int i = n - 1; i > 0; i--) {
		dp[1][i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (map[i] > map[j] && dp[1][j] + 1 > dp[1][i]) {
				dp[1][i] = dp[1][j] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		Max = max(Max, dp[0][i] + dp[1][i]);
	}
	cout << Max - 1;

	
	return 0;
}
