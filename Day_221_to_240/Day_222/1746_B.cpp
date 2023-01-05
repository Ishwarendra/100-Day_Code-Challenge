#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> zero, one;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        (x ? one : zero).push_back(i);
    }

    int ans = 0;
    int pos = 0;
    while (pos < std::ssize(one) and !zero.empty() and one[pos] < zero.back())
    {
        ans++;
        zero.pop_back();
        pos++;
    }

    std::cout << ans << "\n";
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