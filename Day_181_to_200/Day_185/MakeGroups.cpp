#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int minimumGroups(vector<int> awards, int k)
{
    int n = awards.size();
    std::sort(awards.begin(), awards.end());

    int left = 1, right = n;
    int ans = n;

    auto good = [&](int mid)
    {
        int groups = 0;
        for (int i = 0; i < n; i++)
        {
            int j;
            for (j = i; j < n; j++)
            {
                if (awards[j] - awards[i] > k)
                    break;
            }

            i = j - 1;
            groups++;
        }

        return groups <= mid;
    };

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    return ans;
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::cout << minimumGroups(a, k) << "\n";
    return 0; 
}    