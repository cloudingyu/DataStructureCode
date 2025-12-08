#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = 1e18;

struct Edge { int to; ll t, w; };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<Edge>> e(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        ll t, w;
        cin >> u >> v >> t >> w;
        e[u].push_back({v, t, w});
        e[v].push_back({u, t, w});
    }
    
    vector<pll> dist(n + 1, {INF, INF});
    priority_queue<pair<pll, int>, vector<pair<pll, int>>, greater<>> pq;
    
    dist[1] = {0, 0};
    pq.push({{0, 0}, 1});
    
    while (!pq.empty()) {
        auto [tw, u] = pq.top();
        auto [t, w] = tw;
        pq.pop();
        
        if (tw > dist[u]) continue;
        
        for (auto [v, dt, dw] : e[u]) {
            pll new_dist = {t + dt, w + dw};
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
    
    cout << dist[n].first << " " << dist[n].second << endl;
    return 0;
}