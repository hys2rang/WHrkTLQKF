/*
문제
세로 두 줄, 가로로 N개의 칸으로 이루어진 표가 있다. 첫째 줄의 각 칸에는 정수 1, 2, …, N이 차례대로 들어 있고 
둘째 줄의 각 칸에는 1이상 N이하인 정수가 들어 있다. 첫째 줄에서 숫자를 적절히 뽑으면, 그 뽑힌 정수들이 이루는 집합과, 
뽑힌 정수들의 바로 밑의 둘째 줄에 들어있는 정수들이 이루는 집합이 일치한다. 이러한 조건을 만족시키도록 정수들을 뽑되, 
최대로 많이 뽑는 방법을 찾는 프로그램을 작성하시오. 예를 들어, N=7인 경우 아래와 같이 표가 주어졌다고 하자.

1	2	3	4	5	6	7
3	1	1	5	5	4	6
이 경우에는 첫째 줄에서 1, 3, 5를 뽑는 것이 답이다. 첫째 줄의 1, 3, 5밑에는 각각 3, 1, 5가 있으며 두 집합은 일치한다. 
이때 집합의 크기는 3이다. 만약 첫째 줄에서 1과 3을 뽑으면, 이들 바로 밑에는 정수 3과 1이 있으므로 두 집합이 일치한다. 
그러나, 이 경우에 뽑힌 정수의 개수는 최대가 아니므로 답이 될수 없다. 

입력
첫째 줄에는 N(1≤N≤100)을 나타내는 정수 하나가 주어진다. 그 다음 줄부터는 표의 둘째 줄에 들어가는 정수들이 순서대로 한 줄에 하나씩 입력된다. 

출력
첫째 줄에 뽑힌 정수들의 개수를 출력하고, 그 다음 줄부터는 뽑힌 정수들을 작은 수부터 큰 수의 순서로 한 줄에 하나씩 출력한다. 

예제 입력
7
3
1
1
5
5
4
6
예제 출력
3
1
3
5
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 105;
vector<int> map[MAX];
int visited[MAX] = { 0, };
void DFS(int v);
int cnt = 0;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		map[i].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] != 2) {
			DFS(i);
		}
		for (int j = 1; j <= n; j++) {
			if (visited[j] != 2) {
				visited[j] = 0;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 2) {
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 2) {
			cout << i << " ";
		}
	}
	return 0;
}
void DFS(int v)
{
	visited[v]++;

	if (visited[map[v][0]] < 2) {
		DFS(map[v][0]);
	}else{
	  return;
	}
}
