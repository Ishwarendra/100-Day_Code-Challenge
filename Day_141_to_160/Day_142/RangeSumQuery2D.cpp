#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
    std::vector<std::vector<int>> pref;
    void print(std::vector<std::vector<int>> & a)
    {
        for (auto i : a)
        {
            for (auto j : i)
                std::cout << j << " ";
            std:cout << "\n";
        }
    }
public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        pref.resize(n + 1, std::vector<int>(m + 1));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + matrix[i - 1][j - 1];
        }

        print(pref);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        row1++, col1++, row2++, col2++;
        
        return pref[row2][col2] + pref[row1 - 1][col1 - 1]
            - pref[row1 - 1][col2] - pref[row2][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
    int n, m;
    std::cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> a[i][j];

    NumMatrix num(a);
    std::cout << num.sumRegion(2, 1, 4, 3);

    return 0; 
}    