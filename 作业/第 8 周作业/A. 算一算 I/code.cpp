#include <iostream>
using namespace std;

const int MAXN = 2005;
int n, s, ans = 0, sum = 0;
int a[MAXN];

void dfs(int k)
{
    if (sum == s && k > n)
        ans++;

    if (sum > s || k > n)
        return;

    for (int i = 0; i <= 1; i++)
    {
        sum += i * a[k];
        dfs(k + 1);
        sum -= i * a[k];
    }

    return;
}

int main()
{
    cin >> n >> s;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dfs(1);

    cout << ans << endl;

    return 0;
}