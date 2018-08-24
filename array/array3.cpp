/*
문제
N이 주어질 때, 다음과 같은 프로그램을 작성해보자.  

입력
첫째 줄에 자연수 N이 주어진다.(1<=N<=100) 

출력
예시를 참고하여 작성하자. 

예제 입력
3 
예제 출력
1 2 4
3 5
6  

예제 입력
5
예제 출력
1 2 4 7 11
3 5 8 12 
6 9 13 
10 14
15 
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,j,k;
	int cnt = 1;
	vector<vector <int>> arr;

	cin >> n;

	arr.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (j = i,k=0; j >= 0; j--,k++) {
			arr[k][j] = cnt++;

		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
