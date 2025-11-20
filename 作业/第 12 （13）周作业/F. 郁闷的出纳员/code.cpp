#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, minSalary, delta, leftCnt;
priority_queue<int, vector<int>, greater<int>> pq;

void removeLowSalary()
{
    while (!pq.empty() && pq.top() + delta < minSalary)
    {
        pq.pop();
        leftCnt++;
    }
}

int getKth(int k)
{
    if (k > pq.size())
        return -1;

    priority_queue<int, vector<int>, greater<int>> backup = pq;

    for (int i = 0; i < pq.size() - k; i++)
        backup.pop();

    return backup.top() + delta;
}

int main()
{
    cin >> n >> minSalary;

    for (int i = 0; i < n; i++)
    {
        char op;
        int k;
        cin >> op >> k;

        if (op == 'I')
        {
            if (k >= minSalary)
            {
                pq.push(k - delta);
            }
        }
        else if (op == 'A')
        {
            delta += k;
        }
        else if (op == 'S')
        {
            delta -= k;
            removeLowSalary();
        }
        else if (op == 'F')
        {
            int result = getKth(k);
            cout << result << endl;
        }
    }

    cout << leftCnt << endl;

    return 0;
}
