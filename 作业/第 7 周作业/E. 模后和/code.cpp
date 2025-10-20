#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200005;
int T, n;
long long suma, sumb;
int a[MAXN], b[MAXN];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> T;
    while (T--)
    {
        suma=0;
        sumb=0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] %= n;
            suma += a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            b[i] %= n;
            sumb += b[i];
        }

        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1, cmp);

        int l = 0, r = n;
        while (l != r)
        {
            int mid = (l + r) >> 1;
            int flag = 0;
            for (int i = 1; i <= n - mid; i++)
                if (a[i] + b[i + mid]>= n)
                {
                    flag = 1;
                    break;
                }
            if (flag)
                l = mid + 1;
            else
                r = mid;
        }

        cout << suma + sumb - l * n << endl;
    }
    return 0;
}
