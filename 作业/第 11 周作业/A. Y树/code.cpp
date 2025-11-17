#include <iostream>
using namespace std;

const int MAXN = 2000010;

int head[MAXN], to[MAXN], nxt[MAXN], edge_cnt = 0;
int sz[MAXN];
int parent[MAXN];
int parts_buf[MAXN];
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
    for (int i = 0; i < MAXN; ++i)
        head[i] = -1;

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }

    if (n < 3)
    {
        cout << 0 << endl;
        return 0;
    }

    dfs(1, 0);

    long long total = 0;

    for (int u = 1; u <= n; ++u)
    {
        int cnt = 0;
        for (int e = head[u]; e != -1; e = nxt[e])
        {
            int v = to[e];
            parts_buf[cnt++] = (v == parent[u]) ? n - sz[u] : sz[v];
        }

        if (cnt < 3)
            continue;

        long long sum = 0,pair_sum = 0,triple_sum = 0;
        for (int i = 0; i < cnt; ++i)
        {
            long long x = parts_buf[i];
            triple_sum += x * pair_sum;
            pair_sum += x * sum;
            sum += x;
        }
        total += triple_sum;
    }

    cout << total << endl;
    return 0;
}