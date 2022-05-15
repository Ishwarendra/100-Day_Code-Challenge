#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vvi = vector<vector<int>>;
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

const int FACT_MAX = 2e5 + 7;
ll mod = 998244353; // Change Mod value
ll fact[FACT_MAX], fact_inv[FACT_MAX];
 
long long binpow(long long a, long long b, const long long MOD = mod)
{
    long long ans = 1;
    while(b > 0)
    {
        if (b % 2 == 1)
            ans = (ans * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;  
    }

    return ans;
}
 
void make_fact()
{
	ll val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = binpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}
 
ll C(ll n, ll k)
{
	ll ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
} 

void solve()
{
	ll n; cin >> n;
	vll a(n);
     ll maxi = 0, second_maxi = 0;
     map<ll, ll> m;
	for(int i = 0; i < n; i++)
     {
          cin >> a[i];
          m[a[i]]++;
          if (a[i] > maxi)
               second_maxi = maxi, maxi = a[i];
          else if (a[i] > second_maxi)
               second_maxi = a[i];
     }
     
     // n = 1 
     if (n == 1)
     {
          if (a[0] == 1)
               cout << "1\n";
          else
               cout << "0\n";          
     }
     
     else if (m[maxi] > 1)
     {
          ll result = fact[n];
          cout << result << "\n";
     }
     else // m[maxi] == 1
     {
          if (maxi - second_maxi == 1)
          {
               ll result = fact[n];
               result -= (fact[n]*binpow(m[maxi] + m[second_maxi], mod - 2)) % mod;
               result += mod;
               result %= mod;
          
               cout << result << "\n";
          }
          
          else
          {
               cout << "0\n";
          }
     }
}

int main()
{
     FIO;
     make_fact();
     int t = 1;
     cin >> t;
     while(t--)
         solve();
     return 0;
}