#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
     int n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n);

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        int len;
        std::cin >> len;

        a[i].resize(len);
        for (int j = 0; j < len; ++j)
            std::cin >> a[i][j];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::vector<int> temp = a[i];
            temp.insert(std::end(temp), std::begin(a[j]), std::end(a[j]));

            int min = 1e9;
            for (int k = 0; k < temp.size(); ++k)
            {
                if (min < temp[k])
                {
                    ans++;
                    break;
                }
                else
                    min = temp[k];
            }
        }
    }

    std::cout << ans;
    
    return 0;
}