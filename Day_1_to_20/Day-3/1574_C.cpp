#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) a.begin(),a.end()
using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;

void solve()
{
    int n; cin >> n;
    vll a(n);
    ll tot_pow = 0;
    for(auto &x: a)
        cin >> x, tot_pow += x;
    
    sort(a.begin(), a.end());

    int m; cin >> m;
    while(m--)
    {
        ll power1 = tot_pow;
        ll power2 = tot_pow;

        ll x, y; // x - attack , y - def
        cin >> x >> y;
        // send person who has max health in army (but less than dragon) or min health who has more health than dragon

        ll ans1 = 0, ans2 = 0;

        ll f1 = lower_bound(all(a), x) - a.begin();
        ll f2 = upper_bound(all(a), x) - a.begin();
        
        if (f1 == a.size() or a[f1] > x)    
            f1--; 
        if (f2 == a.size())
            f2--;
        
        power1 -= a[f1]; // subtract attacker power (fight-1) 
        power2 -= a[f2]; // sub attacker power(fight-2)
        // cout << f1 << " " << f2 << "\n";
        // fight-1
        if (a[f1] > x) // attacker more powerful than dragon
            ans1 += max(0LL, y - power1);
        else // attacker less powerful use coins
        {
            ans1 += (x - a[f1]); // add some coins for attacker
            ans1 += max(0LL, y - power1); // coin for defence
        }

        // fight-2
        if (a[f2] > x)
            ans2 += max(0LL, y - power2); // for def
        else
        {
            ans2 += (x - a[f2]);
            ans2 += max(0LL, y - power2); // def
        }

        cout << min(ans1, ans2) << "\n";
    }
}

int main()
{
    FIO
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}