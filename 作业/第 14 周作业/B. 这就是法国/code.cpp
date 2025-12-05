#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct node
{
    long long x, y, c, k;
} a[2005];

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

int n, cnt = 0;
long long ans = 0;
int p[2005];

int find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;

    for (int i = 1; i <= n; i++)
        cin >> a[i].c;

    for (int i = 1; i <= n; i++)
        cin >> a[i].k;

    for (int i = 1; i <= n; i++)
        e.push_back({0, i, a[i].c});

    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
            e.push_back({i, j, (a[i].k + a[j].k) * (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y))});

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
            if (++cnt == n)
            {
                cout << ans << endl;
                return 0;
            }
        }
    }
    return 0;
}