#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)

#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using maxheap  =    priority_queue<int>;
using minheap  =    priority_queue<int, vector<int>, greater<int>>;
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.ssecond; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.ssecond; return out;}
void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

int MOD = 2;

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
        x = (long long)(x) * rhs.x % MOD;
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

void solve()
{
	int n; cin >> n;
	MOD = n;
	
	vi phin;
	
	for(int i = 1; i <= n - 1; i++)
	{
		if (__gcd(n, i) == 1)
			phin.push_back(i);
	}
	
	Z prod = 1;
	
	for(int i : phin)
		prod *= i;
		
	if (prod.val() == 1)
	{
		cout << phin.size() << "\n";
		log(phin);
	}	
	else
	{
		cout << phin.size() - 1 << "\n";
		for(int i : phin)
		{
			if (i == prod.val())
				continue;
			cout << i << " ";
		}	
		cout << "\n";
	}
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}