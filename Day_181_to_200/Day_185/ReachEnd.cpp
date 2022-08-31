#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

// int findMinHealth(vector<int> power, int armor)
// {
//     int left = 1, right = INT_MAX;
//     int ans = -1;

//     auto good = [&](int mid, vector<int> a)
//     {
//         long long sum = 0;
//         bool used  = false;
//         int biggest = 0;

//         for (int i = 0; i < a.size(); i++)
//         {
//             biggest = max(biggest, a[i]);
//             sum += a[i];
            
//             if (sum >= mid)
//             {
//                 if (used)
//                     return false;
//                 else
//                 {
//                     used = true;

//                     if (biggest >= armor)
//                         sum -= armor;
//                     else
//                         sum -= biggest;

//                     if (sum >= mid)
//                         return false;
//                 }
//             }
//         }

//         return true;
//     };

//     while (left <= right)
//     {
//         int mid = (left + right) / 2;

//         if (good(mid, power))
//             ans = mid, right = mid - 1;
//         else
//             left = mid + 1;
//     }

//     return ans;
// }

int findMinHealth(vector<int> power, int armor)
{
    int n = power.size();

    long long ans = 0;
    bool used = false;

    for (int i = 0; i < n; ++i)
    {
        if (armor < power[i] and !used)
        {
            used = true;
            ans += power[i] - armor;
        }
        else
            ans += power[i];
    }

    if (!used)
    {
        int temp = *std::max_element(power.begin(), power.end());
        ans -= temp;
        used = true;
    }

    return ans + 1;
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    cout << findMinHealth(a, k) << "\n";

    return 0; 
}    