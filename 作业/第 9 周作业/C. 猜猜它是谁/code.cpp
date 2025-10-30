#include <iostream>
using namespace std;

int n, m, posx, posy;
long long a[1005][1005];

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == -1)
            {
                posx = i;
                posy = j;
            }
        }

    cout << a[(posx + 1) % n][posy] + a[posx][(posy + 1) % m] - a[(posx + 1) % n][(posy + 1) % m] << endl;

    return 0;
}