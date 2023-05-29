#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    std::string countOfAtoms(std::string formula) 
    {
        int n = std::size(formula);
        int pos = 0;

        auto getString = [&]()
        {
            std::string s;
            if (pos >= n or !std::isupper(formula[pos]))
                return s;

            s += formula[pos];
            pos++;

            while (pos < n and std::islower(formula[pos]))
                s += formula[pos], pos++;

            return s;
        };

        auto getNum = [&]()
        {
            if (pos >= n or !std::isdigit(formula[pos]))
                return 1;

            int num = 0;
            while (pos < n and std::isdigit(formula[pos]))
                num = num * 10 + (formula[pos] - '0'), pos++;

            return std::max(1, num);
        };

        std::function<std::map<std::string, int>()> f;
        f = [&]()
        {
            std::map<std::string, int> m;

            while (pos < n)
            {
                if (formula[pos] == '(')
                {
                    pos++;
                    auto nm = f();
                    for (auto &[s, freq] : nm)
                        m[s] += freq;
                }
                else if (formula[pos] == ')')
                {
                    pos++;
                    auto s = getString();
                    int num = getNum();

                    for (auto &[_, freq] : m)
                        freq *= num;
                    if (!s.empty())
                        m[s]++;

                    return m;
                }
                else
                {
                    auto s = getString();
                    auto num = getNum();
                    m[s] += num;
                }
            }

            return m;
        };

        auto m = f();
        std::string ans;
        for (auto [atom, freq] : m)
        {
            if (freq == 0)
                continue;
            ans += atom;
            if (freq > 1)
                 ans += std::to_string(freq);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    std::string ss;
    std::cin >> ss;

    std::cout << s.countOfAtoms(ss);
    return 0; 
}    