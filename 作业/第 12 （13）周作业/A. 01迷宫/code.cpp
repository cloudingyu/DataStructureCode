#include <iostream>
using namespace std;

int n, m;
int a[105][105], mem[105][105];

void memse()
{
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 105; j++)
            mem[i][j] = 0;
}

int dfs(int x, int y)
{
    if (mem[x][y])
        return 0;
    mem[x][y] = 1;

    int ans = 1;

    if (x > 1 && (a[x][y] ^ a[x - 1][y]))
        ans += dfs(x - 1, y);
    if (y > 1 && (a[x][y] ^ a[x][y - 1]))
        ans += dfs(x, y - 1);
    if (x < n && (a[x][y] ^ a[x + 1][y]))
        ans += dfs(x + 1, y);
    if (y < n && (a[x][y] ^ a[x][y + 1]))
        ans += dfs(x, y + 1);

    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }

    while (m--)
    {
        int x, y;
        cin >> x >> y;

        memse();
        cout << dfs(x, y) << endl;
    }

    return 0;
}