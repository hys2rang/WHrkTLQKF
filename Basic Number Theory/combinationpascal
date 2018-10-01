/*
문제
n명의 사람중 m명을 순서에 상관없이 뽑는 경우의 수를 조합이라고 하며 nCm으로 나타낸다.
이 조합은 파스칼의 삼각형과 아주 밀접한 관련이 있다고 한다.
n과 m이 주어졌을때 nCm의 값을 출력하는 프로그램을 작성하시오.  

입력
첫째 줄에 정수 n, m(0≤m≤n≤30)이 들어온다. 

출력
첫째 줄에 nCm의 값을 출력한다. 

예제 입력
5 2
예제 출력
10 
*/
#include <iostream>

using namespace std;

int main()
{
	int n,m;
	int arr[35][35];

	cin >> n>>m;

	arr[0][0]=1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}

	cout << arr[n][m] << endl;

	return 0;
}
