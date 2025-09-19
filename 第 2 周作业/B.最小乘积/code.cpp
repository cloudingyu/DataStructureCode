#include <iostream>
using namespace std;

int a, b, x, y, n;

int main()
{
    cin >> a >> b >> x >> y >> n;

    int min_product = INT_MAX;

    for (int i = 0; i <= n; i++)
    {
        int j = n - i;
        min_product = min(min_product, (a + i) * (b + j));
    }

    cout << min_product << endl;

    return 0;
}