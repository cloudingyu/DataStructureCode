#include <iostream>
using namespace std;

int n, k, x, last = 0, res = 0;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x + last <= k)
            last += x;
        else
        {
            last = x;
            res++;
        }
    }
    cout << res + 1 << endl;
    return 0;
}