#include <iostream>
using namespace std;

const long long LLMAX = 1e15;
int T, n;
long long a[500005],queSum[500005];

void cal()
{
    for (int i = 1; i <= n + 2; i++)
        queSum[i] = LLMAX;

    int t = 1, s = 1, len = 0;
    long long ans = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        long long x, y;
        if (a[t] < queSum[s])
            x = a[t++];
        else
            x = queSum[s++];
        if (a[t] < queSum[s])
            y = a[t++];
        else
            y = queSum[s++];

        ans += x + y;
        queSum[++len] = x + y;
    }

    cout << ans / 2 << ((ans & 1) ? ".5" : ".0") << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = a[n + 2] = LLMAX;    

    cal();

    while (--T)
    {
        int m, u, v;
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v;
            a[u] = v;
        }

        cal();
    }

    return 0;
}