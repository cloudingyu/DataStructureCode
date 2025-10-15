#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

using i128 = __int128;

std::ostream &operator<<(std::ostream &os, i128 x)
{
    std::string s;
    do
    {
        s.push_back(x % 10 + '0');
        x /= 10;
    } while (x);
    std::reverse(s.begin(), s.end());
    return os << s;
};

const int MAXN = 3e6 + 5;

int n, a[MAXN];
int left_max[MAXN], right_max[MAXN], left_min[MAXN], right_min[MAXN];
int stk[MAXN], top = -1;

void solve()
{

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        left_max[i] = -1;
        right_max[i] = n;
        left_min[i] = -1;
        right_min[i] = n;
    }

    for (int i = 0; i < n; ++i)
    {
        while (top >= 0 && a[stk[top]] <= a[i])
            top--;
        if (top >= 0)
            left_max[i] = stk[top];
        stk[++top] = i;
    }

    top = -1;
    for (int i = n - 1; i >= 0; --i)
    {
        while (top >= 0 && a[stk[top]] < a[i])
            top--;
        if (top >= 0)
            right_max[i] = stk[top];
        stk[++top] = i;
    }

    i128 sum_max = 0;
    for (int i = 0; i < n; ++i)
    {
        long long cnt = (long long)(i - left_max[i]) * (right_max[i] - i);
        sum_max += (i128)a[i] * cnt;
    }

    top = -1;
    for (int i = 0; i < n; ++i)
    {
        while (top >= 0 && a[stk[top]] >= a[i])
            top--;
        if (top >= 0)
            left_min[i] = stk[top];
        stk[++top] = i;
    }

    top = -1;
    for (int i = n - 1; i >= 0; --i)
    {
        while (top >= 0 && a[stk[top]] > a[i])
            top--;
        if (top >= 0)
            right_min[i] = stk[top];
        stk[++top] = i;
    }

    i128 sum_min = 0;
    for (int i = 0; i < n; ++i)
    {
        long long cnt = (long long)(i - left_min[i]) * (right_min[i] - i);
        sum_min += (i128)a[i] * cnt;
    }

    i128 ans = sum_max - sum_min;

    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}