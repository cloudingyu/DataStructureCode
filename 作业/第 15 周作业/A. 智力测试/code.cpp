#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 3005;

struct Edge
{
    int u, v, l, s;
};

int T, n, m;
int dis[MAXN];

vector<Edge> edges;

bool check(int k)
{
    for (int i = 1; i <= n; i++)
        dis[i] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Edge e = edges[j];
            if (dis[e.v] > dis[e.u] + e.s - k * e.l)
                dis[e.v] = dis[e.u] + e.s - k * e.l;
        }
    }

    for (int i = 0; i < m; i++)
    {
        Edge e = edges[i];
        if (dis[e.v] > dis[e.u] + e.s - k * e.l)
            return true;
    }

    return false;
}

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> n >> m;

        edges.clear();

        for (int i = 1; i <= m; i++)
        {
            int u, v, l, s;
            cin >> u >> v >> l >> s;
            edges.push_back({u, v, l, s});
        }

        if (check(70))
            cout << "E" << endl;
        else if (check(90))
            cout << "D" << endl;
        else if (check(110))
            cout << "C" << endl;
        else if (check(120))
            cout << "B" << endl;
        else if (check(140))
            cout << "A" << endl;
        else
            cout << "A+" << endl;
    }

    return 0;
}