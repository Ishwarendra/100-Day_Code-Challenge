#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int       long long
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi   =  vector<int>;
using vvi  =  vector<vector<int>>;
using vll  =  vector<long long>;
using vvll =  vector<vector<long long>>;
using ll   =  long long;
using ld   =  long double;
using ull  =  unsigned long long;
using pii  =  pair<int, int>;
using pll  =  pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

void solve()
{
	int n, k; cin >> n >> k;
    
    vi a(n);
    
    for(auto &x : a)
        cin >> x;
    
    sort(all(a));
    
    int median = a[n/2];
    
    // a[n/2] -> a[n/2 + 1] ke equal tak 1 op
    // a[n/2] -> a[n/2 + 2] ke liye 2 op
    //...
    // a[n/2] -> a[n/2 + n/2] ke liye n/2 op
    // a[n/2] -> a[n/2 + n/2 + x] ke liye n/2 op
    
    for(int i = n/2 + 1; i <= n; i++)
    {
        int diff = (i < n ? a[i] - median : 1e18);
        int incre = min(k/(i - n/2), diff);
        
        median += incre;
        k -= incre * (i - n/2);
    }
    
    cout << median << "\n";
}

int32_t main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}