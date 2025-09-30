#include <iostream>
using namespace std;

long long a, b, x, y, n;

long long da, db;

int main()
{
    cin >> a >> b >> x >> y >> n;

    da = min(n, a - x);
    db = min(n, b - y);

    cout << min(
                (a - da) * max(b - (n - da), y),
                (b - db) * max(a - (n - db), x))
         << endl;

    return 0;
}