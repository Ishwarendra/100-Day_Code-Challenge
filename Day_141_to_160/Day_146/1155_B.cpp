#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> eight, non_eight;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '8')
            eight.push_back(i);
        else
            non_eight.push_back(i);
    }

    std::reverse(eight.begin(), eight.end());
    std::reverse(non_eight.begin(), non_eight.end());
    print(eight, non_eight)
    auto vasya = [&]()
    {
        if (non_eight.empty())
            return true;
        if (eight.empty())
            return false;

        return eight.back() < non_eight.back();
    };

    for (int i = 0; i < (n - 11) / 2; ++i)
    {
        if (non_eight.size())
            non_eight.pop_back();

        if (non_eight.empty())
        {
            std::cout << "YES\n";
            return 0;
        }

        if (eight.size())
            eight.pop_back();

        if (eight.empty())
        {
            std::cout << "NO\n";
            return 0;
        }
    }
    print(eight, non_eight)

    std::cout << (vasya() ? "YES\n" : "NO\n");
    
    return 0;
}