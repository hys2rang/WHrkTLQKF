/*
문제
트리의 높이는 루트로부터 가장 멀리 떨어진 노드와의 거리로 정의된다. 
예를 들어, 아래의 트리에서 0번 노드가 루트라고 하면, 7번 노드까지의 거리가 가장 멀고, 그 거리는 3이다. 따라서 이 트리의 높이는 3이 된다.
트리가 주어질 때, 그 트리의 높이를 출력하는 프로그램을 작성하시오. 

입력
첫 번째 줄에 트리의 노드 개수 n, 그리고 루트노드의 번호 r이 주어진다. ( 1 ≤ r ≤ n ≤ 100 ) 두 번째 줄부터 트리의 간선 정보가 주어진다. 
각 줄은 2개의 숫자 a, b로 이루어지며, 이는 a번 노드와 b번 노드가 연결되어 있다는 뜻이다.  

출력
트리의 높이를 출력한다. 

예제 입력
8 0
0 1
0 2
1 3
1 4
1 5
2 6
6 7
예제 출력
3
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
vector<bool> visited;

int M = 0;
int x,y;
int getdepth(int v,int d);
int main()
{    
    int n,r;
    int ans;

    cin>>n>>r;

    visited.resize(n+1,false);
    map.resize(n+1);

    for(int i=0;i<n;i++){
        int a, b;

        cin>>a>>b;

        map[a].push_back(b);
        map[b].push_back(a);
    }    
    
    cout<<getdepth(r,0);
    return 0;
}
int getdepth(int v,int d)
{
    visited[v] = true;

    for(int i=0;i<map[v].size();i++){
        if(map[v][i] && !visited[map[v][i]]){
            getdepth(map[v][i],d+1);
        }
    }
    
    return M = max(M,d);
}
