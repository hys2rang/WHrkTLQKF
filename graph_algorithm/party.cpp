/*
문제
철수네 마을에는 N개의 집이 있으며, 각 집은 고유한 번호를 부여받는다. 각 번호는 1보다 크거나 같고, N보다 작거나 같다. 
철수는 마을 K에 살고 있다. 집과 집 사이에는 단방향 도로가 존재하기 때문에, 이 도로를 통하여 서로 이동할 수 있다. 
즉, N개의 마을은 그래프 구조를 이룬다. 편의상 각 집에는 한 사람만이 살고 있다고 가정하자. 
크리스마스인 오늘, 철수는 본인의 집에서 파티를 열려고 한다. 따라서 다른 모든 사람들이 철수의 집에 모여 파티를 즐기고, 
파티가 끝난 후에는 다시 본인의 집으로 돌아가려 한다. 사람들은 본인의 집에서 철수네 집까지 이동하기 위하여 항상 최단거리로 이동하기를 원하고, 
마찬가지로 철수네 집에서 본인의 집에 갈 때도 최단거리로 이동하기를 원한다. 집의 개수와 두 집을 잇는 단방향 도로의 정보, 그
리고 철수의 집 번호가 주어질 때, 마을 사람들이 파티를 즐기기 위해서 이동해야 하는 총 거리의 합을 출력하는 프로그램을 작성하시오. 

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M, 그리고 철수의 집 번호 K가 주어진다. ( 1 ≤ N, K ≤ 1,000, 1 ≤ M ≤ 100,000 ) 
둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b, c로 이루어져 있으며, 
이는 정점 a에서 정점 b로 이동하는 데 시간이 c만큼 걸린다는 의미이다. 양방향 도로가 아님에 주의하자. 

출력
마을 사람들이 파티를 즐기기 위해서 이동해야 하는 총 거리의 합을 출력한다. 

예제 입력
6 10 3
1 2 1
2 5 2
3 1 5
3 2 3
3 4 1
3 6 4
4 1 1
5 3 1
6 5 3
6 4 2

예제 출력
32
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
int n, m, s;
const int MAX = 1010;
vector<long long>List[MAX];
vector<long long>Back[MAX];
vector<long long>Cost[MAX];
vector<long long>Cost_B[MAX];
vector<long long> getShortest(int start, int end);
vector<long long> getShortest_b(int start, int end);
int main()
{
	int sum = 0;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		List[a].push_back(b);
		Back[b].push_back(a);
		Cost[a].push_back(c);
		Cost_B[b].push_back(c);
	}
	vector<long long> Table;

	Table = getShortest_b(s,n);
	for (int i = 1; i <= n; i++) {		
		sum += Table[i];
	}

	Table = getShortest(s, n);
	for (int i = 1; i <= n; i++) {
		sum += Table[i];
	}
	cout << sum;
	return 0;
}
vector<long long> getShortest(int start, int end) {

	vector<long long> Table;
	vector<bool> Check;
	Table.resize(n + 1, 0);
	Check.resize(n + 1, false);

	for (int i = 1; i <= n; i++) {
		Table[i] = (i == start) ? 0 : 987987987;
	}

	for (int i = 1; i < n; i++) {
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

	return Table;
}
vector<long long> getShortest_b(int start, int end) {

	vector<long long> Table;
	vector<bool> Check;
	Table.resize(n + 1, 0);
	Check.resize(n + 1, false);

	for (int i = 1; i <= n; i++) {
		Table[i] = (i == start) ? 0 : 987987987;
	}

	for (int i = 1; i < n; i++) {
		int myMin = 987987987, minInx = -1;

		for (int j = 1; j <= n; j++) {
			if (!Check[j] && myMin >= Table[j]) {
				myMin = Table[j];
				minInx = j;
			}
		}

		Check[minInx] = true;

		for (int j = 0; j < Back[minInx].size(); j++) {
			int w = Back[minInx][j];
			int c = Cost_B[minInx][j];

			Table[w] = min(Table[w], Table[minInx] + c);
		}
	}

	return Table;
}
