#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> v;
        string  s;
        cin >> s;
        
        int bp = 0;
        string str = "";
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'W' && str != "")
            {
                v.push_back(str);
                str = "";
            }
            else {
                if (s[i] != 'W')
                {
                    str += s[i];
                }
            }
        }
        if (str != "")
            v.push_back(str);
        
        bool printed = false;
        
        for (std::string temp : v)
        {
            int red = count(all(temp), 'R');
            int blue = count(all(temp), 'B');
            
            if (!printed and (!red and blue) or (red and !blue))
            {
                cout << "NO\n";
                printed = true;
                break;
            }
            
        }
        
        if (!printed)
            cout << "YES\n";
    }
}