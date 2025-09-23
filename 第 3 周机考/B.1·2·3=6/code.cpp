#include <iostream>
using namespace std;

int n;

long long a[1000005];

long long b[1000005];

int result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]] = i;
    }

    int cube = 1;
    while (cube * cube * cube < n)
        cube++;
    cube++;

    int sqrt = 1;
    while (sqrt * sqrt < n)
        sqrt++;
    sqrt++;

    for (int i = 1; i <= n - 3; i++)
        if (a[i] < cube)
        {

            for (int j = n; j >= i + 3; j--)
                if (a[j] % a[i] == 0)
                {
                    for (int k = i + 1; k <= j - 2; k++)
                    {
                        if (a[i] < a[k] && a[k] < a[j])
                            if (a[j] % (a[i] * a[k]) == 0)
                                if (a[j] / a[i] / a[k] > a[k])
                                    if (b[a[j] / a[i] / a[k]] > k && b[a[j] / a[i] / a[k]] < j)
                                        result++;
                    }
                }
            /*
            for (int j = i + 1; j <= n-2; j++)
                if(a[j] < sqrt)
                    if (a[j] > a[i] )
                    {
                        for (int k = j + 1; k <= n-1; k++)
                            if (a[i] * a[j] * a[k] <= n)
                                if (a[j] < a[k])
                                    if (b[a[i] * a[j] * a[k]] > k)
                                    {
                                        // cout<<i<<" "<<j<<" "<<k<<endl;
                                        result++;
                                    }
                    }
            */
        }

    cout << result << endl;

    return 0;
}
