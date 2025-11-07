#include <cstdio>

const int MAXN = 5e6 + 5;

struct Edge
{
    int to, nxt;
} edges[MAXN];

int n, k, fa, edgeCnt = 0;
int guide[MAXN], ans[MAXN], path[MAXN];

void addEdge(int u, int v)
{
    edges[++edgeCnt].to = v;
    edges[edgeCnt].nxt = guide[u];
    guide[u] = edgeCnt;
}

void dfs(int u, int depth)
{
    path[depth] = u;

    if (depth >= k)
        ++ans[path[depth - k]];

    for (int e = guide[u]; e != 0; e = edges[e].nxt)
        dfs(edges[e].to, depth + 1);
}

int main()
{
    scanf("%d%d", &n, &k);

    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &fa);
        addEdge(fa, i);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);

    return 0;
}