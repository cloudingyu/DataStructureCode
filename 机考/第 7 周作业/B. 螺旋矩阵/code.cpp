#include <iostream>
using namespace std;

int n, m, dir = 1, posx = 1, posy = 1;
int ans[105][105];
int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m * n; i++)
    {
        ans[posx][posy] = i;

        if (dir == 1)
        {
            if (posy == m - posx + 1)
                dir = 2, posx++;
            else
                posy++;
        }
        else if (dir == 2)
        {
            if (posx - posy == n - m)
                dir = 3, posy--;
            else
                posx++;
        }
        else if (dir == 3)
        {
            if (posx + posy == n + 1)
                dir = 4, posx--;
            else
                posy--;
        }
        else if (dir == 4)
        {
            if (posx == posy + 1)
                dir = 1, posy++;
            else
                posx--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}