#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 75;

struct query
{
    int x = 0, k = 0, id = 0, ans = 0;
};

int n, m;
int W[MAXN][MAXN], current[MAXN][MAXN], temp[MAXN][MAXN];

vector<query> q;

bool cmp1(query a, query b)
{
    return a.k < b.k;
}

bool cmp2(query a, query b)
{
    return a.id < b.id;
}

void add_k()
{

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            temp[i][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (current[i][k] & W[k][j])
                    temp[i][j] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            current[i][j] = temp[i][j];

    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            W[i][j] = x;
            current[i][j] = x;
        }

    for (int i = 1; i <= m; i++)
    {
        int x, k;
        cin >> x >> k;
        query Q;
        Q.id = i;
        Q.x = x;
        Q.k = k;
        Q.ans = 0;
        q.push_back(Q);
    }

    sort(q.begin(), q.end(), cmp1);

    int now_k = 1;

    for (int i = 0; i <= m - 1; i++)
    {
        while (now_k < q[i].k)
        {
            now_k++;
            add_k();
        }

        for (int j = 1; j <= n; j++)
            if (current[q[i].x][j])
                q[i].ans++;
    }

    sort(q.begin(), q.end(), cmp2);

    for (int i = 1; i <= m; i++)
        cout << q[i - 1].ans << endl;

    return 0;
}