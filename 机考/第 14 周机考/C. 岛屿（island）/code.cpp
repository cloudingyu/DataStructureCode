#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAXN = 200005;

int n, m;
int a[MAXN], cnt[MAXN], fa[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq[MAXN];

int find(int x)
{
    if(x==fa[x])
        return x;
    fa[x]=find(fa[x]);
    return fa[x];
}

int get_valid_node(int root)
{
    while (!pq[root].empty())
    {
        int u = pq[root].top().second;
        if (cnt[u] == 3)
            pq[root].pop();
        else
            return u;
    }
    return -1;
}

void merge_heaps(int fx, int fy)
{
    if (pq[fx].size() > pq[fy].size())
        swap(pq[fx], pq[fy]);

    while (!pq[fx].empty())
    {
        pq[fy].push(pq[fx].top());
        pq[fx].pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        fa[i] = i;
        cnt[i] = 0;
        pq[i].push({a[i], i});
    }

    long long total_cost = 0;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        int fx = find(x);
        int fy = find(y);

        if (fx != fy)
        {
            int u = get_valid_node(fx);
            int v = get_valid_node(fy);

            total_cost += (long long)a[u] + a[v];
            cnt[u]++;
            cnt[v]++;

            fa[fx] = fy;

            merge_heaps(fx, fy);

            cout << "yes" <<endl;
        }
        else
            cout << "no"<<endl;
    }

    cout << total_cost << endl;

    return 0;
}