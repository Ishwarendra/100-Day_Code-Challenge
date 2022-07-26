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
    
    // freopen("stacking.in", "r", stdin);
    // freopen("stacking.out", "w", stdout);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> stack(n + 1);

    while (k--)
    {
        int a, b;
        std::cin >> a >> b;
        a--, b--;

        stack[a]++, stack[b + 1]--;
    }

    for (int i = 1; i <= n; i++)
        stack[i] += stack[i - 1];
    std:sort(stack.begin(), stack.end() - 1);

    std::cout << stack[n / 2] << "\n";
    
    return 0;
}
