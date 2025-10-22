#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long ans = 0;
long long a[200005], b[200005], sum[200005];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    sort(b + 1, b + m + 1);

    sum[0] = 0;
    for (int i = 1; i <= m; i++)
        sum[i] = sum[i - 1] + b[i];

    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = m;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (a[i] > b[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        ans += (2 * l - m - 2) * a[i] + sum[m] - 2 * sum[l - 1];
    }

    cout << ans << endl;

    return 0;
}