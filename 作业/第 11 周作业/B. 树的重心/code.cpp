#include <iostream>
using namespace std;

const int MAXN = 100010;

int head[MAXN], to[MAXN], nxt[MAXN], edge_cnt = 0;
int sz[MAXN];
int parent[MAXN];
int n;

void add_edge(int u, int v)
{
    to[edge_cnt] = v;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}

void dfs(int u, int p)
{
    sz[u] = 1;
    parent[u] = p;
    for (int e = head[u]; e != -1; e = nxt[e])
    {
        int v = to[e];
        if (v == p)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        head[i] = -1;
    }
    edge_cnt = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }

    dfs(1, 0);

    int min_max_comp = n, center_cnt = 0;
    int centers[MAXN];

    for (int u = 1; u <= n; ++u)
    {
        int max_comp = n - sz[u];
        for (int e = head[u]; e != -1; e = nxt[e])
        {
            int v = to[e];
            if (v == parent[u])
                continue;
            if (sz[v] > max_comp)
                max_comp = sz[v];
        }

        if (max_comp < min_max_comp)
        {
            min_max_comp = max_comp;
            center_cnt = 0;
            centers[center_cnt++] = u;
        }
        else if (max_comp == min_max_comp)
            centers[center_cnt++] = u;
    }

    for (int i = 0; i < center_cnt; ++i)
        cout << centers[i] << " ";

    return 0;
}