#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

int w, h, n, cut;
char type;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> w >> h >> n;

    set<int> cut_h = {0, h};
    set<int> cut_w = {0, w};

    multiset<int> len_h = {h};
    multiset<int> len_w = {w};

    for (int i = 0; i < n; ++i)
    {

        cin >> type >> cut;

        if (type == 'H')
        {
            auto it = cut_h.upper_bound(cut);
            

            int upper = *it;
            int lower = *(--it);
            int old_len = upper - lower;

            auto it_len = len_h.find(old_len);
            len_h.erase(it_len);
            len_h.insert(cut - lower);
            len_h.insert(upper - cut);

            cut_h.insert(cut);
        }
        else
        {
            auto it = cut_w.upper_bound(cut);
            
            int upper = *it;
            int lower = *(--it);
            int old_len = upper - lower;

            auto it_len = len_w.find(old_len);
            len_w.erase(it_len);
            len_w.insert(cut - lower);
            len_w.insert(upper - cut);  

            cut_w.insert(cut);
        }

        ll max_h = *len_h.rbegin();
        ll max_w = *len_w.rbegin();
        cout << max_h * max_w << endl;
    }

    return 0;
}