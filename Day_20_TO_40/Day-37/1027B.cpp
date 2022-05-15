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

void f1(ll x, ll y, ll n)
{
    ll ans = 0;
    ll d = (n + 1)/2;
    if ((x + y) % 2)
        ans += (n*n + 1)/2;

    y = (y + 1)/2 - 1;
    ans += d*x - d + 1 + y;
    cout << ans << "\n";
}

void f2(ll x, ll y, ll n)
{
    ll d = n;
    ll ans = 0;
    if ((x + y) % 2)
        ans += (n*n + 1)/2;
    
    bool row = (x % 2);
    x = (x + 1)/2;
    y = (row ? (y + 1)/2 - 1 : (y + 2)/2 - 1);
    ll first = (x - 1)*d + (row ? 1 : (1 + d)/2);
    // print(first);
    ans += first + y;
    cout << ans << "\n";
}

int main()
{
    FIO;
    ll n, q;
    cin >> n >> q;
    while(q--)
    {
        ll x, y;
        cin >> x >> y;
        (n % 2) ? f2(x, y, n) : f1(x, y, n);
    }
    return 0;
}