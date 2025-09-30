#include <iostream>
using namespace std;

int x;
int rods[4][55], cnt[4], pos[55];

long long hanoi(int n, int from, int aux, int to)
{
    if (n == 0)
        return 0;
    if (pos[n] == from)
        return hanoi(n - 1, from, to, aux);
    else if (pos[n] == to)
    {
        long long res = hanoi(n - 1, aux, from, to);
        if (res == -1)
            return -1;
        return res + (1LL << (n - 1));
    }
    else
        return -1;
}

int main()
{
    for (int i = 1; i <= 3; i++)
    {
        cin >> cnt[i];
        for (int j = 0; j < cnt[i]; j++)
        {
            cin >> x;
            pos[x] = i;
        }
    }
    int n = cnt[1] + cnt[2] + cnt[3];

    long long steps = hanoi(n, 1, 2, 3);
    if (steps == -1)
        cout << "No" << endl;
    else
        cout << (1LL << n) - 1 - steps << endl;

    return 0;
}