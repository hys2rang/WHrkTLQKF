#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

const int MAX = 110;
struct Num {
	int cnt, n;
};
vector<int> calc(int arr[], int size);
bool compare(Num a, Num b);
int main()
{
	int cnt;
	int cy = 3, cx = 3;
	int r, c, k;
	int arr[MAX][MAX] = { 0, };
	cin >> r >> c >> k;
	for (int i = 0; i < cy; i++) {
		for (int j = 0; j < cx; j++) {
			cin >> arr[i][j];
		}
	}
	for(cnt=0;cnt<101;cnt++) {
		int tmp[MAX][MAX] = { 0, };
		if (arr[r-1][c-1] == k) {
			break;
		}
        if(cy>100){
            cy = 100;
        }
        if(cx>100){
            cx=100;
        }
		if (cy >= cx) {
			//R연산
			int mx = 0;
			for (int i = 0; i < cy; i++) {
				vector<int> res = calc(arr[i],cx);
				int j = 0;
				for (int k = 0; k < res.size() && k < 100; k++) {
					tmp[i][j++] = res[k];
				}
				mx = max(mx, j);
			}
			cx = mx;
		}
		else {
			//C연산
			int my = 0;
			for (int i = 0; i < cx; i++) {
				int ty[MAX] = { 0, };
				for (int j = 0; j < cy; j++) {
					ty[j] = arr[j][i];
				}
				vector<int> res = calc(ty, cy);
				int j = 0;
				for (int k = 0; k < res.size() && k < 100; k++) {
					tmp[j++][i] = res[k];
				}
				my = max(my, j);
			}
			cy = my;
		}
		for (int i = 0; i < cy; i++) {
			for (int j = 0; j < cx; j++) {
				arr[i][j] = tmp[i][j];
			}
		}
	}
    if (cnt == 101) {
				cnt = -1;
		}
	cout << cnt;
}
vector<int> calc(int arr[], int size)
{
	int cnt[MAX] = { 0, };
	int mnum = 0;
	vector<Num> numbers;
	vector<int> res;
	for (int i = 0; i < size; i++) {
		cnt[arr[i]]++;
		mnum = max(mnum, arr[i]);
	}
	for (int i = 1; i <= mnum; i++) {
		if (cnt[i]) {
			numbers.push_back({ cnt[i],i });
		}
	}
	sort(numbers.begin(), numbers.end(),compare);
	for (int i = 0, j = 0; i < numbers.size(); i++,j+=2) {
		res.push_back(numbers[i].n);
		res.push_back(numbers[i].cnt);
	}
	return res;
}
bool compare(Num a, Num b) 
{
	if (a.cnt != b.cnt) {
		return a.cnt < b.cnt;
	}
	else if (a.cnt == b.cnt) {
		return a.n < b.n;
	}
}
