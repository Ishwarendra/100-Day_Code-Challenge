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

    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);

    std::string s, t;
    std::cin >> s >> t;

    int n = s.size(), m = t.size();
    bool del = true;
    std::string censor;

    for (int i = 0; i < n; i++)
    {
        censor += s[i];

        if (censor.size() > m and censor.substr(censor.size() - m) == t)
            censor.resize(censor.size() - m);
    }

    std::cout << censor << '\n';

    return 0;
}