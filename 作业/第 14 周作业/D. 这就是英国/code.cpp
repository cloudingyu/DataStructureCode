#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int flow_v[1005];

int main()
{
    cin>>n>>m;

    for (int i = 1; i <= n; i++)
        cin >> flow_v[i];

    long long total = 0; 
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        total += min(flow_v[u], flow_v[v]);
    }

    cout << total << endl;
    
    return 0;
}