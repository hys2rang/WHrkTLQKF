/*
문제
N과 시작 숫자 S가 주어지면 숫자 피라미드를 만드는 프로그램을 작성하시오. 예를 들어, N이 5이고 S가 3 이라면, 그 숫자 피라미드는

    3
   456
  21987
 3456789
987654321
가 된다. 

입력
입력의 첫 번째 줄에 N과 시작 숫자 S가 주어진다. ( 1≤N≤100, 1 ≤S≤ 9) 

출력
첫 번째 줄부터 숫자 피라미드를 출력한다.

예제 입력
5 3
예제 출력
    3
   456
  21987
 3456789
987654321
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, s;
	vector<int> arr;
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			cout << " ";
		}
		arr.resize(2 * i + 1);
		if (i % 2 == 0) {
			for (int j = 2 * i; j >= 0; j--) {
				if (s == 10) {
					s = 1;
				}
				arr[j] = s++;
			}
		}
		else {
			for (int j = 0; j < 2 * i + 1; j++) {
				if (s == 10) {
					s = 1;
				}
				arr[j] = s++;
			}
		}		
		for (int j = 0; j < 2 * i + 1; j++) {
			cout << arr[j];
		}
		cout << endl;
		arr.clear();
	}
	return 0;
}
