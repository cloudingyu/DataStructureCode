#include <iostream>
#include <algorithm>
using namespace std;

struct Station
{
    int v, id;
} a[1005];

bool cmp(Station a, Station b)
{
    return a.v > b.v;
}

int n, m;
int flow_v[1005], visited[1005], e[1005][1005];
long long total = 0;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> flow_v[i];
        a[i].v = flow_v[i];
        a[i].id = i;
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u][v] = 1;
        e[v][u] = 1;
    }

    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        int u = a[i].id;
        visited[u] = 1;

        for (int v = 1; v <= n; v++)
            if (e[u][v] && !visited[v])
                total += flow_v[v];
        
    }
    cout << total << endl;
    return 0;
}