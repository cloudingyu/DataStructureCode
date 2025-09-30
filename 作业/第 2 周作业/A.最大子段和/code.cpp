#include <iostream>
#include <climits>
using namespace std;

long long n, x, maxN = INT_MIN, maxSum, currentSum;

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        currentSum = max((long long)0, currentSum + x);

        maxSum = max(maxSum, currentSum);

        maxN = max(maxN, x);
    }

    cout << (maxN > 0 ? maxSum : maxN) << endl;

    return 0;
}