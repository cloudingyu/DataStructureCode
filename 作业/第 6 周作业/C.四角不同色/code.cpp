#include <iostream>
using namespace std;

int T;

int main()
{
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        if (n == 1)
        {
            for (int i = 1; i <= m; i++)
                cout << "0";
            cout << endl;
        }
        else if (m == 1)
        {
            for (int i = 1; i <= n; i++)
                cout << "0";
            cout << endl;
        }
        else if (n == 2 || m == 2)
        {
            if (m == 2)
            {
                cout << "00" << endl;
                for (int i = 2; i <= n; i++)
                    cout << "01" << endl;
            }
            else
            {
                for (int i = 1; i <= m; i++)
                    cout << "0";
                cout << endl
                     << "0";
                for (int i = 2; i <= m; i++)
                    cout << "1";
                cout << endl;
            }
        }
        else if (n == 3 && m == 3)
        {
            cout << "000" << endl;
            cout << "011" << endl;
            cout << "101" << endl;
        }
        else if (n == 3 && m == 4)
        {
            cout << "0001" << endl;
            cout << "0110" << endl;
            cout << "1010" << endl;
        }
        else if (n == 3 && m == 5)
        {
            cout << "00011" << endl;
            cout << "01100" << endl;
            cout << "10101" << endl;
        }
        else if (n == 3 && m == 6)
        {
            cout << "000111" << endl;
            cout << "011001" << endl;
            cout << "101010" << endl;
        }
        else if (n == 4 && m == 3)
        {
            cout << "000" << endl;
            cout << "011" << endl;
            cout << "101" << endl;
            cout << "110" << endl;
        }
        else if (n == 4 && m == 4)
        {
            cout << "0001" << endl;
            cout << "0110" << endl;
            cout << "1010" << endl;
            cout << "1100" << endl;
        }
        else if (n == 4 && m == 5)
        {
            cout << "00011" << endl;
            cout << "01100" << endl;
            cout << "10101" << endl;
            cout << "11010" << endl;
        }
        else if (n == 4 && m == 6)
        {
            cout << "000111" << endl;
            cout << "011001" << endl;
            cout << "101010" << endl;
            cout << "110100" << endl;
        }
        else if (n == 5 && m == 3)
        {
            cout << "001" << endl;
            cout << "010" << endl;
            cout << "011" << endl;
            cout << "100" << endl;
            cout << "101" << endl;
        }
        else if (n == 5 && m == 4)
        {
            cout << "0011" << endl;
            cout << "0101" << endl;
            cout << "0110" << endl;
            cout << "1001" << endl;
            cout << "1010" << endl;
        }
        else if (n == 6 && m == 3)
        {
            cout << "001" << endl;
            cout << "010" << endl;
            cout << "011" << endl;
            cout << "100" << endl;
            cout << "101" << endl;
            cout << "110" << endl;
        }
        else if (n == 6 && m == 4)
        {
            cout << "0011" << endl;
            cout << "0101" << endl;
            cout << "0110" << endl;
            cout << "1001" << endl;
            cout << "1010" << endl;
            cout << "1100" << endl;
        }
        else
            cout << "No solution" << endl;
    }
    return 0;
}
