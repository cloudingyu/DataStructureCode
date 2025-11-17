#include <iostream>
using namespace std;

const int MAXN = 1e6 + 5;

int n, q;
int father[MAXN], stack[MAXN][2], color[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 2; i <= n; i++)
        cin >> father[i];

    for (int i = 1; i <= q; i++)
        cin >> stack[i][0] >> stack[i][1];

    for (int i = q; i >= 1; i--)
        for (int x = stack[i][0], y = stack[i][1]; color[x] == 0 && x >= 1; x = father[x])
            color[x] = y;

    for (int i = 1; i <= n; i++)
        cout << color[i] << " ";

    return 0;
}