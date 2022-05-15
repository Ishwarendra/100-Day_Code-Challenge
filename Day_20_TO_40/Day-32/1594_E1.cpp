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

const ll mod = 1e9 + 7;

long long binary_exponentiation(long long a, long long b, const long long mod = 1000000007)
{
    long long ans = 1;
    while(b > 0)
    {
        if (b % 2 == 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;  
    }

    return ans;
}

void solve()
{
    ll k; cin >> k;
    ll power = (1LL << k) - 2;
    ll ans = binary_exponentiation(4, power, mod);

    ans = (ans * 6) % mod;
    cout << ans << "\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}