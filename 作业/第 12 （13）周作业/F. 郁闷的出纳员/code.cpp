#include <iostream>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n, min_salary;
int delta;
int total_left;
int id_counter;
ordered_set tr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> min_salary;

    char op;
    int k;

    while (n--)
    {
        cin >> op >> k;
        if (op == 'I')
        {
            if (k >= min_salary)
                tr.insert({k - delta, ++id_counter});
        }
        else if (op == 'A')
        {
            delta += k;
        }
        else if (op == 'S')
        {
            delta -= k;
            int limit_val = min_salary - delta;
            ordered_set keep;
            tr.split({limit_val - 1, 2000000000}, keep);
            total_left += tr.size();
            tr.swap(keep);
        }
        else if (op == 'F')
        {
            if (k > tr.size())
                cout << -1 << endl;
            else
            {
                auto it = tr.find_by_order(tr.size() - k);
                cout << it->first + delta << endl;
            }
        }
    }

    cout << total_left << endl;

    return 0;
}