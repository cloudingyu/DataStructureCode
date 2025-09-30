#include <iostream>
using namespace std;

int n, x;

int a[1000005];

int result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x] = i;
    }

    for (int p1 = 1; p1 <= 100; p1++)
        for (int p2 = p1 + 1; p2 <= 1000; p2++)
            if (a[p2] > a[p1])
            {
                for (int p3 = p2 + 1; p3 <= 1000000 / p1 / p2 + 1; p3++)
                    if (a[p3] > a[p2])
                    {
                        int p4 = p1 * p2 * p3;
                        if (p4 <= n && a[p4] > a[p3])
                            result++;
                    }
            }

    cout << result << endl;

    return 0;
}
