#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
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

vi xor_vals(3e5 + 7);

void pre_process()
{
	for(int i = 1; i < xor_vals.size(); i++)
		xor_vals[i] ^= (xor_vals[i - 1] ^ i);
}

void solve()
{
	int a, b;
	cin >> a >> b;
	
	if (xor_vals[a - 1] == b)
		cout << a << "\n";
	else if (xor_vals[a] == b)
		cout << a + 2 << "\n";
	else 
		cout << a + 1 << "\n";
}

int main()
{
    FIO;
    pre_process();
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}