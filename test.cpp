#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 存储空隙信息
struct Gap {
    int len; // 空隙长度
    int u;   // 左侧块的索引
    int v;   // 右侧块的索引
};

// 贪心策略：按空隙长度从小到大排序
bool cmp(const Gap& a, const Gap& b) {
    return a.len < b.len;
}

const int MAXN = 5005;
int parent[MAXN];
long long block_size[MAXN]; // 记录每个集合（连通块）当前的砖块总长度

// 并查集查找
int find_set(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find_set(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    string s;
    cin >> s;

    vector<long long> blocks;
    vector<Gap> gaps;

    // 1. 初始化：添加左边的虚拟块（大小为0），索引为0
    blocks.push_back(0); 

    int i = 0;
    // 检查开头是否有空隙
    if (i < n && s[i] == '.') {
        int len = 0;
        while (i < n && s[i] == '.') {
            len++;
            i++;
        }
        // 连接 虚拟左块(0) 和 第一个真实块(1)
        gaps.push_back({len, 0, 1});
    }

    while (i < n) {
        // 解析真实块 (#)
        int b_len = 0;
        while (i < n && s[i] == '#') {
            b_len++;
            i++;
        }
        if (b_len > 0) {
            blocks.push_back(b_len);
        }

        // 解析空隙 (.)
        if (i < n && s[i] == '.') {
            int g_len = 0;
            while (i < n && s[i] == '.') {
                g_len++;
                i++;
            }
            // 连接 当前最后一个块 和 下一个块
            // 下一个块的索引将是 blocks.size()
            gaps.push_back({g_len, (int)blocks.size() - 1, (int)blocks.size()});
        }
    }

    // 确保所有空隙连接的 '右侧块' 都存在
    // 如果最后一个是空隙，它连接的是 最后一个真实块 和 虚拟右块
    // 我们用 0 填充 vector 直到足够大
    int max_idx = 0;
    for (const auto& g : gaps) max_idx = max(max_idx, g.v);
    while (blocks.size() <= max_idx) {
        blocks.push_back(0); // 添加虚拟块（大小0）
    }

    // 2. 初始化并查集
    for (int k = 0; k < blocks.size(); ++k) {
        parent[k] = k;
        block_size[k] = blocks[k];
    }

    // 3. 排序 + 贪心合并
    sort(gaps.begin(), gaps.end(), cmp);

    long long total_score = 0;

    for (const auto& g : gaps) {
        int root_u = find_set(g.u);
        int root_v = find_set(g.v);

        if (root_u != root_v) {
            long long L = block_size[root_u];
            long long R = block_size[root_v];
            long long k = g.len;

            // 计算得分公式
            long long current_score = k * max(L, R) + min(L, R) + k * (k + 1) / 2;
            total_score += current_score;

            // 合并块
            parent[root_v] = root_u;
            // 更新新块的大小：左块 + 右块 + 填上的空隙
            block_size[root_u] += block_size[root_v] + k;
        }
    }

    cout << total_score << endl;

    return 0;
}