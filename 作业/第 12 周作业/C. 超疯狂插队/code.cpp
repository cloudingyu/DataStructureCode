#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 2000005;
int n;
int a[MAXN];
int k[MAXN];
int tree[MAXN * 4];

void update(int node, int start, int end, int pos, int val)
{
    if (start == end)
    {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (pos <= mid)
        update(node * 2, start, mid, pos, val);
    else
        update(node * 2 + 1, mid + 1, end, pos, val);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int start, int end, int L, int R, int val, int &limit)
{
    if (start > R || end < L || tree[node] <= val)
    {
        return 0;
    }

    if (start == end)
    {
        limit--;
        if (limit == -1)
            return start;
        return 0;
    }

    int mid = (start + end) / 2;
    int res = 0;

    if (mid < R)
    {
        res = query(node * 2 + 1, mid + 1, end, L, R, val, limit);
        if (res != 0)
            return res;
    }

    if (start <= R)
    {
        res = query(node * 2, start, mid, L, R, val, limit);
    }

    return res;
}

int main()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> k[i];

    for (int i = 1; i <= n; i++)
        update(1, 1, n, i, a[i]);

    for (int i = 1; i <= n; i++)
    {
        int target_pos = 1;

        if (i > 1)
        {
            int limit = k[i];
            int pos = query(1, 1, n, 1, i - 1, a[i], limit);
            if (pos != 0)
                target_pos = pos + 1;
        }

        cout << target_pos << " ";
    }
    cout << endl;

    return 0;
}