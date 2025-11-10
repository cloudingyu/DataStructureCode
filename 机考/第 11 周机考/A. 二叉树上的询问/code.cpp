#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m;
long long n;

long long subtreeSize(long long root, long long n)
{
    if (root > n)
        return 0;

    long long size = 0, low = root, high = root;
    while (low <= n)
    {
        size += min(high, n) - low + 1;
        if (low > n / 2)
            break;
        low <<= 1;
        high = (high > (n - 1) / 2) ? n : ((high << 1) + 1);
    }

    return size;
}

int main()
{

    cin >> n >> m;

    while (m--)
    {
        long long node, sum = 0;
        cin >> node;

        while (node > 0)
        {
            if (node > 1 && (node & 1))
                sum += subtreeSize(node - 1, n);
            node >>= 1;
            sum += 1;
        }

        cout << sum << endl;
    }

    return 0;
}