#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

struct Edge
{
    int u, v;
};

vector<Edge> edges;

int n, m, ans = -1;

bool check(int k)
{
    int cnt = 0;
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < k; i++)
    {
        adj[edges[i].u].push_back(edges[i].v);
        degree[edges[i].v]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (degree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        if (q.size() > 1)
            return false;

        int u = q.front();
        q.pop();
        cnt++;

        for (int v : adj[u])
            if (!--degree[v])
                q.push(v);
    }

    return cnt == n;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int l = 1, r = m;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans << endl;

    return 0;
}