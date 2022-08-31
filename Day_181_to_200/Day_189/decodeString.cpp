#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    std::string decodeString(std::string s) 
    {        
        std::function<std::string(const std::string&, int&)> f;
        f = [&](const std::string &t, int &i) -> std::string
        {
            std::string ans;

            while (i < std::size(t) and t[i] != ']')
            {
                if (!std::isdigit(t[i]))
                    ans += t[i++];
                else
                {
                    int num = 0;
                    while (i < std::size(t) and std::isdigit(t[i]))
                        num = num * 10 + t[i++] - '0';

                    i++;
                    auto cur = f(t, i);

                    while (num-- > 0)
                        ans += cur;

                    i++;    
                }
            }

            return ans;
        };

        int i = 0;
        auto ans = f(s, i);
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Solution sol;
    std::string s;
    std::cin >> s;

    std::cout << sol.decodeString(s) << std::endl;
    
    return 0;
}