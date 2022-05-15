#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll pair_with_sum_K(vll &a, ll k)
{
    unordered_map<ll, int, custom_hash> m;
    ll ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ans += m[k - a[i]];
        m[a[i]]++;
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vll a(n);
    ll sum = 0LL;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (2 * sum % n != 0)
        cout << "0\n";
    else
    {
        ll k = (2 * sum) / n;
        ll ans = pair_with_sum_K(a, k);
        cout << ans << "\n";
    }
}

int main()
{
    FIO int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}