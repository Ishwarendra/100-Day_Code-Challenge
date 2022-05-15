#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution
{
      vector<string> split(string &s)
      {
            string cur;
            vector<string> res;
            for (int i = 0; i < s.length(); i++)
            {
                  if (s[i] == ' ')
                        res.push_back(cur), cur = "";
                  else
                        cur += s[i];
            }
            res.push_back(cur);
            return res;
      }

public:
      bool wordPattern(string pattern, string s)
      {
            vector<string> words = split(s);
            if (pattern.size() != words.size())
                  return false;

            map<char, string> m;
            map<string, char> m2;
            for (int i = 0; i < pattern.size(); i++)
            {
                  if (m.find(pattern[i]) == m.end())
                  {
                        if (m2.find(words[i]) != m2.end())
                              return false;
                        m[pattern[i]] = words[i];
                  }
                  else 
                  {
                        if (m[pattern[i]] != words[i])
                             return false;
                  }
            }

            return true;
      }
};

int main()
{
      return 0;
}