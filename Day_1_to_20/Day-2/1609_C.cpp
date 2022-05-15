#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;
#define int long long

vector<bool> prime(1e6 + 3, true);

void seive()
{
    int n = 1e6 + 3;
    prime[0] = false; prime[1] = false;
    for(int i = 2; i < n; i++)
    {
        if (prime[i])
        {   
            for(int j = i*i; j < n; j += i)    
                prime[j] = false;
        }
    }
}

void print(vi &a)
{
    for(int i : a)
        cout << i << " ";
    cout << "\n";
}

void solve()
{
    // input
    int n, e;
    cin >> n >> e;
    vector<int> a(n), ones;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            ones.push_back(i);
    }

    // prefix suffix time
    vector<int> pref(n), suf(n);

    for(int i = 0; i < ones.size(); i++)  
        pref[ones[i]] = (ones[i] - e >= 0) ? pref[ones[i] - e] + 1 : 1;

    // // reverse(ones.begin(), ones.end()); // iterate ones from backward for suffix
    // for(int i = 0; i < ones.size(); i++)   
    //     suf[ones[i]] = (ones[i] + e < n) ? suf[ones[i] + e] + 1 : 1;

    for(int i = ones.size() - 1; i >= 0; i--)
        suf[ones[i]] = (ones[i] + e < n) ? suf[ones[i] + e] + 1 : 1;

    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        if (prime[a[i]])
        {
            int pr = 0, sf = 0;
            if (i >= e)
                pr = pref[i - e], ans += pr;
            if (i + e < n)
                sf = suf[i + e], ans += sf;
            
            ans += (pr * sf);
        }
    }

    cout << ans << "\n";
}

int32_t main()
{
    FIO
    seive();
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}