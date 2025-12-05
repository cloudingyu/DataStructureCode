#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct edge
{
    int u, v;
    long long w;
};

vector<edge> e;

bool cmp(edge Ea, edge Eb)
{
    return Ea.w < Eb.w;
}

int n, m, minp, cnt = 0;
int p[200005];
long long mina = 1e13, ans;
long long a[200005];

int find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < mina)
        {
            mina = a[i];
            minp = i;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }

    for (int i = 1; i <= n; i++)
        e.push_back({i, minp, a[i] + mina});

    sort(e.begin(), e.end(), cmp);

    for (int i = 0; i <= n; i++)
        p[i] = i;

    for (int i = 0; i <= e.size(); i++)
    {
        int fu = find(e[i].u), fv = find(e[i].v);
        if (fu != fv)
        {
            p[fu] = fv;
            ans += e[i].w;
            if (++cnt == n - 1)
            {
                cout << ans << endl;
                return 0;
            }
        }
    }
    return 0;
}