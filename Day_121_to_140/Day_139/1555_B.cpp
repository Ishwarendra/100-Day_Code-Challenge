#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int W, H;
    std::cin >> W >> H;

    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int w1 = x2 - x1, h1 = y2 - y1;

    int w2, h2;
    std::cin >> w2 >> h2;

    int ans = 1e9;

    if (w1 + w2 <= W)
    {
        // left
        ans = std::min(ans, std::max(0, w2 - x1));
        // right
        ans = std::min(ans, std::max(0, w2 - (W - x2)));
    }

    if (h1 + h2 <= H)
    {
        // up
        ans = std::min(ans, std::max(0, h2 - (H - y2)));
        // down
        ans = std::min(ans, std::max(0, h2 - y1));
    }

    std::cout << (ans == 1e9 ? -1 : ans) << "\n";
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