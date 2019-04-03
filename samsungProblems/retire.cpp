#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 20;

int t[MAX] = { 0, };
int p[MAX] = { 0, };
int dp[MAX] = { 0, };
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i+1] = max(dp[i], dp[i + 1]);
		dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
	}
	cout << dp[n];
	return 0;
}
