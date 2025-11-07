#include <iostream>
using namespace std;

int n;
int pre[1005], in[1005];

void printPost(int root, int l, int r)
{
    if (l == r)
    {
        cout << pre[root] << " ";
        return;
    }

    int t = l;
    while (in[t] != pre[root])
        t++;

    if (t != l)
        printPost(root + 1, l, t - 1);

    if (t != r)
        printPost(root + t - l + 1, t + 1, r);

    cout << pre[root] << " ";

    return;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> pre[i];
    for (int i = 1; i <= n; i++)
        cin >> in[i];

    printPost(1, 1, n);

    return 0;
}