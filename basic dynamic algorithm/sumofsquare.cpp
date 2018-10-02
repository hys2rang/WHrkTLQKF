/*
문제
N x M 의 직사각형이 주어지며, 각 칸에는 정수가 들어있다. 이제 Q개의 질문에 대하여 답을 해야 하며, 
각각의 질문은 (a, b)부터 (c, d)까지의 직사각형에 들어있는 정수의 합을 묻는다. 
예를 들어, 다음과 같이 5 x 5 의 직사각형이 주어질 때, (1, 2) 부터 (3, 3) 까지의 직사각형에 들어있는 정수의 합은 26 이다.

입력
첫 번째 줄에 N, M, Q가 주어진다. ( 1 ≤ N, M ≤ 1,000, 1 ≤ Q ≤ 1,000,000 ) 두 번째 줄부터 N x M 직사각형에 주어진다. 그 후 Q개의 질문이 주어진다. 
각각의 질문은 “a b c d” 로 이루어 져 있으며, 이는 (a, b) 부터 (c, d) 까지의 직사각형에 들어있는 정수의 합을 묻는다.  

출력
각 질문에 대한 답을 출력한다. 

예제 입력
5 5 3
 1 -2 3 2 8
-8 -9 3 4 5
 2 4 7 8 2
 1 4 3 1 4
-1 2 5 -6 3
1 2 3 4
0 0 1 1
2 0 2 1
예제 출력
37
-18
6
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
const int MAX = 1010;
int main()
{
	int n, m, q;
	int sum = 0;
	int map[MAX][MAX];
	int dp[MAX][MAX];
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			dp[i][j] = map[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1] << endl;
	}

	return 0;
}
