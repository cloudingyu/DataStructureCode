#include <iostream>
using namespace std;

const int MAXN = 5e6 + 5;

int n, k;
int head[MAXN], to[MAXN], nxt[MAXN];
int ans[MAXN];

int stackNode[MAXN], stackEdge[MAXN];
unsigned char stackEntered[MAXN];

int edgeCnt = 0;

inline void add_edge(int u, int v)
{
    to[++edgeCnt] = v;
    nxt[edgeCnt] = head[u];
    head[u] = edgeCnt;
}

int main()
{

    cin >> n >> k;
    fill(head, head + n + 1, -1);

    for (int i = 2; i <= n; ++i)
    {
        int fa;
        cin >> fa;
        add_edge(fa, i);
    }

    int sp = 0;
    stackNode[0] = 1;
    stackEdge[0] = head[1];
    stackEntered[0] = 0;

    while (sp >= 0)
    {
        int u = stackNode[sp];

        if (!stackEntered[sp])
        {
            stackEntered[sp] = 1;
            if (sp >= k)
            {
                int ancestor = stackNode[sp - k];
                ++ans[ancestor];
            }
        }

        int e = stackEdge[sp];
        if (e != -1)
        {
            stackEdge[sp] = nxt[e];
            int v = to[e];
            stackNode[++sp] = v;
            stackEdge[sp] = head[v];
            stackEntered[sp] = 0;
        }
        else
        {
            --sp;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (i > 1)
            cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}