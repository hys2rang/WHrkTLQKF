#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 205;

int main()
{
	long long dp[MAX][MAX] = { 0, };
	//dp[i][j] : i+2개를 더해서 j를 만들 수 있는 경우의 수
	int n,k;

	cin >> n>>k;

	for (int i = 0; i <= n; i++) {
		dp[0][i] = 1;
	}
    
    for(int j=0;j<=k;j++){
        dp[j][0] = 1;
    }

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i-1][j])%1000000000;
		}
	}

	cout << dp[k - 1][n]%1000000000;

	return 0;
}
