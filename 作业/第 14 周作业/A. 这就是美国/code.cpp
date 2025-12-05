#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge
{
    int u, v, a, b;
} e[10005];

int n, m, S, T, cnt, max_b;
int p[5005];
long long ans = -1;

vector<edge> active_edges;

bool cmp(edge Ea, edge Eb)
{
    return Ea.a < Eb.a;
}

int find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

int main()
{
    cin >> n >> m >> S >> T;

    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].a >> e[i].b;

    sort(e + 1, e + m + 1, cmp);

    for (int i = 1; i <= m; i++)
    {
        int pos = 0;
        while (pos < active_edges.size() && active_edges[pos].b < e[i].b)
        {
            pos++;
        }
        active_edges.insert(active_edges.begin() + pos, e[i]);

        if (active_edges.size() < n - 1)
            continue;

        for (int j = 1; j <= n; j++)
            p[j] = j;

        cnt = 0;
        max_b = 0;

        for (int j = 0; j < active_edges.size(); j++)
        {
            int fu = find(active_edges[j].u), fv = find(active_edges[j].v);
            if (fu != fv)
            {
                p[fu] = fv;
                max_b = active_edges[j].b;
                if (++cnt == n - 1)
                    break;
            }
        }

        if (cnt == n - 1)
        {
            long long cost = (long long)e[i].a * S + (long long)max_b * T;
            if (ans == -1 || cost < ans)
                ans = cost;
        }
    }

    cout << ans << endl;
    return 0;
}