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

// a1+ a2 = n (a1, a2 >= 0 for now last me remove)
// (n + 2 - 1) C (2 - 1)

ll to_num(string &a)
{
    ll res = 0;
    for(int i = 0; i < a.length(); i++)
    {
        ll cur_dig = a[i] - '0';
        res = res * 10 + cur_dig;    
    }
    
    return res;
}

void solve()
{
	string n; cin >> n;
    
    string odd, even;
    
    for(int i = 0; i < n.length(); i++)
    {
        if (i % 2)
            odd += n[i];
        else
            even += n[i];
    }
    
    ll a = to_num(odd);
    ll b = to_num(even);
    
    cout << (a + 1) * (b + 1) - 2 << "\n";
        
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}