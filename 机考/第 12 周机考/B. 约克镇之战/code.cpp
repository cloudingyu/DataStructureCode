#include <iostream>
using namespace std;

const int MAXN = 1005;
struct Tower
{
    int x, y, r, color;
    bool up, down, right, left;
} tow[MAXN];

int N, M, p, cnt = 0;

int sq(int x)
{
    return x * x;
}

bool ifLink(Tower a, Tower b)
{
    return sq(a.x - b.x) + sq(a.y - b.y) <= sq(a.r + b.r);
}

bool ifCover(Tower a, Tower b)
{
    return ((a.up || a.left) && (b.down || b.right)) || ((b.up || b.left) && (a.down || a.right));
}

void dfs(int u)
{
    for (int v = 1; v <= p; v++)
        if ((u != v) && (tow[v].color == 0) && ifLink(tow[u], tow[v]))
        {
            tow[v].color = tow[u].color;
            dfs(v);
        }
    return;
}

int main()
{
    cin >> N >> M >> p;

    for (int i = 1; i <= p; i++)
    {
        cin >> tow[i].x >> tow[i].y >> tow[i].r;

        tow[i].left = (tow[i].x - tow[i].r <= 0);
        tow[i].down = (tow[i].y - tow[i].r <= 0);
        tow[i].right = (tow[i].x + tow[i].r >= N);
        tow[i].up = (tow[i].y + tow[i].r >= M);

        if (ifCover(tow[i], tow[i]))
        {
            cout << "N" << endl;
            return 0;
        }
    }

    for (int i = 1; i <= p; i++)
        if (!tow[i].color)
        {
            tow[i].color = ++cnt;
            dfs(i);
        }

    for (int i = 1; i <= p; i++)
        for (int j = 1; j <= p; j++)
            if (i != j && tow[i].color == tow[j].color && ifCover(tow[i], tow[j]))
            {
                cout << "N" << endl;
                return 0;
            }
    
    cout << "S" << endl;

    return 0;
}