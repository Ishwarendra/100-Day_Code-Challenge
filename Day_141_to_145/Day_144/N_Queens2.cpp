#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

class Solution
{
    int f(int r, std::vector<int> &col,
          std::vector<int> &dia, std::vector<int> &anti)
    {
        int n = col.size();
        int cnt = 0;

        if (r == n)
            return 1;

        for (int c = 0; c < n; c++)
        {
            if (!col[c] and !dia[r + c] and !anti[r - c + n - 1])
            {
                col[c] = dia[r + c] = anti[r - c + n - 1] = 1;
                cnt += f(r + 1, col, dia, anti);
                col[c] = dia[r + c] = anti[r - c + n - 1] = 0;
            }
        }

        return cnt;
    }
public:
    int totalNQueens(int n)
    {
        std::vector<int> col(n), anti(2 * n), dia(2 * n);
        return f(0, col, dia, anti);
    }
};

int main()
{
    return 0;
}