/*
문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. 
(1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다. 

출력
첫째 줄에 연결 요소의 개수를 출력한다. 

예제 입력 1
6 5
1 2
2 5
5 1
3 4
4 6
예제 출력 1
2

예제 입력 2
6 8
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3
예제 출력 2
1
*/
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1010;
int n, m;
vector<int> map[MAX];
bool visited[MAX] = { false, };
void DFS(int x);
int main()
{
	int cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}
void DFS(int x)
{
	visited[x] = true;
	for (int i = 0; i < map[x].size(); i++) {
		if (!visited[map[x][i]]) {
			DFS(map[x][i]);
		}
	}
}
