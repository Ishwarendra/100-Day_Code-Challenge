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

    std::freopen("lineup.in", "r", stdin);
    std::freopen("lineup.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<std::string> cows {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    std::map<std::string, int> pos;
    std::sort(std::begin(cows), std::end(cows));

    constexpr int total = 8;
    for (int i = 0; i < total; i++)
        pos[cows[i]] = i;

    std::vector<std::array<int, 2>> together;

    for (int i = 0; i < n; i++)
    {
        std::string a, b, c;
        std::cin >> a >> b >> b >> b >> b >> c;
        together.push_back({pos[a], pos[c]});
    }
    
    auto valid = [&](std::vector<int> &a)
    {
        for (auto [x, y] : together)
        {
            int yes = 0;
            for (int i = 0; i < total; i++)
            {
                if (a[i] == x)
                {
                    if (i - 1 >= 0 and a[i - 1] == y)
                        yes = 1;
                    if (i + 1 < total and a[i + 1] == y)
                        yes = 1;

                    break;
                }
            }

            if (!yes)
                return false;
        }

        return true;
    };

    std::function<void(int)> f;
    std::vector<int> ans(total, total), cur_ans;
    std::vector<int> vis(total);

    f = [&](int id)
    {
        if (id == total)
        {
            if (valid(cur_ans) and cur_ans < ans)
                ans = cur_ans;

            return;
        }

        for (int i = 0; i < total; i++)
        {
            if (!vis[i])
            {
                cur_ans.push_back(i);
                vis[i] = 1;
                f(id + 1);
                vis[i] = 0;
                cur_ans.pop_back();
            }
        }
    }; f(0);
    for (auto i : ans)
        std::cout << cows[i] << "\n";

    return 0;
}
