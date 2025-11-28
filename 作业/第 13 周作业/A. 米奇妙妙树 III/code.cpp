#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

int n, q;
vector<int> adj[MAXN];
vector<pair<int, int>> query_vec[MAXN];

int father[MAXN], dep[MAXN], color[MAXN];
int lca_res[MAXN];

int p_tarjan[MAXN];
int p_paint[MAXN];
bool visited[MAXN];

struct Query
{
    int x, y, c;
} queries[MAXN];

int find_paint(int x)
{
    if (p_paint[x] == x)
        return x;
    return p_paint[x] = find_paint(p_paint[x]);
}

int find_tarjan(int x)
{
    if (p_tarjan[x] == x)
        return x;
    return p_tarjan[x] = find_tarjan(p_tarjan[x]);
}

void dfs(int u, int fa)
{
    father[u] = fa;
    dep[u] = dep[fa] + 1;
    p_tarjan[u] = u;

    for (int v : adj[u])
    {
        if (v != fa)
        {
            dfs(v, u);
            p_tarjan[v] = u;
        }
    }

    visited[u] = true;

    for (auto &q_pair : query_vec[u])
    {
        int v = q_pair.first;
        int id = q_pair.second;
        if (visited[v])
        {
            lca_res[id] = find_tarjan(v);
        }
    }
}

void paint(int u, int lca, int c)
{
    u = find_paint(u);

    while (dep[u] >= dep[lca])
    {
        if (color[u] == 0)
            color[u] = c;

        if (u == 0) break;

        int fa = father[u];
        p_paint[u] = find_paint(fa);

        u = p_paint[u];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> n >> q)) return 0;

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> queries[i].x >> queries[i].y >> queries[i].c;
        query_vec[queries[i].x].push_back({queries[i].y, i});
        query_vec[queries[i].y].push_back({queries[i].x, i});
    }

    dfs(1, 0);

    for (int i = 0; i <= n; ++i)
        p_paint[i] = i;

    for (int i = q - 1; i >= 0; --i)
    {
        int x = queries[i].x, y = queries[i].y, c = queries[i].c;
        int lca = lca_res[i];

        paint(x, lca, c);
        paint(y, lca, c);
    }

    for (int i = 1; i <= n; ++i)
        cout << color[i] << " ";

    return 0;
}