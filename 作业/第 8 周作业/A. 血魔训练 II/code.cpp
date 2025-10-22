#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 5;

int n;
long long x;
int a[MAXN], b[MAXN];

struct Node
{
    int a, b;
} pos[MAXN], neg[MAXN];

int pc = 0, nc = 0;

bool cmpPos(const Node u, const Node v)
{
    return u.a < v.a;
}
bool cmpNeg(const Node u, const Node v)
{
    if (u.b != v.b)
        return u.b > v.b;
    return u.a < v.a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++)
    {
        if (b[i] >= a[i])
            pos[++pc] = {a[i], b[i]};
        else
            neg[++nc] = {a[i], b[i]};
    }

    sort(pos + 1, pos + pc + 1, cmpPos);
    for (int i = 1; i <= pc; i++)
    {
        if (x <= (long long)pos[i].a)
        {
            cout << "NO" << endl;
            return 0;
        }
        x += (long long)pos[i].b - pos[i].a;
    }

    sort(neg + 1, neg + nc + 1, cmpNeg);
    for (int i = 1; i <= nc; i++)
    {
        if (x <= (long long)neg[i].a)
        {
            cout << "NO" << endl;
            return 0;
        }
        x -= (long long)neg[i].a - neg[i].b;
    }

    cout << "YES" << endl;
    return 0;
}