/*
문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.  

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다. 

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다. 

예제 입력
24 18
예제 출력
6
72
*/
#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int big, small, a, b;

	cin >> n >> m;

	if (n >= m) {
		big = n;
		small = m;
	}
	else {
		big = m;
		small = n;
	}

	while (1) {
		a = big / small;
		b = big % small;

		if (b == 0) {
			cout << small << endl;
			cout << n * m / small << endl;
			break;
		}
		big = small;
		small = b;
	}

	return 0;
}
