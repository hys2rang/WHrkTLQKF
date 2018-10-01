/*
문제
주어진 숫자들 중 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.  

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 줄에 걸쳐 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다. 

출력
주어진 수들 중 소수의 개수를 출력한다. 

예제 입력
4
1
3
5
7
예제 출력
3
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	int cnt = 0;
	vector<int> arr;
	cin >> n;

	arr.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 2; j < arr[i]; j++) {
			if (!(arr[i] % j)) {
				flag = true;
				break;
			}
		}		
		if (!flag && arr[i]!=1) {
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}
