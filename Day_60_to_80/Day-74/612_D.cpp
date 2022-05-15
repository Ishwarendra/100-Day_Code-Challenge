#include<bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<std::vector<int>> a;
    
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        
        a.push_back({l, 1});
        a.push_back({r, -1});
    }  
    
    std::sort(a.begin(), a.end(), [&](const std::vector<int> &a, const std::vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        
        return a[0] < b[0];
    });
    
    int cnt = 0;
    std::vector<int> start, end;
    
    for (int i = 0; i < 2 * n; ++i)
    {
        if (cnt == k - 1 and a[i][1] == 1)
            start.push_back(a[i][0]);
        
        if (cnt == k and a[i][1] == -1)
            end.push_back(a[i][0]);
        
        cnt += a[i][1];
    }
    
    std::cout << start.size() << "\n";
    
    for (int i = 0; i < start.size(); ++i)
        std::cout << start[i] << " " << end[i] << "\n";
      
    return 0;
}