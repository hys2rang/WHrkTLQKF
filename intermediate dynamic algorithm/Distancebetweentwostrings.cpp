/*
문제
두 문자열 A, B 가 주어질 때, 두 문자열 사이의 거리를 구하려 한다. 여기서 거리는 다음과 같이 정의된다. 
문자열 A가 주어질 때, 여기서 하나의 연산은 하나의 알파벳을 삽입 또는 삭제하는 것을 의미한다. 
문자열 A와 B 사이의 거리란, A에서 시작하여 B를 만들기 위한 최소 연산의 횟수로 정의된다. 
예를 들어, 문자열 A가 “abcabcd”이고, 문자열 B가 “abccabc” 라면, 문자열 A와 B 사이의 거리는 2가 된다. 
왜냐하면 문자열 A의 세 번째에 ‘c’를 삽입하고, 가장 마지막에 있는 ‘d’를 삭제하면 문자열 B를 얻기 때문이다. 
두 문자열이 주어질 때, 두 문자열 사이의 거리를 출력하는 프로그램을 작성하시오. 

입력
첫 번째 줄과 두 번째 줄에 문자열이 주어지며, 이 문자열의 길이는 1000을 넘지 않는다. 주어진 문자열은 대소문자가 섞여있다.  

출력
두 문자열 사이의 거리를 출력한다. (대문자 'A'와 소문자 'a'는 다른 문자로 취급한다.) 

예제 입력
abcabcd
abccabc
예제 출력
2
*/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX = 1010;
int max(int a, int b, int c);
int main()
{
	char str1[MAX] = "";
	char str2[MAX] = "";
	int dp[MAX][MAX] = { 0 }; //str1[0~i] 와 str2[0~j]의 LCS 값

	scanf("%s\n", str1);
	scanf("%s", str2);


	dp[0][0] = (int)(str1[0] == str2[0]);

	for (int i = 1; i < strlen(str2); i++) {
		dp[0][i] = str1[0] == str2[i] ? 1 : dp[0][i - 1];
	}

	for (int i = 1; i < strlen(str1); i++) {
		dp[i][0] = (str1[i] == str2[0] ? 1 : 0);
	}
	for (int i = 1; i < strlen(str1); i++) {
		for (int j = 1; j < strlen(str2); j++) {		
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int lcs = dp[strlen(str1) - 1][strlen(str2) - 1];
	cout << strlen(str1) - lcs + strlen(str2) - lcs;

	return 0;
}
int max(int a, int b, int c)
{
	int M;
	M = max(a, b);
	return M = max(M, c);
}
