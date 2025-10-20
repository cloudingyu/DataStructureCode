#include <iostream>
using namespace std;

const int MAXN = 1e6 + 5;
int n, a, b, lastans = 0, op, v, len = -1;
int stk[MAXN], posstk[MAXN], top = -1;
int num[MAXN], leftsup[MAXN];
long long ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    while (n--)
    {
        cin >> a >> b;

        op = lastans ^ a;
        v = lastans ^ b;

        if (op == 1)
        {
            ++len;
            while (top >= 0 && stk[top] <= v)
                --top;
            stk[++top] = v;
            posstk[top] = len;
        }
        else
        {
            int L = len - v + 1;
            int l = 0, r = top, res = top;
            
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (posstk[mid] >= L)
                {
                    res = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            lastans = stk[res];
            ans += lastans;
        }
    }
    cout << ans << endl;
    return 0;
}
