#include <iostream>
using namespace std;

int m, n, x, a[1005];

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x] = 1;
    }

    int sum = m * n;
    int count =0;

    for (int i = sum; i >= 1; i--)
        if (a[i])
        {
            int head = i;
            while (++head <= sum && a[head])
                ;
            if (head != sum + 1)
            {
                a[head]++;
                count++;
            }
        }

    cout << n - count << endl;
    return 0;
}
