#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 1010;

int main() {
	int n;
	int Min = -MAX;
	int Max;
	int map[MAX] = { 0, };
	int dp[MAX] = { 0, };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		Min = min(Min, map[i]);
	}
	Max = map[0];
	dp[0] = map[0];

	for (int i = 1; i < n; i++) {
		dp[i] = map[i];
		for (int j = 0; j < i; j++) {
			if (map[i] > map[j] && dp[j] + map[i] > dp[i]) {
				dp[i] = dp[j] + map[i];
			}
		}
		Max = max(Max, dp[i]);
	}

	cout << Max;
	
	return 0;
}
