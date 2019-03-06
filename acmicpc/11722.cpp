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
	int dp[MAX] = { 0, };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	dp[0] = Max = 1;

	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (map[i]<map[j] && dp[j] + 1>dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		Max = max(Max, dp[i]);
	}

	cout << Max;

	
	return 0;
}
