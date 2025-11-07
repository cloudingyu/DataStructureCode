#include <iostream>
using namespace std;

const int MAXN = 1e6 + 5;
int n;
int father[MAXN], beauty[MAXN], depth[MAXN];

void getDepth(int k)
{
    if (depth[father[k]] == 0 && father[k] != 1)
        getDepth(father[k]);

    depth[k] = depth[father[k]] + 1;

    return;
}

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
        cin >> father[i];
    for (int i = 1; i <= n; i++)
        cin >> beauty[i];

    depth[1] = 0;
    for (int i = 2; i <= n; i++)
        getDepth(i);

    long long sum_a = 0, sum_depth = 0, sum_a_depth = 0;
    for (int i = 1; i <= n; i++)
    {
        sum_a += beauty[i];
        sum_depth += depth[i];
        sum_a_depth += 1LL * beauty[i] * depth[i];
    }
    long long ans = sum_a_depth + sum_a + sum_depth + n;
    cout << ans << endl;

    return 0;
}