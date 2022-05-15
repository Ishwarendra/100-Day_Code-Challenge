#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vll = vector<long long>;
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

// add at right delete from anywhere
vector<string> powertwo;

// Make upto 2**54 (i.e x just less than 1e18 tak)
void init()
{
    ll expo = 1;
    for(int i = 0; i < 54; i++)
    {
        string tmp = to_string(expo);
        powertwo.push_back(tmp);
        expo *= 2;
    }
}

ll convert_oper(const string &a, const string &b)
{
    int n = a.length(), m = b.length();
    // j-> 2 ki power i-> normal wala
    int i = 0, j = 0, ans = 0;
    while(i < n and j < m)
    {
        if (b[j] == a[i])
            j++, ans++;
        i++;
    }

    return (n - ans) + (m - ans); // unmatch + not found
}

void solve()
{
    ll n; cin >> n;
    string s = to_string(n);
    
    ll ans = 2*n;
    for(int i = 0; i < powertwo.size(); i++)
    {
        // print(s, powertwo[i], convert_oper(s, powertwo[i]))
        ans = min(ans, convert_oper(s, powertwo[i]));
    }

    cout << ans << "\n";
}

int main()
{
    FIO;
    init();
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}