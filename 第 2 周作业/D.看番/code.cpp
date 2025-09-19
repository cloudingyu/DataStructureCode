#include <iostream>
using namespace std;

int N, X;

int main()
{
    cin >> N >> X;

    int a, b, last = 0, count = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> a >> b;
        count += (a - last-1) % X + b - a + 1;
        last = b;
    }
    cout << count << endl;

    return 0;
}