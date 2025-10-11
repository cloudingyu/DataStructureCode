#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 全局变量存储结果
vector<string> result;
bool found;
int n_global, m_global;

// 检查在位置(row, col)放置value是否合法
bool isValid(const vector<string> &matrix, int row, int col, char value)
{
    // 检查所有之前的行和列组合
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == value &&
                matrix[i][col] == value &&
                matrix[row][j] == value)
            {
                return false;
            }
        }
    }
    return true;
}

// DFS函数，按字典序尝试填0和1
void dfs(vector<string> &matrix, int pos)
{
    if (found)
        return;

    if (pos == n_global * m_global)
    {
        // 找到解
        result = matrix;
        found = true;
        return;
    }

    int row = pos / m_global;
    int col = pos % m_global;

    // 优先尝试0（保证字典序最小）
    if (isValid(matrix, row, col, '0'))
    {
        matrix[row][col] = '0';
        dfs(matrix, pos + 1);
        if (found)
            return;
    }

    // 如果0不行，尝试1
    if (isValid(matrix, row, col, '1'))
    {
        matrix[row][col] = '1';
        dfs(matrix, pos + 1);
        if (found)
            return;
    }
}

void func(int n, int m)
{
    n_global = n;
    m_global = m;
    found = false;

    // 初始化矩阵
    vector<string> matrix(n, string(m, '0'));

    // 开始DFS
    dfs(matrix, 0);

    if (found)
    {
        cout << "else if(n == " << n << " && m == " << m << ") " << endl;
        cout << "{" << endl;

        for (const string &row : result)
        {
            cout << "    cout<<\""<<row << "\"<<endl;"
                 << endl;
        }
        cout << "}" << endl;
    }
}

int main()
{
    for (int i = 3; i <= 6; i++)
        for (int j = 3; j <= 6; j++)
        {
            func(i, j); 
        }
    return 0;
}