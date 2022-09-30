#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;

    std::cout << "1\n";
    for (int i = 1; i < n; ++i)  
    {
        std::cout << "1 ";
        for (int j = 1; j < i; j++)
            std::cout << "0 ";
        std::cout << "1\n";
    }
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