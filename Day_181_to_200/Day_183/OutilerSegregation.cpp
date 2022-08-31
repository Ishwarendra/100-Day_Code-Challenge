#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

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
    T rangeSum(int l, int r)
    {
        if (l - 1 < 0)
            return sum(r);

        return sum(r) - sum(l - 1);
    }
};

int countMoves(vector<int> &a)
{
    int moves = 0;
    int it2 = 0;
    int n = a.size();

    for (int i = 0; i < n; ++i)
    {
        if (!a[i])
            continue;

        moves += i != it2;
        swap(a[it2++], a[i]);
    }

    print(moves)
    return moves;
}

int countInversion(vector<int> &arr)
{
    print(arr)
    int n = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            n = i;
            break;
        }
    }

    Fenwick<int> ft(n + 1);
    int ans = 0;
    
    for (int i = 0; i < n; ++i)
    {
        ans += ft.rangeSum(arr[i] + 1, n);
        print(ft.a)
        ft.add(arr[i], 1);
    }
    print(ans)
    return ans;
}

int getMinSwaps(vector<int> &arr)
{
    return countMoves(arr) + countInversion(arr);
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    cout << getMinSwaps(a) << "\n";
    
    return 0;
}