#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 100010;
vector<int> g[N];
int n;

pair<int, int> bfs(int s)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    int last = s;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        last = u;
        for (int v : g[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {last, dist[last]};
}

int main()
{

    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    auto [u, _] = bfs(1);
    auto [v, diam] = bfs(u);

    cout << 2 * (n - 1) - diam << endl;
    return 0;
}