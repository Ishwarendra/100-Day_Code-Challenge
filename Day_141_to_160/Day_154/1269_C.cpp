#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

bool beautiful(std::string &a, int k)
{
    int n = a.size();
    for (int i = 0; i < n - k; i++)
    {
        if (a[i] != a[i + k])
            return false;
    }

    return true;
}

bool less(std::string &a, std::string &b)
{
    if (a.size() < b.size())
        return true;
    if (a.size() > b.size())
        return false;

    for (int i = 0; i < (int) a.size(); i++)
    {
        if (a[i] < b[i])
            return true;
        if (a[i] > b[i])
            return false;
    }

    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::string a;
    std::cin >> a;

    std::string b, start;

    for (int i = 0; i < k; i++)
        start += a[i];


    for (int i = 0; i < n; i++)
        b += start[i % k];

    if (!less(b, a))
        std::cout << b.size() << "\n" << b << "\n";
    else
    {
        for (int i = k - 1; i >= 0; i--)
            if (start[i] != '9')
            {
                start[i] = start[i] + 1;
                break;
            }
            else
                start[i] = '0';

        b.clear();
        for (int i = 0; i < n; i++)
            b += start[i % k];

        std::cout << b.size() << "\n";
        std::cout << b << "\n";
        assert(!less(b, a));
    }

    return 0;
}