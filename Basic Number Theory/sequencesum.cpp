/*
문제
준혁이는 양의 정수 N개로 이루어진 수열 A의 정체를 아무에게나 알려주고 싶지 않았다. 
그래서 준혁이는 수열 A의 모든 두 수의 합만을 적어놓고 이를 S라고 했다. 이 때, 수열 A를 구하는 프로그램을 작성하시오.  

입력
첫째 줄에 수열의 크기 N이 주어진다. (3 ≤ N ≤ 1000)
다음 N개 줄에는 100,000보다 작거나 같은 양의 정수가 N개씩 주어진다. 이 숫자들은 S를 이루는 숫자이며, 
S(i,j) = A[i] + A[j] (i≠j), S(i,j) = 0 (i=j) 이다. S(i,j)는 i번째 줄, j번째 숫자를 의미하며, A[i]는 A의 i번째 수이다.
입력으로 주어지는 S에 해당하는 수열 A는 항상 유일하다.  

출력
첫째 줄에 수열 A를 출력한다. 

예제 입력
4
0 3 6 7
3 0 5 6
6 5 0 9
7 6 9 0
예제 출력
2 1 4 5
 

출처
COCI 2012/2013 Contest #6 2번  

힌트
즉 S의 2행 3열(예제에서는 5)이 의미하는 바는 A[2] + A[3] (예제에서는 1+4) 이다.
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<vector <int>> s;
	vector<int> arr;
	cin >> n;

	s.resize(n, vector<int>(n, 0));
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	arr[0] = (s[0][1] + s[0][2] - s[1][2])/2;

	for (int i = 1; i < n; i++) {
		arr[i] = s[0][i] - arr[0];
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
