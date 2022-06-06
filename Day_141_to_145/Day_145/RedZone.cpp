#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

class Solution
{
public:
    int solve(std::vector<std::vector<int>> &a, int b);
};

long double euclidean_distance(std::vector<int> &p1, std::vector<int> &p2)
{
    auto sq = [&](int i) -> long double
    {
        return i * 1.0L * i;
    }; 

    return sqrt(sq(p1[0] - p2[0]) + sq(p1[1] - p2[1]));
}

int Solution::solve(std::vector<std::vector<int>> &a, int b) 
{
    int left = 1, right = (int) 1e9;
    int ans = (int) 1e9;

    auto good = [&](int x)
    {
        int n = a.size();
        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
                cnt += euclidean_distance(a[i], a[j]) <= 2.0 * x;
        }

        return cnt >= b;
    };

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    return ans;
}


int main()
{
    return 0;
}