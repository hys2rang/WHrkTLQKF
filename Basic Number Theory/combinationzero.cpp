/*
문제
n명의 사람중 m명을 순서에 상관없이 뽑는 경우의 수를 조합이라고 하며 nCm으로 나타낸다.

nCm은 수식으로 n!/m!(n-m)! 으로 구할 수 있다. (5! = 12345)

n과 m이 주어졌을때 nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.  

입력
첫째 줄에 정수 n, m(0≤m≤n≤1,000,000)이 들어온다.

 

출력
첫째 줄에 0의 개수를 출력한다.

 

예제 입력
25 12
예제 출력
2
*/
#include <iostream>

using namespace std;

int main()
{
	int n, m,nn;
	int cnt2 = 0, cnt5=0;
	int result;
	cin >> n >> m;

	for (int i = n; i > 0; i--) {
		nn = i;
		while (1) {
			if (nn % 2 == 0) {
				cnt2++;
				nn = nn / 2;
			}
			if (nn % 5 == 0) {
				cnt5++;
				nn = nn / 5;
			}
			if (nn%2 !=0 && nn%5 !=0) {
				break;
			}
		}
	}

	for (int i = m; i > 0; i--) {
		nn = i;
		while (1) {
			if (nn % 2 == 0) {
				cnt2--;
				nn = nn / 2;
			}
			if (nn % 5 == 0) {
				cnt5--;
				nn = nn / 5;
			}
			if (nn % 2 != 0 && nn % 5 != 0) {
				break;
			}
		}
	}
	for (int i = n-m; i > 0; i--) {
		nn = i;
		while (1) {
			if (nn % 2 == 0) {
				cnt2--;
				nn = nn / 2;
			}
			if (nn % 5 == 0) {
				cnt5--;
				nn = nn / 5;
			}
			if (nn % 2 != 0 && nn % 5 != 0) {
				break;
			}
		}
	}

	if (cnt2 < cnt5) {
		result = cnt2;
	}
	else {
		result = cnt5;
	}

	cout << result << endl;
	return 0;
}
