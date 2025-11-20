#include <iostream>
using namespace std;

const int MAXN = 1000005;

int n, q,clk = 0;
int head[MAXN], to[MAXN * 2], nxt[MAXN * 2], edge_cnt;
int parent[MAXN];
int L[MAXN], R[MAXN], seq[MAXN];
int color[MAXN];

int op_type[MAXN], op_x[MAXN], op_y[MAXN];

int fseq[MAXN];
int ftree[MAXN];

void add_edge(int u, int v)
{
    to[++edge_cnt] = v;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt;
}

void dfs(int u)
{
    L[u] = ++clk;
    seq[clk] = u;
    for (int e = head[u]; e; e = nxt[e])
    {
        int v = to[e];
        dfs(v);
    }
    R[u] = clk;
}

int find_seq(int x)
{
    if (fseq[x] == x)
        return x;
    fseq[x] = find_seq(fseq[x]);
    return fseq[x];
}

int find_tree(int x)
{
    if (ftree[x] == x)
        return x;
    ftree[x] = find_tree(ftree[x]);
    return ftree[x];
}

int main()
{
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int fa;
        cin >> fa;
        add_edge(fa, i);
        parent[i] = fa;
    }
    parent[1] = 0;

    dfs(1);

    for (int i = 1; i <= q; i++)
        cin >> op_type[i] >> op_x[i] >> op_y[i];

    for (int i = 0; i <= n + 1; i++)
    {
        fseq[i] = i;
        ftree[i] = i;
    }

    for (int i = q; i >= 1; i--)
    {
        int x = op_x[i];
        int y = op_y[i];

        if (op_type[i] == 1)
        {
            for (int k = find_seq(L[x]); k <= R[x]; k = find_seq(k))
            {
                int u = seq[k];
                color[u] = y;

                fseq[k] = find_seq(k + 1);
                ftree[u] = find_tree(parent[u]);
            }
        }
        else
        {
            int u = find_tree(x);
            while (u != 0)
            {
                color[u] = y;
                int k = L[u];

                fseq[k] = find_seq(k + 1);
                ftree[u] = find_tree(parent[u]);

                u = find_tree(u);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << color[i] << " ";

    return 0;
}
