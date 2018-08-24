/*
문제
9개의 서로 다른 자연수가 주어질 때, 이들 중 두 번째 최소값을 찾고, 그 두 번째 최소값이 몇 번째 수인지를 구하는 프로그램을 작성하시오. 
예를 들어, 서로 다른 9개의 자연수 3, 29, 38, 12, 57, 74, 40, 85, 61 이 주어지면, 이들 중 두 번째 최소값은 12이고, 이 값은 4번째 수이다.

입력
첫째 줄부터 아홉 번째 줄까지 한 줄에 하나의 자연수가 주어진다. 주어지는 자연수는 10,000,000 보다 작다.

출력
첫째 줄에 두 번째 최소값을 출력하고, 둘째 줄에 두 번째 최소값이 몇 번째 수인지를 출력한다.

예제 입력
3
29
38
12
57
74
40
85
61
예제 출력
12
4
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr;
	vector<int> arr1;

	arr.resize(9);
	arr1.resize(9);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		arr1[i] = arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < 9; i++) {
		if (arr[1] == arr1[i]) {
			cout << arr1[i] << endl;
			cout << i+1 << endl;
		}
	}

	return 0;
}
