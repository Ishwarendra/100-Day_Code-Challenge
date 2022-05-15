#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

// https://leetcode.com/problems/search-a-2d-matrix-ii/
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int i = 0, j = m - 1;

    while(i < n and j >= 0)
    {
        if (matrix[i][j] > target)
            j--;
        else if (matrix[i][j] < target)
            i++;
        else    
            return true;
    }
    return false;
}

int main()
{
    return 0;
}