/*
문제
크기 N의 프랙탈 수는 다음과 같이 출력된다.
크기 N-1의 프랙탈 수를 출력한다. (단, 숫자 1에 대한 프랙탈 수는 1이다)
그 다음에 숫자 N을 출력한다.
그 다음에 크기 N-1 프랙탈 수를 출력한다.
예를 들어, 숫자 2에 대한 프랙탈 수는 “1 2 1”이며, 숫자 3에 대한 프랙탈 수는 “1 2 1 3 1 2 1”이다. 
숫자 N이 주어질 때, 크기 N의 프랙탈 수를 출력하는 프로그램을 작성하시오.  

입력
첫 번째 줄에 숫자 N이 주어진다. ( 1 ≤ N ≤ 20 )  

출력
첫째 줄에 크기 N의 프랙탈 수를 출력한다.

 

예제 입력
4
예제 출력
1 2 1 3 1 2 1 4 1 2 1 3 1 2 1
 
*/
#include <iostream>

using namespace std;
void PrintMt(int n);
int main()
{
	int n;

	cin >> n;

	PrintMt(n);

	return 0;
}

void PrintMt(int n)
{
	if (n == 1) {
		cout << 1<<" ";
	}
	else {
		PrintMt(n - 1);
		cout << n <<" ";
		PrintMt(n - 1); 
	}
}
