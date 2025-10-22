#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int n, r, q, wc, lc;

struct Player
{
    int s, w, id;
} a[MAXN], win[MAXN], lose[MAXN], tmp[MAXN];

bool cmp(const Player a, const Player b)
{
    return ((a.s - b.s) ? a.s > b.s : a.id < b.id);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r >> q;

    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i].s;
        a[i].id = i;
    }
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i].w;

    sort(a + 1, a + 2 * n + 1, cmp);

    while (r--)
    {
        wc = 0, lc = 0;
        for (int i = 1; i <= 2 * n; i += 2)
        {
            Player x = a[i], y = a[i + 1];
            if (x.w > y.w)
            {
                x.s++;
                win[++wc] = x;
                lose[++lc] = y;
            }
            else
            {
                y.s++;
                win[++wc] = y;
                lose[++lc] = x;
            }
        }

        int i = 1, j = 1, p = 1;
        while (i <= wc && j <= lc)
        {
            if (cmp(win[i], lose[j]))
                tmp[p++] = win[i++];
            else
                tmp[p++] = lose[j++];
        }
        while (i <= wc)
            tmp[p++] = win[i++];
        while (j <= lc)
            tmp[p++] = lose[j++];
        
        for (int k = 1; k <= 2 * n; k++)
            a[k] = tmp[k];
    }

    cout << a[q].id << endl;

    return 0;
}