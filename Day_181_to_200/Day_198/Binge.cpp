#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int findMinimumDay(vector<float> a)
{
    int n = a.size();
    sort(a.begin(), a.end());

    vector<bool> vis(n);

    int days = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        
        vis[i] = true;
        days++;

        for (int j = n - 1; j > i; j--)
        {
            if (vis[j] or a[i] + a[j] > 3.00)
                continue;

            vis[j] = true;
            break;
        }
    }

    return days;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<float> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::cout << findMinimumDay(a) << "\n";
    return 0; 
}    