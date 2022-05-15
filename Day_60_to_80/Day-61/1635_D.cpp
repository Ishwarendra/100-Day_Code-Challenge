#include <bits/stdc++.h>
using namespace std;

#define FIO        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using maxheap  =    priority_queue<int>;
using minheap  =    priority_queue<int, vector<int>, greater<int>>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

constexpr int MOD = 1e9 + 7;

// assume -MOD <= x < 2*MOD
int norm(int x) {
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(MOD - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, MOD - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = (int)(x) * rhs.x % MOD;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
}; 


set<int> a;
int parent(int x)
{
    if (x <= 0)
        return -1;
    
    if (a.count(x))
    {
        return 0;
    }
    
    if (x % 2 == 0)
        return parent(x/4);
    else
        return parent((x - 1)/2);
}

void solve()
{
    int n, p; cin >> n >> p;
    
    a.clear();
    vector<int> inp(n);
    
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.insert(x);
        inp[i] = x;
    }
    
    sort(all(inp), greater<int>());
    
    for(int i = 0; i < n; i++)
    {
        // print(inp[i], parent(inp[i]));
        a.erase(inp[i]);
        if (parent(inp[i]) == -1)
            a.insert(inp[i]);
    }
     
    vector<Z> dp(p);
    
    dp[0] = 0;
    dp[1] = 1;
    
    Z ans(1);
    
    for(int i = 2; i < p; i++)
        dp[i] = dp[i - 1] + dp[i - 2]; 
    
    for(int ele : a)
    {
        ans = ans + dp[ele];
    }
    
    cout << ans.val() << "\n";
}

int32_t main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}