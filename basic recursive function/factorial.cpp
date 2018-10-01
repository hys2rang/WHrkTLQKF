/*
문제
N 팩토리얼 (N!)은 1부터 N까지의 곱으로 정의된다. 예를 들어, 3! = 1 x 2 x 3 = 6, 4! = 1 x 2 x 3 x 4 = 24 이다. 
N이 주어질 때, N!을 계산하는 프로그램을 작성하시오.  

입력
첫 번째 줄에 숫자 N이 주어진다. ( 1 ≤ N ≤ 10 )  

출력
첫째 줄에 N!을 출력한다.

 

예제 입력
4
예제 출력
24
 
*/
#include <iostream>

using namespace std;
int Factorial(int n);
int main()
{
	int n;

	cin >> n;

	cout << Factorial(n);


	return 0;
}

int Factorial(int n)
{
	//n까지 곱한 수를 반환
	//f(0) = 1
	if (n == 0) {
		return 1;
	}
	else {
		return n * Factorial(n - 1);
	}
}
