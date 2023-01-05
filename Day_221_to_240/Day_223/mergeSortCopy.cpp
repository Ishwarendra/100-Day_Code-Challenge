#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) void(1);
#endif

using i64 = long long;

int merge(std::vector<int> &a, int l, int m, int r)
{
    std::vector<int> left, right;

    for (int i = l; i <= m; i++)
        left.push_back(a[i]);
    for (int i = m + 1; i <= r; i++)
        right.push_back(a[i]);

    int ans = 0;
    int i = 0, j = 0, k = l;

    while (i < left.size() and j < right.size())
    {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
        {
            a[k++] = right[j++];
            ans |= 1;
        }
    }

    while (i < left.size())
        a[k++] = left[i++];

    while (j < right.size())
        a[k++] = right[j++];

    return ans;
}

void mergeSort(std::vector<int> &a, int l, int r, int &ans)
{
    if (r <= l)
        return;

    int m = (l + r) / 2;
    mergeSort(a, l, m, ans);
    mergeSort(a, m + 1, r, ans);
    ans += merge(a, l, m, r);
}

int largestCountValue(std::vector<int> a)
{
    int ans = 0;
    int n = a.size();
    mergeSort(a, 0, n - 1, ans);

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    // std::cout << largestCountValue(a) << "\n";
    std::vector<int> b {2, 3, 5, 7, 1, 3, 5, 8};
    merge(b, 0, 3, std::size(b) - 1);
    print(b)
    
    return 0;
}