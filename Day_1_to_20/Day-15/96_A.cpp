#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int i = (start); i < (end); i++) cout << (v[i]) << " ";cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);};

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
    cout << "\n";
};

int max_consec_char(string s, int id)
{
    int n = s.length();
    int ans = 1;
    char ch = s[id];
    for(int i = id + 1; i < n; i++)
    {
        if (s[i] == ch)
            ans++;
        else
            break;
    }
    return ans;
}

void solve()
{
    string s; cin >> s;
    int n = s.length();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, max_consec_char(s, i));
    }

    if (ans >= 7)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}