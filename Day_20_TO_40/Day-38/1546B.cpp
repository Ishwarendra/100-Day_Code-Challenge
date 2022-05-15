#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

void solve()
{
    int n, len;
    cin >> n >> len;
    vector<map<char, int>> m(len);

    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for(int j = 0; j < s.length(); j++)
            m[j][s[j]]++;
    }

    for(int i = 0; i < n - 1; i++)
    {
        string s; cin >> s;
        for(int j = 0; j < s.length(); j++)
        {
            char ch = s[j];
            m[j][ch]--;
            if (m[j][ch] == 0)
                m[j].erase(ch);
        }
    }

    string ans;
    for(int i = 0; i < len; i++)
        for(auto j : m[i])
            ans += j.first;
    
    cout << ans << "\n";
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}