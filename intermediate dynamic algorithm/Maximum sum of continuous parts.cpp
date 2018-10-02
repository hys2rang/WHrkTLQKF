#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> d;
int main()
{
    cin>>n;
    arr.resize(n);
    d.resize(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    d[0] = arr[0];

    for(int i=1;i<n;i++){
        if(d[i-1]+arr[i] > arr[i]){
            d[i] = d[i-1]+arr[i];
        }else{
            d[i] = arr[i];
        }
    }

    int m = d[0];

    for(int i=1;i<n;i++){
        m = max(m,d[i]);
    }

    cout<<m;
    return 0;
}
