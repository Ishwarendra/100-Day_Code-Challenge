#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    std::string f, b;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != 'b')
            f += s[i];
        if (t[i] != 'b')
            b += t[i];
    }

    if (f != b) // same relative ordering must
    {
        std::cout << "NO\n";
        return;
    }
 
    std::vector<int> ids, idt;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != 'b')
            ids.push_back(i);
        if (t[i] != 'b')
            idt.push_back(i);
    }

    // a cannot move back and c cannot move fwd
    n = f.size();
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 'a')
        {
            if (ids[i] > idt[i]) // a in s comes before
            {
                std::cout << "NO\n";
                return;
            }
        }
        else
        {
            if (ids[i] < idt[i]) // c is s comes after
            {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::cout << "YES\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}