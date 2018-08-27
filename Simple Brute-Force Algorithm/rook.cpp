/*
문제
체스에서 룩이라는 기물은 상, 하, 좌, 우 방향으로 막혀있지만 않으면 움직일 수 있다.

체스는 킹만 잡히면 지게 되는 게임이다. 그 중에서도 알랩이는 룩으로 인해 게임을 지는 것을 극도로 싫어한다!

현재 체스판의 상태가 주어져 있고, 다음 차례가 상대의 차례일 때, 킹이 룩에게 잡힐 가능성이 있는지 알아보자 

입력
8줄에 걸쳐 8x8 체스판의 상태가 주어진다. 이때 0은 기물이 없는 상태이고, 1은 알랩이의 킹을 의미하고, 
2는 상대의 룩을 의미하며 3은 그 외 다른 기물들을 의미한다. (킹은 하나만 존재하며, 상대의 룩은 최대 2개까지 있을 수 있다. 
그 외 기물들은 최대 29개까지 있을 수 있다.) 

출력
킹이 룩에게 잡힐 가능성이 있으면 1, 아니면 0을 출력한다. 

예제 입력
0 3 0 0 0 0 0 0
3 1 0 0 0 0 2 0
0 3 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
예제 출력
1
*/
#include <iostream>

using namespace std;

int main()
{
	int arr[8][8];
	int a, b;
	int flag = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				a = i;
				b = j;
			}
		}
	}

	for (int i = a-1; i >= 0; i--) {
		if (arr[i][b] == 3) {
			break;
		}
		else if (arr[i][b] == 1) {
			flag = 1;
			break;
		}
	}
	if (flag != 1) {
		for (int i = a+1; i < 8; i++) {
			if (arr[i][b] == 3) {
				break;
			}
			else if (arr[i][b] == 1) {
				flag = 1;
				break;
			}
		}
	}
	
	if (flag != 1) {
		for (int i = b - 1; i >= 0; i--) {
			if (arr[a][i] == 3) {
				break;
			}
			else if (arr[a][i] == 1) {
				flag = 1;
				break;
			}
		}
	}

	if (flag != 1) {
		for (int i = b + 1; i < 8; i++) {
			if (arr[a][i] == 3) {
				break;
			}
			else if (arr[a][i] == 1) {
				flag = 1;
				break;
			}
		}
	}

	if (flag == 1) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}
