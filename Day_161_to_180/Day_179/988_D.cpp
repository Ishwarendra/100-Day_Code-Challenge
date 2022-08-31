#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> x(n);
    for (int i = 0; i < n; ++i)
        std::cin >> x[i];

    const int null_val = -2e9 - 1;

    std::sort(std::begin(x), std::end(x));
    std::vector<std::vector<int>> ans(3);
    ans[0] = {null_val};
    ans[1] = {null_val, null_val};
    ans[2] = {null_val, null_val, null_val};

    auto powerOfTwo = [](int x) -> bool
    {
        if (x <= 0)
            return false;

        return (x & (x - 1)) == 0;
    };

    for (int i = 0; i < n; ++i)
    {
        if (powerOfTwo(x[i]))
            ans[0][0] = x[i];

        for (int p = 0; p <= 30; p++)
        {
            int two = 0;
            int a = null_val, c = null_val;
            int b = x[i];

            if (std::binary_search(std::begin(x), std::begin(x) + i, b - (1 << p)))
                a = b - (1 << p);

            if (std::binary_search(std::begin(x) + i + 1, std::end(x), b + (1 << p)))
                c = b + (1 << p);

            if (a != null_val and c != null_val)
                ans[2][0] = a, ans[2][1] = b, ans[2][2] = c;
            else if (a != null_val)
                ans[1][0] = a, ans[1][1] = b;
            else if (c != null_val)
                ans[1][0] = b, ans[1][1] = c;
        }
    }

    if (ans[2][0] != null_val)
    {
        std::cout << "3\n";
        for (int i : ans[2])
            std::cout << i << " ";
        std::cout << "\n";
    }
    else if (ans[1][0] != null_val)
    {
        std::cout << "2\n";
        for (int i : ans[1])
            std::cout << i << " ";
        std::cout << "\n";
    }
    else
        std::cout << "1\n" << x[0] << "\n";
    
    return 0;
}