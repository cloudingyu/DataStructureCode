#include <iostream>
using namespace std;

long long n, k, negSum = 0, posSum = 0, zeroSum = 0, negLast = 0, posLast = 0, zeroLast = 0;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> k;

        if (k > 0)
            posLast++;
        else if (k == 0)
        {
            posLast = 0;
            negLast = 0;
            zeroLast = i;
        }
        else
        {
            negLast += posLast;
            posLast = negLast - posLast;
            negLast = negLast - posLast + 1;
        }

        negSum += negLast;
        zeroSum += zeroLast;
        posSum += posLast;
    }

    cout << negSum << " " << zeroSum << " " << posSum << endl;

    return 0;
}
