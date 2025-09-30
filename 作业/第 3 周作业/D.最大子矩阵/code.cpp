#include <iostream>
#include <algorithm>
using namespace std;

int n, maxSum = -128, maxN = -128;
int A[105][105], prefixSum[105][105];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
            prefixSum[i][j] = prefixSum[i][j - 1] + A[i][j];
            maxN = max(maxN, A[i][j]);
        }

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            int currentSum = 0;
            for (int k = 1; k <= n; k++)
            {
                currentSum = max(0, currentSum + prefixSum[k][j] - prefixSum[k][i - 1]);
                maxSum = max(maxSum, currentSum);
            }
        }

    cout << (maxN > 0 ? maxSum : maxN) << endl;
    return 0;
}