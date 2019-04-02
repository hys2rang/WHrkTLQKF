#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 20;
long M = -1000000000;
long m = -M;
int n;
int op[4] = { 0, };
int map[MAX];
void DFS(int depth);
vector<char> v;
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	DFS(0);
	cout << M << endl << m;

	return 0;
}
void DFS(int depth)
{
	if (depth == n - 1) {
		long sum = map[0];
		for (int i = 0; i < n - 1; i++) {
			switch (v[i])
			{
			case '+':
				sum += map[i + 1];
				break;
			case '-':
				sum -= map[i + 1];
				break;
			case '*':
				sum *= map[i + 1];
				break;
			case '/':
				sum /= map[i + 1];
				break;
			}
		}
		M = max(M, sum);
		m = min(m, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			switch (i)
			{
			case 0:
				v.push_back('+');
				break;
			case 1:
				v.push_back('-');
				break;
			case 2:
				v.push_back('*');
				break;
			case 3:
				v.push_back('/');
				break;
			}
			op[i]--;
			DFS(depth + 1);
			v.pop_back();
			op[i]++;
		}
	}
}
