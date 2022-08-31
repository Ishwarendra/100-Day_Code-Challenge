#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

long countSubarray(vector<int> numbers, int k)
{
    int n = numbers.size();
    long ans = 0;
    long long product = 1;

    for (int i = 0, start = 0; i < n; i++)
    {
        product *= 1LL * numbers[i];
        while (start < i and product > k)
        {
            product /= numbers3[start];
            start++;
        }

        if (product <= k)
            ans += i - start + 1;
    }

    return ans;
}

int main()
{
    int n, k;
    std::cin >> n >>k;
    std::vector<int>a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::cout << countSubarray(a, k);
    return 0; 
}    