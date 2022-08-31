#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get(),
    (uint32_t)__builtin_ia32_rdtsc()
};
std::mt19937 rng(seed);

template<class T = int>
T get_rand(T l, T r)
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

long long correct(const vector<int> &a, int k)
{
    int n = std::size(a);
    long long ans = 0;
    for (int i = 0; i < n - k + 1; ++i)
    {
        std::set<int> s;
        for (int j = i; j < i + k; j++)
            s.emplace(a[j]);

        if (s.size() == k)
        {
            long long sum = 0;
            for (int x : s)
                sum += x;

            ans = std::max(ans, sum);
        }
    }

    return ans;
}

long long findMaximumSum(const vector<int> &stockPrice, int k)
{
    int n = stockPrice.size();
    map<int, int> m;

    long long ans = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i < k - 1)
        {
            m[stockPrice[i]]++;
            sum += stockPrice[i];
        }
        else
        {
            m[stockPrice[i]]++;
            sum += stockPrice[i];

            if (m.size() == k)
                ans = std::max(ans, sum);

            m[stockPrice[i - k + 1]]--;
            if (m[stockPrice[i - k + 1]] == 0)
                m.erase(stockPrice[i - k + 1]);

            sum -= stockPrice[i - k + 1];
        }
    }

    return ans;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n = get_rand<int>(1, int(10));
        int k = get_rand<int>(1, n);

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = get_rand<int>(1, std::max(1, int(1e9)));

        long long actual = correct(a, k);
        long long mine = findMaximumSum(a, k);

        if (actual != mine)
        {
            print(actual, mine)
            print(n, k, a);
            return 0;
        }
    }

    std::cout << "omk:)";

    return 0;
}