#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100010;
int main()
{
	int n;
	int m;
	cin >> n;

	int arr[MAX] = { 0, };
	int dp[MAX] = { 0, };

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	m = dp[0] = arr[0];
	
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		m = max(m, dp[i]);
	}

	cout << m;

	return 0;
}
