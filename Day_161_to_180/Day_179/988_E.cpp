#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::map<char, int> m;
    for (char ch : s)
        m[ch]++;

    constexpr int inf = 1e9;
    auto f = [&n, &inf](std::string s, char last, char secLast)
    {
        std::vector<int> vis(n);

        auto find = [&](char ch) -> int
        {
            for (int i = n - 1; i >= 0; --i)
            {
                if (s[i] == ch and !vis[i])
                {
                    vis[i] = 1;
                    return i;
                }
            }

            return -1;
        };

        auto move = [&](int from, int to) -> int
        {
            for (int i = from; i < to - 1; i++)
                std::swap(s[i], s[i + 1]);

            return abs(to - from);
        };

        int lastPos = find(last), secLastPos = find(secLast);
        int ans = 0;
        auto [min, max] = std::minmax(lastPos, secLastPos);

        if (min == 0)
        {
            int nonzero = -1;
            for (int i = 1; i < n; i++)
            {
                if (i == max)
                    continue;
                if (s[i] != '0')
                {
                    nonzero = i;
                    break;
                }
            }

            for (int i = nonzero; i > 0; i--)
            {
                ans++;
                std::swap(s[i], s[i - 1]);
            }        
        }

        std::fill(std::begin(vis), std::end(vis), 0);
        lastPos = find(last), secLastPos = find(secLast);

        if (lastPos < secLastPos)
            ans += move(secLastPos, n - 1) + move(lastPos, n - 1);
        else
            ans += move(lastPos, n - 1) + move(secLastPos, n - 2);

        return ans;
    };

    int ans = inf;

    for (auto last : {"00", "25", "50", "75"})
    {            
        std::map<int, int> t;
        t[last[0]]++, t[last[1]]++;

        if (m[last[0]] < t[last[0]] or m[last[1]] < t[last[1]])
            continue;

        ans = std::min(ans, f(s, last[1], last[0]));
    }

    std::cout << (ans >= inf ? -1 : ans) << "\n";

    return 0;
}