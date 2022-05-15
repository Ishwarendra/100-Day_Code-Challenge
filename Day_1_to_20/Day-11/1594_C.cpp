#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

bool all_same(const string &s, const char &c, int x = 1)
{
    int n = s.length();
    for(int i = x - 1; i < n; i += x)
    {
        if (s[i] != c)
            return false;
    }

    return true;
}


void solve()
{
    int n; char c; string s;
    cin >> n >> c >> s;

    if (all_same(s, c))
        cout << "0\n";
    else
    {
        for(int i = 2; i <= n; i++)
        {
            if (all_same(s, c, i))
            {
                cout << "1\n" << i << "\n";
                return;                
            }
        }

        cout << "2\n" << n << " " << n - 1 << "\n";
    }
    
}

int main()
{
    FIO
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}