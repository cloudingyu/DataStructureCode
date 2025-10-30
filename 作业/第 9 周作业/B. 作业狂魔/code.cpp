#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans;
int h[2005];

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    sort(h + 1, h + n + 1);

    for (int i = n; i + k > n; i--)
        ans += h[i];

    cout << ans << endl;

    return 0;
}
