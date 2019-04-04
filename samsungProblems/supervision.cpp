#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1000010;

int main()
{
	int n, b, c;
	long long ans = 0;
	int stu[MAX] = { 0, };

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> stu[i];
	}

	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		stu[i] -= b;
		if (stu[i] <= 0) {
			stu[i] = 0;
		}
		ans++;
	}
	for (int i = 0; i < n; i++) {
		if (stu[i] % c != 0) {
			ans += (stu[i] / c) + 1;
		}
		else {
			ans += (stu[i] / c);
		}
	}

	cout << ans;
	return 0;
}
