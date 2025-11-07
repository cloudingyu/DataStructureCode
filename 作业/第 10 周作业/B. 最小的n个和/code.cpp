#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;
int n;
int A[MAXN], B[MAXN];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= n; i++)
        cin >> B[i];

    sort(A + 1, A + n + 1);
    sort(B + 1, B + n + 1);

    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;

    for (int i = 1; i <= n; i++)
        pq.push(make_tuple(A[i] + B[1], i, 1));

    vector<long long> ans;
    for (int k = 1; k <= n; k++)
    {
        auto [sum, i, j] = pq.top();
        pq.pop();

        cout << sum << " ";
        if (j <= n)
            pq.push(make_tuple(A[i] + B[j + 1], i, j + 1));
    }

    return 0;
}