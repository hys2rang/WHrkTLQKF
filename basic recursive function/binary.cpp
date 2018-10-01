/*
문제
숫자를 입력 받아 이진수로 출력하는 프로그램을 작성하시오. 

입력
첫 번째 줄에 숫자를 입력 받는다. 숫자의 크기는 1,000보다 작거나 같다. 

출력
첫째 줄에 숫자를 이진수로 바꾸어 출력한다. 

예제 입력
14
예제 출력
1110

예제 입력
31
예제 출력
11111
*/
#include <iostream>

using namespace std;
void PrintBinary(int n);
int main()
{
	//freopen("sample.txt", "r", stdin);
	int n;

	cin >> n;

	PrintBinary(n);

	return 0;
}

void PrintBinary(int n)
{
	//n의 이진수를 출력
	if (n == 0) {
		cout << 0;
	}
	else if (n == 1) {
		cout << 1;
	}
	else {
		PrintBinary(n / 2);
		cout << n % 2;
	}
}
