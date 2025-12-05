#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
#include <algorithm>

using namespace std;

using ll = long long;
const ll INF = numeric_limits<ll>::max();

struct Edge
{
    int to;
    ll t, w;
};

struct State
{
    ll t, w;
    int u;

    bool operator>(const State &other) const
    {
        if (t != other.t)
            return t > other.t;
        return w > other.w;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> e(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll t, w;
        cin >> u >> v >> t >> w;
        e[u].push_back({v, t, w});
        e[v].push_back({u, t, w});
    }

    vector<pair<ll, ll>> dist(n + 1, {INF, INF});

    priority_queue<State, vector<State>, greater<State>> pq;

    dist[1] = {0, 0};
    pq.push({0, 0, 1});

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();

        ll t_curr = current.t;
        ll w_curr = current.w;
        int u = current.u;

        if (t_curr > dist[u].first || (t_curr == dist[u].first && w_curr > dist[u].second))
            continue;

        for (const auto &edge : e[u])
        {
            int v = edge.to;
            ll t_uv = edge.t;
            ll w_uv = edge.w;

            ll t_new = t_curr + t_uv;
            ll w_new = w_curr + w_uv;

            if (t_new < dist[v].first)
            {
                dist[v] = {t_new, w_new};
                pq.push({t_new, w_new, v});
            }
            else if (t_new == dist[v].first)
            {
                if (w_new < dist[v].second)
                {
                    dist[v] = {t_new, w_new};
                    pq.push({t_new, w_new, v});
                }
            }
        }
    }

    cout << dist[n].first << " " << dist[n].second << endl;

    return 0;
}