#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    std::string t;
    int x;
    std::cin >> t >> x;

    auto add = [&](std::string &s)
    {
        assert(s.size() == 5);
        int hnow = std::stoi(s.substr(0, 2));
        int mnow = std::stoi(s.substr(3, 2));

        hnow = (hnow + x / 60) % 24;
        mnow = (mnow + x % 60);

        if (mnow >= 60)
            hnow++, mnow -= 60;
        hnow %= 24;

        std::string ans;
        if (hnow / 10 == 0)
            ans += '0';
        ans += std::to_string(hnow);
        ans += ':';

        if (mnow / 10 == 0)
            ans += '0';

        ans += std::to_string(mnow);

        return ans;
    };  

    auto isPalin = [&](std::string &s)
    {
        return s[0] == s[4] and s[1] == s[3];
    };

    int count = 1600;
    std::set<std::string> p;

    while (count--)
    {
        if (isPalin(t))
            p.insert(t);

        t = add(t);
    }
    
    std::cout << p.size() << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}