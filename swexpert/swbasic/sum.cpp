/*
다음 100X100의 2차원 배열이 주어질 때, 각 행의 합, 각 열의 합, 각 대각선의 합 중 최댓값을 구하는 프로그램을 작성하여라.

다음과 같은 5X5 배열에서 최댓값은 29이다.

[제약 사항]

총 10개의 테스트 케이스가 주어진다.

배열의 크기는 100X100으로 동일하다.

각 행의 합은 integer 범위를 넘어가지 않는다.

동일한 최댓값이 있을 경우, 하나의 값만 출력한다.
 
[입력]

각 테스트 케이스의 첫 줄에는 테스트 케이스 번호가 주어지고 그 다음 줄부터는 2차원 배열의 각 행 값이 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스의 답을 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX = 100;
int max(int a, int b, int c, int d, int e);
int main()
{
	int arr[MAX][MAX];
	for (int TC = 0; TC < 10; TC++) {
		int n,m=0;
		int sum_w[100] = { 0, };
		int sum_h[100] = { 0, };
		int ac1 = 0, ac2 = 0;
		cin >> n;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
				sum_w[i] += arr[i][j];
				sum_h[j] += arr[i][j];
				if (i == j) {
					ac1 += arr[i][j];
				}
				if (i + j == 99) {
					ac2 += arr[i][j];
				}
			}
		}
		for (int i = 0; i < 100; i++) {
			m = max(sum_w[i], sum_h[i], m, ac1, ac2);
		}
		cout << "#" << n<<" " << m << endl;
	}
	return 0;
}
int max(int a, int b, int c, int d, int e) {
	int M = max(a, b);
	M = max(M, c);
	M = max(M, d);
	M = max(M, e);
	return M;
}
