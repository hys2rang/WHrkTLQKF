/*
문제
열의 개수 N, 행의 개수 M이 주어질 때, 다음과 같이 출력하는 프로그램을 작성해보자. (단, 2차원 배열을 활용할 것)  
입력
첫째 줄에 자연수 N,M이 주어진다.(1<=N,M<=100)
출력
출력 예시와 같은 형식으로 출력한다. 

예제 입력
3 4
예제 출력
1 2 3 4
5 6 7 8
9 10 11 12 

예제 입력
4 3
예제 출력
1 2 3
4 5 6
7 8 9
10 11 12
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	int cnt = 1;
	vector<vector <int>> arr;

	cin >> n >> m;

	arr.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = cnt++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
