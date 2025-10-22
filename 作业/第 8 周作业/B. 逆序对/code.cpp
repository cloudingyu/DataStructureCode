#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a[100005], tran[100005];

long long inv(int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) >> 1;

    long long ret = inv(l, mid) + inv(mid + 1, r);

    int i = l, j = mid + 1, p = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            tran[p++] = a[i++];
        else
        {
            tran[p++] = a[j++];
            ret += (mid - i + 1);
        }
    }
    while (i <= mid)
        tran[p++] = a[i++];
    while (j <= r)
        tran[p++] = a[j++];

    for (int k = l; k <= r; k++)
        a[k] = tran[k];

    return ret;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << max(inv(1, n) - k, (long long)0) << endl;

    return 0;
}