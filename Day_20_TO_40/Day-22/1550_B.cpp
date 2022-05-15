#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int i = (start); i < (end); i++) cout << (v[i]) << " ";cout << "\n";
#define log(v) for(auto i = ((v).begin()); i != ((v).end()); i++) cout << *(i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

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
};

int blocks(string s, int n)
{
    char ch = s[0];
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if (ch != s[i])
            cnt++, ch = s[i];
    }
    return cnt;
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    string s; cin >> s;

    ll ans = 0;
    if (b > 0)
    {
        ans = (a + b) * n;
        cout << ans << "\n";
    }
    else
    {
        int m = blocks(s, n);
        // cout << m << " ";
        ans = a*n + b*(m/2 + 1);
        cout << ans << "\n";
    }
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}