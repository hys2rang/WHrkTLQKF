/*
문제
트리가 주어지고, 두 노드 X, Y가 주어질 때, 이 두 노드 사이의 거리를 출력하는 프로그램을 작성하시오. 
트리에서는 두 노드를 잇는 경로가 유일하기 때문에, 정답은 항상 유일하다는 것을 참고한다. 
예를 들어, 다음과 같은 트리에서 노드 3, 노드 6 사이의 거리는 4이다.

입력
첫 번째 줄에 트리의 노드 개수 n, 두 노드 X, Y의 번호가 주어진다. ( 1 ≤ X, Y ≤ n ≤ 1000 ) 두 번째 줄부터 트리의 간선 정보가 주어진다. 
각 줄은 2개의 숫자 a, b로 이루어지며, 이는 노드 a가 노드 b의 부모노드라는 것을 의미한다. 루트는 노드 0이라고 가정한다.  

출력
두 노드 X, Y 사이의 거리를 출력한다.

예제 입력
11 3 6
0 1
0 2
1 3
1 4
1 5
2 6
2 10
6 7
6 8
6 9
예제 출력
4
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree
{
    int parent;
    vector<int> child;
    void create(int x)
    {
        child.resize(x + 1);
    }
    void push(int x)
    {
        child.push_back(x);
    }
    int getparent()
    {
        return parent;
    }
};
Tree tree[1000];

int main()
{
    int x, y;
    int n;
    int len = 0;
    int ans;
    int cnt =0;
    bool sp = false;
    
    vector<int> parents;

    cin >> n >> x >> y;

    for (int i = 0; i < n + 1; i++)
    {
        tree[i].create(n + 1);
    }

    parents.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[b].parent = a;
        tree[a].push(b);
    }

    int a = x;
    while (a>0)
    {
        parents[len++] = a;
        a = tree[a].parent;
    }
    while (!sp)
    {
        for (int i = 0; i < len+1; i++)
        {
            if (y == parents[i])
            {
                ans = parents[i];
                sp = true;
                break;
            }
        }
        y = tree[y].parent;
        cnt++;
    }
    for(int i=0;parents[i]!=ans;i++){
        cnt++;
    }

    cout<<cnt-1;

    return 0;
}
