#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int to;
    int w;
};

vector<Edge> adj[MAXN];
int dist[MAXN];
int n, m,q,s;

int stk_back[MAXN * 2],stk_front[MAXN * 2];
int top_back = 0,top_front = 0;

void push_back(int val)
{
    stk_back[++top_back] = val;
}

void push_front(int val)
{
    stk_front[++top_front] = val;
}

int popp()
{
    if (top_front > 0)
        return stk_front[top_front--];
    while (top_back > 0)
        stk_front[++top_front] = stk_back[top_back--];
    return stk_front[top_front--];
}

bool empty()
{
    return top_back == 0 && top_front == 0;
}

long long solve(int start_node)
{
    for (int i = 1; i <= n; ++i)
        dist[i] = INF;

    top_back = top_front = 0;
    

    dist[start_node] = 0;
    push_front(start_node);

    while (!empty())
    {
        int u = popp();

        for (auto &e : adj[u])
        {
            int v = e.to;
            int w = e.w;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                if (w == 0)
                    push_front(v);
                else
                    push_back(v);
            }
        }
    }

    long long total = 0;
    for (int i = 1; i <= n; ++i)
        total += dist[i];

    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    cin >> q;
    while (q--)
    {
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}