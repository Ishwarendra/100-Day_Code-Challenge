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

void solve()
{
    int n, m;
    cin >> n >> m;
    vi strong(n); // stores people stronger than him
    
    while(m--)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        strong[min(u, v)]++; 
    }

    int base_ans = 0;
    for(int i = 0; i < n; i++)
        if (strong[i] == 0) base_ans++;

    int cur_ans = base_ans;
    vi base_strong = strong;
    int q; cin >> q;
    while(q--)
    {
        int qu; cin >> qu;
        if (qu == 1) // add friendship
        {
            int u, v; cin >> u >> v; u--, v--;
            // min(u, v) must die
            if (strong[min(u,v)]++ == 0) // ek aur gaya
                cur_ans--; 
        }
        else if (qu == 2) // remove friendship
        {
            int u, v; cin >> u >> v; u--, v--;
            // agar min(u, v) ko ek ka dar phir bach gaya
            if (strong[min(u, v)]-- == 1)
                cur_ans++;
        } 
        else
        {
            // dont forget to undo changes
            cout << cur_ans << "\n";
            // cur_ans = base_ans;
            // strong = base_strong;
        }
    }
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}