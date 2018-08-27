/*
문제
5x5 2차원 배열이 주어질 때 어떤 원소가 상하좌우에 있는 원소보다 작을 때 해당 위치에 * 을 표시하는 프로그램을 작성하시오. 
경계선에 있는 수는 상하좌우 중 존재하는 원소만을 비교한다. 

입력
5x5 행렬의 정보가 25 개의 수로 주어진다. 각 수는 0 에서 9 사이 수이다. 

출력
*를 포함한 행렬을 출력예의 형식으로 출력한다. 

예제 입력
3 4 1 4 9
2 9 4 5 8
9 0 8 2 1
7 0 2 8 4
2 7 2 1 4
예제 출력
3 4 * 4 9 
* 9 4 5 8 
9 0 8 2 * 
7 0 2 8 4 
* 7 2 * 4 
*/
#include <iostream>

using namespace std;

int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } }; //상,하,좌,우
int main()
{
	int arr[7][7];
	int cnt1 = 0;
	int cnt2 = 0;

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			arr[i][j] = 10;
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			for (int k = 0; k < 4; k++) {		
				if (arr[i + dir[k][0]][j+dir[k][1]] < 10) {
					cnt1++;
				}
			}

			for (int k = 0; k < 4; k++) {
				if (arr[i + dir[k][0]][j + dir[k][1]] < 10 && (arr[i][j] < arr[i + dir[k][0]][j + dir[k][1]])) {
					cnt2++;
				}

			}
			if (cnt1 == cnt2) {
				cout << "* ";
				cnt1 = cnt2 = 0;
			}
			else {
				cout << arr[i][j] << " ";
				cnt1 = cnt2 = 0;
			}
		}
		cout << endl;
	}

	return 0;
}
