/*
문제
그래프가 주어질 때, 정점 1번에서 정점 N번으로 가는 최단거리를 구하려 하는데, 그 과정에서 두 개의 정점을 반드시 거쳐야 한다. 
한 번 방문했던 정점을 또 다시 방문하는 것도 허용하고, 간선도 마찬가지로 여러번 방문하는 것을 허용한다고 할 때, 
1번에서 N번으로 가는 “특정한" 최단거리를 출력하는 프로그램을 작성하시오. 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 
각 줄은 두 개의 숫자 a, b, c로 이루어져 있으며, 이는 정점 a와 정점 b가 가중치 c인 간선으로 연결되어 있다는 의미이다. 
마지막 줄에는 반드시 거쳐야 하는 두 정점 A, B가 주어진다. 

출력
1번 정점에서 N번 정점으로 가는 “특정한" 최단거리를 출력한다. 단, “특정한" 최단거리란, 주어진 정점 A와 B를 반드시 방문할 때의 최단거리를 의미한다. 

예제 입력
4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3

예제 출력
7
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
int n, m;
const int MAX = 1010;
vector<int>List[MAX];
vector<int>Cost[MAX];
long long getShortest(int start, int end);
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		List[a].push_back(b);
		List[b].push_back(a);
		Cost[a].push_back(c);
		Cost[b].push_back(c);
	}
	int a, b;
	cin >> a >> b;
	cout << min(getShortest(1, a) + getShortest(a, b) + getShortest(b, n), getShortest(1, b) + getShortest(b, a) + getShortest(a, n));
	return 0;
}
long long getShortest(int start, int end) {

	vector<long long> Table;
	vector<bool> Check;
	Table.resize(n + 1, 0);
	Check.resize(n + 1, false);

	for (int i = 1; i <= n; i++) {
		Table[i] = (i == start) ? 0 : 987987987;
	}

	for (int i = 0; i < n; i++) {
		int myMin = 987987987, minInx = -1;

		for (int j = 1; j <= n; j++) {
			if (!Check[j] && myMin >= Table[j]) {
				myMin = Table[j];
				minInx = j;
			}
		}

		Check[minInx] = true;

		for (int j = 0; j < List[minInx].size(); j++) {
			int w = List[minInx][j];
			int c = Cost[minInx][j];

			Table[w] = min(Table[w], Table[minInx] + c);
		}
	}

	return Table[end];
}
