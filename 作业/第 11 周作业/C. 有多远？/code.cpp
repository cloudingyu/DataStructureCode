#include <iostream>
using namespace std;

const int MAXN = 40005;
const int MAXM = 80010;

int head[MAXN], to[MAXM], nxt[MAXM], weight[MAXM], edge_cnt = 0;
long long dist[MAXN];
int depth[MAXN];
int parent[MAXN];
int n, m;

void add_edge(int u, int v, int c)
{
    to[edge_cnt] = v;
    weight[edge_cnt] = c;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}

void dfs(int u, int p, int d)
{
    parent[u] = p;
    depth[u] = d;
    for (int e = head[u]; e != -1; e = nxt[e])
    {
        int v = to[e];
        if (v == p)
            continue;
        dist[v] = dist[u] + weight[e];
        dfs(v, u, d + 1);
    }
}

int lca(int a, int b)
{
    while (depth[a] > depth[b])
        a = parent[a];
    while (depth[b] > depth[a])
        b = parent[b];
    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        head[i] = -1;

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        add_edge(x, y, c);
        add_edge(y, x, c);
    }

    dist[1] = 0;
    dfs(1, 0, 0);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        long long ans = dist[a] + dist[b] - 2 * dist[p];
        cout << ans << endl;
    }

    return 0;
}