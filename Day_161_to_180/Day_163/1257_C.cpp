#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    std::queue<int> q;
    std::map<int, int> m;

    int ans = n + 1;
    for (int i = 0; i < n; ++i)
    {
        q.emplace(a[i]);
        m[a[i]]++;

        if (m[a[i]] == 2)
        {
            while (q.front() != a[i])
                m[q.front()]--, q.pop();

            ans = std::min(ans, (int)std::size(q));
            m[q.front()]--;
            q.pop();
        }
    }

    std::cout << (ans == n + 1 ? -1 : ans) << "\n";
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