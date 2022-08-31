#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

class StockSpanner 
{
    std::stack<int> s;
    std::vector<int> a;
    int pos;
public:
    StockSpanner() : pos(-1) 
    {
        s.emplace(-1);
    }
    
    int next(int price) 
    {
        pos++;
        a.emplace_back(price);

        if (s.top() == -1)
        {
            s.emplace(pos);
            return pos + 1;
        }
        else
        {
            while (s.top() != -1 and a[s.top()] <= a[pos])
                s.pop();

            int top = s.top();
            s.emplace(pos);

            return pos - top;
        }
    }
};


int main()
{
    StockSpanner st;
    int n;
    std::cin >> n;

    while (n--)
    {
        int x;
        std::cin >> x;

        std::cout << st.next(x) << std::endl;
    }
    
    return 0;
}