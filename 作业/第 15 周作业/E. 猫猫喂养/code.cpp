#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

struct Squad
{
    priority_queue<pair<int, int>> static_pq;
    priority_queue<pair<int, int>> decaying_pq;
};

Squad squads[MAXN];
int parent[MAXN];
int hunger[MAXN];
int ans;
vector<int> decaying_cats;

int find_set(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q))
        return 0;

    ans = n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> hunger[i];
        parent[i] = i;
        squads[i].static_pq.push({hunger[i], i});
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            int rx = find_set(x);
            int ry = find_set(y);

            if (rx != ry)
            {
                size_t size_x = squads[rx].static_pq.size() + squads[rx].decaying_pq.size();
                size_t size_y = squads[ry].static_pq.size() + squads[ry].decaying_pq.size();

                if (size_x > size_y)
                    swap(rx, ry);

                parent[rx] = ry;

                while (!squads[rx].static_pq.empty())
                {
                    squads[ry].static_pq.push(squads[rx].static_pq.top());
                    squads[rx].static_pq.pop();
                }
                while (!squads[rx].decaying_pq.empty())
                {
                    squads[ry].decaying_pq.push(squads[rx].decaying_pq.top());
                    squads[rx].decaying_pq.pop();
                }
            }
        }
        else
        {
            int x;
            cin >> x;
            int root = find_set(x);

            while (!squads[root].decaying_pq.empty())
            {
                auto top = squads[root].decaying_pq.top();
                if (hunger[top.second] != top.first)
                {
                    squads[root].decaying_pq.pop();
                }
                else
                {
                    break;
                }
            }

            int cand_static = -1, val_static = -1;
            int cand_decay = -1, val_decay = -1;

            if (!squads[root].static_pq.empty())
            {
                val_static = squads[root].static_pq.top().first;
                cand_static = squads[root].static_pq.top().second;
            }
            if (!squads[root].decaying_pq.empty())
            {
                val_decay = squads[root].decaying_pq.top().first;
                cand_decay = squads[root].decaying_pq.top().second;
            }

            int chosen_id = -1;
            bool from_static = false;

            if (val_static == -1 && val_decay == -1)
            {
            }
            else if (val_static > val_decay)
            {
                chosen_id = cand_static;
                from_static = true;
            }
            else if (val_decay > val_static)
            {
                chosen_id = cand_decay;
                from_static = false;
            }
            else
            {
                chosen_id = cand_static;
                from_static = true;
            }

            if (chosen_id != -1)
            {
                if (from_static)
                {
                    squads[root].static_pq.pop();
                    decaying_cats.push_back(chosen_id);
                }
                else
                {
                    squads[root].decaying_pq.pop();
                }
            }
        }

        vector<int> next_decaying;
        for (int id : decaying_cats)
        {
            if (hunger[id] == 0)
                continue;

            hunger[id] /= 2;

            if (hunger[id] > 0)
            {
                next_decaying.push_back(id);
                int r = find_set(id);
                squads[r].decaying_pq.push({hunger[id], id});
            }
            else
            {
                ans--;
            }
        }
        decaying_cats = next_decaying;

        cout << ans << "\n";
    }

    return 0;
}