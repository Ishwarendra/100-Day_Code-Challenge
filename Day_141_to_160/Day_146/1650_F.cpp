#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

const i64 UTTAM_MITTAL = 199;
const i64 inf = 1e15;

// a -> time, percent, 
std::vector<i64> knapsack(std::vector<std::tuple<i64, i64, i64>> &a, i64 deadline, i64 &tme)
{
    i64 n = a.size();

    auto val = [&](i64 idx) // percent
    {
        return std::get<1>(a[idx]);
    };

    auto wt = [&](i64 idx) // time
    {
        return std::get<0>(a[idx]);
    };

    // f(i, v) = f(i - 1, v) agar v - val[i] < 0
    // f(i, v) = f(i - 1, v - v[i]) or f(i - 1, v) v - val[i] >= 0;

    std::vector<i64> dp(UTTAM_MITTAL, inf), ndp(UTTAM_MITTAL, inf);
    std::vector<std::vector<i64>> chosen(UTTAM_MITTAL, std::vector<i64>(n));

    dp[0] = 0;//, ndp[val(0)] = wt(0), chosen[val(0)][0] = 1;
    
    for (i64 i = 0; i < n; i++)
    {
        for (i64 j = 0; j < UTTAM_MITTAL; j++)
        {
            if (val(i) > j) 
                ndp[j] = dp[j];
            else
            {
                if (dp[j - val(i)] != inf and dp[j - val(i)] + wt(i) < dp[j]) 
                    ndp[j] = dp[j - val(i)] + wt(i), chosen[j][i] = 1;
                else
                    ndp[j] = dp[j];
            }
        }

        std::swap(dp, ndp);
        std::fill(ndp.begin(), ndp.end(), inf);
    }

    i64 min = -1;
    for (i64 i = 100; i < UTTAM_MITTAL; i++)
    {
        if (dp[i] <= deadline)
        {
            if (min == -1)
                min = i;
            else if (dp[min] > dp[i])
                min = i;
        }
    }

    if (min == -1)
        return {-1};
    
    tme += dp[min];
    std::vector<i64> ans;

    for (i64 i = n - 1; i >= 0; i--)
    {
        if (chosen[min][i]) // add in answer and go to dp[v - val(i)] ke chosen
            ans.push_back(std::get<2>(a[i])), min -= val(i);
    }   
    
    return ans;
}

void solve()
{
    i64 n, m;
    std::cin >> n >> m;

    std::vector<i64> a(n);
    for (i64 i = 0; i < n; ++i)
        std::cin >> a[i];

    std::vector<std::vector<std::tuple<i64, i64, i64>>> opt(n);

    for (i64 i = 0; i < m; ++i)
    {
        i64 e, t, p;
        std::cin >> e >> t >> p;
        opt[--e].push_back(std::tuple<i64, i64, i64>(t, p, i + 1));
    }

    std::vector<i64> ans;
    i64 tme = 0;
    i64 deadline = 0;

    for (i64 i = 0; i < opt.size(); i++)
    {
        deadline = a[i] - tme;
        std::vector<i64> temp = knapsack(opt[i], deadline, tme);

        if (temp[0] == -1)
        {
            std::cout << "-1\n";
            return;
        }

        for (i64 id : temp)
            ans.push_back(id);

        print(i, temp);
    }

    std::cout << ans.size() << "\n";
    for (i64 id : ans)
        std::cout << id << " "; std::cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}