#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 40;

int main()
{
	int dp[MAX] = { 0, };
	int n;

	cin >> n;

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			dp[i] += dp[i - j] * 2;
		}
	}

	cout << dp[n];

	return 0;
}
