#include <iostream>
#include <string>
using namespace std;

int n, m, len, tx, ty, ans = 0;
int mapp[405][405];
string row[405], path;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> row[i];
        for (int j = 1; j <= m; j++)
        {
            if (row[i][j - 1] == '.')
                mapp[i][j] = 0;
            else if (row[i][j - 1] == '@')
            {
                mapp[i][j] = 2;
                tx = i;
                ty = j;
            }
            else
                mapp[i][j] = 1;
        }
    }

    cin >> path;

    int len = path.length();

    for (int i = 0; i < len; i++)
    {
        if (path[i] == 'W')
            tx--;
        else if (path[i] == 'A')
            ty--;
        else if (path[i] == 'S')
            tx++;
        else
            ty++;

        if (tx == 0 || tx == n + 1 || ty == 0 || ty == m + 1)
        {
            cout << "GG" << endl;
            return 0;
        }
        if (mapp[tx][ty] == 1)
        {
            ans++;
            mapp[tx][ty]--;
        }
    }

    cout << ans << endl;

    return 0;
}