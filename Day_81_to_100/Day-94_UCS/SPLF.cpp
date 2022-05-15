#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    std::vector<int> pref(n), suff(n);
    
    pref[0] = a[0], suff[n - 1] = a[n - 1];
    
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + a[i];
        
    for (int i = n - 2; i >= 0; i--)
        suff[i] = suff[i + 1] + a[i];
        
    for (int i = 0; i < n; i++)
    {
        int prev = (i == 0 ? 0 : pref[i - 1]);
        int next = (i == n - 1 ? 0 : suff[i + 1]);
        
        if (prev == next)
        {
            std::cout << i << "\n";
            return;
        }
    }
    
    std::cout << "-1\n";
}

int main()
{
    int t;
    std::cin >> t;
    
    while(t--)
        solve();
        
    return 0;
    
}