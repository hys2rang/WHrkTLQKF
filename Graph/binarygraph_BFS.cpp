/*
문제
이분 그래프란, 아래 그림과 같이 정점을 크게 두 집합으로 나눌 수 있는 그래프를 말한다. 여기서 같은 집합에 속한 정점끼리는 간선이 존재해서는 안된다. 
예를 들어, 아래 그래프의 경우 정점을 크게 {1, 4, 5}, {2, 3, 6} 의 두 개의 집합으로 나누게 되면, 
같은 집합에 속한 정점 사이에는 간선이 존재하지 않으므로 이분 그래프라고 할 수 있다.
그래프가 입력으로 주어질 때, 이 그래프가 이분그래프인지를 판별하는 프로그램을 작성하시오. 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 
각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다. 

출력
주어진 그래프가 이분 그래프이면 Yes, 아니면 No를 출력한다. 

예제 입력
6 5
1 2
2 4
3 4
3 5
4 6

예제 출력
Yes 

예제 입력
4 5
1 2
1 3
1 4
2 4
3 4

예제 출력
No
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1010;
vector<int> map[MAX];
vector<bool> visited(MAX);
vector<int> colored(MAX,0);
int n, m;
bool BFS();
int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;

		cin >> a >> b;

		map[a].push_back(b);
		map[b].push_back(a);

	}

	if (BFS()) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}
bool BFS()
{
	queue<int> q;
	visited[1] = true;
	colored[1] = 1;
	q.push(1);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < map[v].size(); i++) {
			if (!visited[map[v][i]]) {
				visited[map[v][i]] = true;
				q.push(map[v][i]);
				if (colored[v] == 1) {
					colored[map[v][i]] = 2;
				}
				else {
					colored[map[v][i]] = 1;
				}
			}
			else if (colored[v] == colored[map[v][i]]) {
				return false;
			}
		}
	}
	return true;
}
