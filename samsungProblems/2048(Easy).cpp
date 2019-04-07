#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 30;
int N;
int ans = -MAX * MAX;
void DFS(int depth, int arr[MAX][MAX]);
void Up(int arr[MAX][MAX]);
void Down(int arr[MAX][MAX]);
void Left(int arr[MAX][MAX]);
void Right(int arr[MAX][MAX]);
void copy(int arr1[MAX][MAX], int arr2[MAX][MAX]);
bool issame(int buf[MAX][MAX], int arr[MAX][MAX]);
void getMax(int arr[MAX][MAX]);
int main()
{
	int map[MAX][MAX] = { 0, };

	cin >> N;

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			map[i][j] = -1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	DFS(0, map);

	cout << ans;
	return 0;
}
void getMax(int arr[MAX][MAX])
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans = max(ans, arr[i][j]);
		}
	}

}
void DFS(int depth, int arr[MAX][MAX])
{
	getMax(arr);
	if (depth == 5) {
		return;
	}
	int buf[MAX][MAX] = { 0, };
	copy(buf,arr);
	Up(arr);
	if (!issame(buf,arr)) {
		DFS(depth + 1, arr);
		copy(arr, buf);
	}	
	Down(arr);
	if (!issame(buf, arr)) {
		DFS(depth + 1, arr);
		copy(arr, buf);
	}
	Left(arr);
	if (!issame(buf, arr)) {
		DFS(depth + 1, arr);
		copy(arr, buf);
	}
	Right(arr);
	if (!issame(buf, arr)) {
		DFS(depth + 1, arr);
		copy(arr, buf);
	}
}
bool issame(int buf[MAX][MAX], int arr[MAX][MAX])
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (buf[i][j] != arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void copy(int arr1[MAX][MAX], int arr2[MAX][MAX])
{
	for (int i = 0; i <= N + 1;i++) {
		for (int j = 0; j <= N + 1; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}
void Up(int arr[MAX][MAX])
{
	queue<int> b;
	queue<int> q;

	int buf[MAX][MAX] = { 0,0 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[j][i]) {
				b.push(arr[j][i]);
			}
		}
		int f, s;
		f = s = 0;
		while (!b.empty()) {	
			f = b.front();
			b.pop();
			if (!b.empty()) {
				s = b.front();
				if (f == s) {
					q.push(f * 2);
					b.pop();
				}
				else {
					q.push(f);
				}
			}
			else {
				q.push(f);
			}
		}
		for (int j = 1; !q.empty(); j++) {
			buf[j][i] = q.front();
			q.pop();
		}
	}
	copy(arr, buf);
}
void Down(int arr[MAX][MAX])
{
	queue<int> b;
	queue<int> q;

	int buf[MAX][MAX] = { 0,0 };
	for (int i = 1; i <= N; i++) {
		for (int j = N; j >= 1 ; j--) {
			if (arr[j][i]) {
				b.push(arr[j][i]);
			}
		}
		int f, s;
		f = s = 0;
		while (!b.empty()) {
			f = b.front();
			b.pop();
			if (!b.empty()) {
				s = b.front();
				if (f == s) {
					q.push(f * 2);
					b.pop();
				}
				else {
					q.push(f);
				}
			}
			else {
				q.push(f);
			}
		}
		for (int j = N; !q.empty(); j--) {
			buf[j][i] = q.front();
			q.pop();
		}

	}
	copy(arr, buf);
}
void Left(int arr[MAX][MAX])
{
	queue<int> b;
	queue<int> q;
	int buf[MAX][MAX] = { 0,0 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j]) {
				b.push(arr[i][j]);
			}
		}
		int f, s;
		f = s = 0;
		while (!b.empty()) {
			f = b.front();
			b.pop();
			if (!b.empty()) {
				s = b.front();
				if (f == s) {
					q.push(f * 2);
					b.pop();
				}
				else {
					q.push(f);
				}
			}
			else {
				q.push(f);
			}
		}
		for (int j = 1; !q.empty(); j++) {
			buf[i][j] = q.front();
			q.pop();
		}
	}
	copy(arr, buf);
}
void Right(int arr[MAX][MAX])
{
	queue<int> b;
	queue<int> q;

	int buf[MAX][MAX] = { 0,0 };
	for (int i = 1; i <= N; i++) {
		for (int j = N; j >= 1; j--) {
			if (arr[i][j]) {
				b.push(arr[i][j]);
			}
		}
		int f, s;
		f = s = 0;
		while (!b.empty()) {
			f = b.front();
			b.pop();
			if (!b.empty()) {
				s = b.front();
				if (f == s) {
					q.push(f * 2);
					b.pop();
				}
				else {
					q.push(f);
				}
			}
			else {
				q.push(f);
			}
		}
		for (int j = N; !q.empty(); j--) {
			buf[i][j] = q.front();
			q.pop();
		}
	}
	copy(arr, buf);
}
