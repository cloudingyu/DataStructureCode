#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long n, m, t, ans = 0;
priority_queue<int, vector<int>> pq;

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        pq.push(t);
    }

    for (int i = 1; i <= m; i++)
    {
        int c = pq.top();
        pq.pop();
        pq.push(c >> 1);
    }

    for (int i = 1; i <= n; i++)
    {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;

    return 0;
}
