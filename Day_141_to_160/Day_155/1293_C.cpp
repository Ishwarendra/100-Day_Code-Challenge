#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> a(2, std::vector<int>(n));
    std::set<std::pair<int, int>> problem;

    while (q--)
    {
        int r, c;
        std::cin >> r >> c;
        r--, c--;

        if (a[r][c]) // time to remove
        {
            if (c - 1 >= 0 and a[r ^ 1][c - 1])
            {
                if (r)
                    problem.erase({c - 1, c});
                else
                    problem.erase({c, c - 1});
            }
            if (c + 1 < n and a[r ^ 1][c + 1])
            {
                if (r)
                    problem.erase({c + 1, c});
                else
                    problem.erase({c, c + 1});
            }
            
            if (a[r ^ 1][c])
                problem.erase({c, c});
        } 
        else // check c - 1, c, c + 1 and add if can
        {
            if (c - 1 >= 0 and a[r ^ 1][c - 1])
            {
                if (r)
                    problem.emplace(c - 1, c);
                else
                    problem.emplace(c, c - 1);
            }
            if (c + 1 < n and a[r ^ 1][c + 1])
            {
                if (r)
                    problem.emplace(c + 1, c);
                else
                    problem.emplace(c, c + 1);
            }
            
            if (a[r ^ 1][c])
                problem.emplace(c, c);
        }

        a[r][c] ^= 1;

        std::cout << (problem.empty() ? "Yes\n" : "No\n");
    }   
    
    return 0;
}