#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 10101;

int max(int x, int y, int z);
int main() {
	int n;
	int dp[MAX] = { 0, };
	int wine[MAX] = { 0, };

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}

	dp[0] = wine[0];
	dp[1] = wine[0] + wine[1];
	dp[2] = max(wine[2] + wine[1], wine[0] + wine[2],dp[1]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 3] + wine[i - 1] + wine[i], dp[i-2]+wine[i]);
	}

	cout << dp[n - 1] << endl;
	return 0;
}

int max(int x, int y, int z)
{
	int m = max(x, y);
	return max(m, z);
}
