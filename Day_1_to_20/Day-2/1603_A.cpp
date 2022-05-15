#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);

    for(ll &x : a) cin >> x;
    bool possible = true;

    ll current_lcm = 2;
    for(int i = 0; i < n; i++)
    {
        if (a[i] % current_lcm == 0)
            possible = false;
        current_lcm = (current_lcm * (i + 3LL)) / __gcd(current_lcm, i + 3LL);
    }

    cout << (possible ? "YES\n" : "NO\n");
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}