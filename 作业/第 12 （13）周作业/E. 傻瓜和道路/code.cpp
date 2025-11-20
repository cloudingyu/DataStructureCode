#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int LOGN = 18;

int n, k;
vector<int> adj[MAXN];
pair<int, int> edges[MAXN];
int parent[MAXN], depth[MAXN], diff[MAXN], up[MAXN][LOGN];

void dfs(int u, int p)
{
    parent[u] = p;
    up[u][0] = p;
    depth[u] = depth[p] + 1;
    for (int v : adj[u])
        if (v != p)
            dfs(v, u);

    return;
}

void init_lca()
{
    for (int j = 1; j < LOGN; j++)
        for (int i = 1; i <= n; i++)
            if (up[i][j - 1] != 0)
                up[i][j] = up[up[i][j - 1]][j - 1];
}

int lca(int a, int b)
{

    if (depth[a] < depth[b])
        swap(a, b);

    int diff_depth = depth[a] - depth[b];
    for (int j = 0; j < LOGN; j++)
    {
        if ((diff_depth >> j) & 1)
        {
            a = up[a][j];
        }
    }

    if (a == b)
        return a;

    for (int j = LOGN - 1; j >= 0; j--)
    {
        if (up[a][j] != up[b][j])
        {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0];
}

void dfs_sum(int u, int p)
{
    for (int v : adj[u])
        if (v != p)
        {
            dfs_sum(v, u);
            diff[u] += diff[v];
        }
}

int main()
{

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }

    depth[0] = 0;
    dfs(1, 0);

    init_lca();
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);

        diff[a]++;
        diff[b]++;
        diff[l] -= 2;
    }

    dfs_sum(1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        int child = (depth[u] > depth[v]) ? u : v;

        cout << diff[child] << " ";
    }

    return 0;
}