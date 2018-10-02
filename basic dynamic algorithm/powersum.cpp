/*
문제
숫자 N을 제곱수의 합으로 표현하고자 할 때, 사용해야 하는 제곱 수의 최소 개수를 출력하는 프로그램을 작성하시오. 
예를 들어, 숫자 45를 제곱수의 합으로 표현하고자 할 때 필요한 제곱 수의 최소 개수는 2개이며, 이는 다음과 같다.

45 = 3^2 + 6^2
 
입력
첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100,000 )  

출력
필요한 제곱 수의 최소 개수를 출력한다. 

예제 입력
45
예제 출력
2 

예제 입력
38
예제 출력
3
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

const int MAX = 100010;
int dp[MAX] = { 0 }; //n항의 최소 개수
int arr[MAX][3] = { 0 };
int n;
int main()
{
	//freopen("a.txt", "r", stdin);

	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1); //dp[6] = 2*2 + 1 + 1
		}
	}

	cout << dp[n];

	return 0;
}
