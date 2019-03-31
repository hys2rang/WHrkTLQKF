#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 110;
int N, L;
bool buildrunway(int arr[]);
bool isflat(int arr[], int start, int end);
int main()
{
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int ans = 0;
		int map[MAX][MAX];
		cin >> N >> L;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= N; i++) {
			//가로줄 확인
			if (buildrunway(map[i])) {
				ans++;
			}
		}
		for (int i = 1; i <= N; i++) {
			//세로줄 확인
			int arr[MAX] = { 0, };
			for (int j = 1; j <= N; j++) {
				arr[j] = map[j][i];
			}
			if (buildrunway(arr)) {
				ans++;
			}
		}
        
        cout<<"#"<<tc+1<<" "<<ans<<endl;
		
	}
	return 0;
}
bool buildrunway(int arr[])
{
	bool upstair[MAX] = { false, };
	bool downstair[MAX] = { false, };

	//case 1 : 두 활주로의 높이차가 2 이상인경우
	for (int i = 1; i <= N - 1; i++) {
		if (abs(arr[i] - arr[i + 1]) >= 2) {
			return false;
		}
	}
	//case 2-1 : 높이차가 1인데 경사로를 설치할 수 없는 경우 오른쪽 방향으로 탐색

	for (int i = 1; i <= N-1; i++) {
		if (arr[i] > arr[i + 1]) {
			if (isflat(arr, i + 1, i + L)) {
				for (int j = i + 1; j <= i + L; j++) {
					upstair[j] = true;
				}
				i = i + L -1 ;
			}
			else {
				return false;
			}
		}
	}
	//case 2-1 : 높이차가 1인데 경사로를 설치할 수 없는 경우 왼쪽 방향으로 탐색

	for (int i = N; i >= 2; i--) {
		if (arr[i] > arr[i - 1]) {
			if (isflat(arr, i - L, i - 1)) {
				for (int j = i - L; j <= i - 1; j++) {
					downstair[j] = true;
				}
				i = i - L +1;
			}
			else {
				return false;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (upstair[i] && downstair[i]) {
			return false;
		}
	}
	return true;
}
bool isflat(int arr[], int start, int end)
{
	if (start <= 0 || end > N) {
		return false;
	}
	for (int i = start; i <= end - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			return false;
		}
	}
	return true;
}
