#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution
{
public:
    int findOccurrence(std::vector<std::vector<char> > &a, std::string s)
    {
        int n = a.size();
        int m = a[0].size();

        std::vector<std::array<int, 2>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        auto safe = [&](int i, int j)
        {
            return 0 <= i and i < n and 0 <= j and j < m;
        };

        auto f = [&](auto &&self, int i, int j, int id) -> int
        {
            if (!safe(i, j) or a[i][j] != s[id])
                return 0;

            if (id + 1 == s.size())
                return 1;

            char ch = a[i][j];
            int ans = 0;
            a[i][j] = '#';

            for (auto dir : dirs)
            {
                auto dx = dir[0], dy = dir[1];
                ans += self(self, i + dx, j + dy, id + 1);
            }

            a[i][j] = ch;
            return ans;
        };

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                ans += f(f, i, j, 0);
        }

        return ans;
    }
};

int main()
{
    int n = 50, m = 50;
    // std::cin >> n >> m;

    std::vector a(n, std::vector(m, 'A'));
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         std::cin >> a[i][j];

    std::string s(15, 'A');
    // std::cin >> s;

    Solution sol;
    std::cout << sol.findOccurrence(a, s);

    return 0; 
}    