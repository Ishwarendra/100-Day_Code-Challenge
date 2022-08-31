#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

string compressWord(string word, int k)
{
    string ans;
    
    if (k == 1)
        return ans;

    stack<pair<char, int>> s;

    int n = word.size();

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            s.push({word[i], 1});
        else if (s.top().first == word[i])
        {
            int freq = s.top().second;
            s.pop();

            if (freq + 1 < k)
                s.push({word[i], freq + 1});
        }
        else
            s.push({word[i], 1});
    }

    while (!s.empty()) 
    {
        int ch = s.top().first;
        int freq = s.top().second;

        for (int i = 0; i < freq; i++)
            ans += ch;
        s.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    std::string s;
    int k;

    std::cin >> k >> s;
    std::cout << compressWord(s, k);
    return 0; 
}    