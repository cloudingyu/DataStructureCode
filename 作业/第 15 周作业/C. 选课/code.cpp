#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 2005;

int n, m, k;
int p[MAXN], degree[MAXN];
vector<int> adj[MAXN];

int main()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        cin >> p[i];

    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        degree[v]++;
    }

    priority_queue<pair<int, int>> pq;

    for (int i = 1; i <= n; i++)
        if (degree[i] == 0)
            pq.push({p[i], i});

    vector<int> result;

    while (!pq.empty())
    {
        pair<int, int> current = pq.top();
        pq.pop();

        int u = current.second;

        result.push_back(u);
        for (int v : adj[u])
            if (!--degree[v])
                pq.push({p[v], v});
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    return 0;
}