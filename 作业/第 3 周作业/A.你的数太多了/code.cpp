#include <iostream>
using namespace std;

int n, l = 0, t, r;

int main()
{
    cin >> n >> t;
    for (int i = 2; i <= n; i++)
    {
        cin >> r;
        if (t != l && t != r)
            cout << t << " ";
        l = t;
        t = r;
    }

    if (l != t)
        cout << t << endl;

    return 0;
}