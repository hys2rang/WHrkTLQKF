#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1010;
int n;
int visited[MAX][MAX] = { 0, }; //화면, 클립보드
int main()
{
	queue<pair<int, int>> q;

	cin >> n;

	q.push({ 1,0 });
	int ans = MAX;

	while (!q.empty()) {
		int screen = q.front().first;
		int clipboard = q.front().second;
		q.pop();

		if (screen == n && visited[screen][clipboard]<ans) {
			ans = min(visited[screen][clipboard], ans);
		}

		//화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
		int nclipboard = screen;
		if (nclipboard < MAX && !visited[screen][nclipboard]) {
			q.push({ screen,nclipboard });
			visited[screen][nclipboard] = visited[screen][clipboard] + 1;
		}

		//클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
		int nscreen;
		if (clipboard > 0) {
			nscreen = screen + clipboard;
			if (nscreen < MAX && !visited[nscreen][clipboard]) {
				q.push({ nscreen,clipboard });
				visited[nscreen][clipboard] = visited[screen][clipboard] + 1;
			}
		}

		//화면에 있는 이모티콘 하나 삭제
		nscreen = screen - 1;

		if (nscreen >= 0 && !visited[nscreen][clipboard]) {
			q.push({ nscreen,clipboard });
			visited[nscreen][clipboard] = visited[screen][clipboard] + 1;
		}
	}


	cout << ans;
	return 0;
}
