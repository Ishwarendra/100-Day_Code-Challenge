#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

template <typename T>
struct Fenwick 
{
    const int n;
    std::vector<T> a;
    
    Fenwick(int n) : n(n), a(n) {}
    Fenwick(const std::vector<T> &inp) : Fenwick((int) inp.size())
    {
        for (int i = 0; i < n; i++)
            add(i, inp[i]);
    }
    void add(int x, T v) 
    {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x)  
    {
        T ans = 0;
        x++;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T sum(int l, int r) 
    {
        if (l - 1 < 0)
            return sum(r);
        
        return sum(r) - sum(l - 1);
    }
}; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::vector<int> tmp(a.begin(), a.end());
    std::sort(tmp.begin(), tmp.end());
    
    int sz = std::unique(tmp.begin(), tmp.end()) - tmp.begin();
    tmp.resize(sz);

    for (int i = 0; i < n; ++i)
        a[i] = std::lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();

    Fenwick<int> ft(n);
    std::map<int, int> m, freq_a;

    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
        freq_a[i] = m[a[i]];
    }

    long long ans = 0;
    m.clear();

    for (int i = n - 1; i >= 0; --i)
    {
        if (freq_a[i] - 1 >= 0)
            ans += ft.sum(freq_a[i] - 1);        
        m[a[i]]++;
        ft.add(m[a[i]], 1);
    }

    std::cout << ans << "\n";
    
    return 0;
}