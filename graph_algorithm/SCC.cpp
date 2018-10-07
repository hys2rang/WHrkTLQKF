/*
문제
SCC (Strongly Connected Component)란, 방향성 그래프가 주어질 때 정점을 여러 집합으로 나누는 기법으로써, 
같은 집합에 속해있는 정점끼리는 서로 왔다갔다 할 수 있어야 한다. 아래 그림은 그래프의 예제와, 이 그래프에서 SCC를 구한 예제이다.
아래 그림처럼, 정점을 {1, 2, 5}, {6, 7}, {3, 4, 8} 의 3개의 집합으로 나누게 되면, 같은 집합에 속한 정점들끼리는 모두 왔다갔다 할 수 있다. 
그래프가 주어질 때, SCC를 구하였을 때 얻을 수 있는 정점의 집합의 개수를 구하는 프로그램을 작성하시오. 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 
각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a에서 정점 b로 향하는 간선이 존재한다는 의미이다. 

출력
주어진 그래프에서 SCC를 구하였을 때, 얻을 수 있는 정점의 집합의 개수를 출력한다. 

예제 입력
8 14
1 5
2 1
2 3
2 6
3 4
3 8
4 3
4 8
5 2
5 6
6 7
7 3
7 6
8 4

예제 출력
3
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX = 1010;
stack<int> stk;
vector<int> map[MAX];
vector<vector<int>>SCC;
int SN = 0;
int chk[MAX] = { 0, };
bool sep[MAX] = { false, };
int n, m;
int cnt = 0;
int DFS(int x);
int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (chk[i]==0) {
			DFS(i);
		}
	}

	cout << SCC.size();

	return 0;	
}
int DFS(int x)
{
	chk[x] = ++cnt;
	stk.push(x);
	
	int res = chk[x];

	for(int i=0;i<map[x].size();i++){
		if (chk[map[x][i]]==0) {
			res = min(res, DFS(map[x][i]));
		}
		else if (!sep[map[x][i]]) {
			res = min(res, chk[map[x][i]]);
		}
	}
	if (res == chk[x]) {
		vector<int> curSCC;
		while (1) {
			int t = stk.top();
			stk.pop();
			curSCC.push_back(t);
			sep[t] = true;
			if (t == x) break;
		}
		SCC.push_back(curSCC);
		SN++;
	}
	return res;
}
