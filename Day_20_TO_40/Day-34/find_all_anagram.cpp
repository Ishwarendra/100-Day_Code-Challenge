#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void print(map<char, int> &a)
{
    for(auto pr : a)
        cout << pr.first << " = " << pr.second << "\n";
}

bool equal(map<char, int> &a, map<char, int> &b)
    {
        for(auto pr : a)
            if (pr.second == 0)
                a.erase(pr.first);
        
        for(auto pr : b)
            if (pr.second == 0)
                b.erase(pr.first);

        if (a.size() != b.size())
            return false;
        for(auto pr : a)
        {
            if (pr.second != b[pr.first])
                return false;
        }
        return true;
    }

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        map<char, int> mp, ms;
        vector<int> ans;
        for(char &ch : p)
            mp[ch]++;
        
        int i = 0, j = 0;
        while(j < s.length())
        {
            // if (i == 6){
            //     print(ms);
            // }
            ms[s[j]]++;
            j++;
            if (j - i == p.length())
            {
                if (equal(mp, ms)){
                    ans.push_back(i);
                }
                // slide the window
                ms[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}