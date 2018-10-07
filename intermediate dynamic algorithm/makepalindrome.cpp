/*
문제
팰린드롬이란, 앞으로 읽으나 뒤로 읽으나 똑같은 문자열을 말한다. 예를 들어, “abcba”, “abccba” 등이 있을 수 있다. 
문자열이 주어질 때, 이를 팰린드롬으로 만들기 위하여 추가해야 하는 최소의 문자 개수를 출력하는 프로그램을 작성하시오. 
예를 들어, 문자열이 “abca” 로 주어질 경우, ‘b’만 추가하면 “abcba” 를 만들 수 있으므로, 이 때는 1개의 문자만 추가하면 된다. 
또 다른 예로써, 문자열이 “adcba” 로 주어질 경우에는, 문자 2개를 추가해야 한다. 

입력
첫 번째 줄에 문자열이 주어진다. 이 문자열의 길이는 1,000 을 넘지 않는다.  

출력
주어진 문자열을 팰린드롬으로 만들기 위해서 추가해야 하는 문자 개수의 최솟값을 출력한다. 

예제 입력
adcba
예제 출력
2 

예제 입력
abccbdbac
예제 출력
3
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1010;
int dp[MAX][MAX] = { 0,0, }; //T(i, j) = i번째 문자부터 j번째 문자까지를 팰린드롬으로 만들기 위해 추가해야 하는 문자 개수의 최소값
int main()
{
	string str;
	cin >> str;
	dp[0][0] = 0;

	for (int i = 1; i < str.size();i++) {
		for (int j = 0, k = i; k < str.size(); j++, k++) {
			dp[j][k] = (str[j] == str[k]) ? dp[j + 1][k - 1] : min(dp[j][k - 1], dp[j + 1][k]) + 1;
		}
	}

	cout << dp[0][str.size() - 1];
	return 0;	
}
