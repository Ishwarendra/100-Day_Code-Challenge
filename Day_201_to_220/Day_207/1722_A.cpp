#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n; 
    std::string s;
    std::cin >> n >> s;

    std::string t = "Timur";
    std::sort(std::begin(t), std::end(t));  
    std::sort(std::begin(s), std::end(s));

    std::cout << (t == s ? "Yes\n" : "No\n");
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