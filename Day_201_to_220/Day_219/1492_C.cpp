#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::string s, t;
    std::cin >> n >> m >> s >> t;

    std::vector<int> pos[26];
    for (int i = 0; i < n; i++)
        pos[s[i] - 'a'].emplace_back(i);

    std::vector<int> first(m);
    std::vector<int> last(m);

    for (int i = 0, j = 0; j < m; i++)
    {
        if (s[i] == t[j])
            first[j++] = i;
    }

    for (int i = n - 1, j = m - 1; j >= 0; i--)
    {
        if (s[i] == t[j])
            last[j--] = i;
    }

    
    int width = 0;
    for (int i = 1; i < m; i++)
        width = std::max(width, last[i] - first[i - 1]);

    std::cout << width;

    return 0;
}