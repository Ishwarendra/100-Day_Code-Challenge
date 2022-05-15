#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi    =   vector<int>;
using vvi   =   vector<vector<int>>;
using vll   =   vector<long long>;
using vvll  =   vector<vector<long long>>;
using ll    =   long long;
using ld    =   long double;
using pii   =   pair<int, int>;
using pll   =   pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};


void solve()
{
    vi n(3);
    cin >> n[0] >> n[1] >> n[2];
    
    vector<vll> bags(3);
    
    vll sum(3, 0);
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < n[i]; j++)
        {
            ll x; cin >> x;
            bags[i].push_back(x);
            sum[i] += x;
        }
        
        sort(all(bags[i]));
    }
    
    ll ans = -1;
    for(int i = 0; i < 3; i++)
        ans = max(ans, sum[(i + 1)%3] + sum[(i + 2) % 3] - sum[i]);
        
    vll mins(3);
    
    for(int i = 0; i < 3; i++)  
        mins[i] = bags[i][0];
    
    sort(all(mins));
    
    ans = max(ans, sum[0] + sum[1] + sum[2] - 2*(mins[0] + mins[1]));
        
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