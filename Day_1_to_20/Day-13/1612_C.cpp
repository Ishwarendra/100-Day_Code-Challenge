#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

bool good1(ll mid, ll x)
{
    return (mid * (mid + 1)) <= 2 * x;
}

bool good2(ll i, ll x, ll k)
{
    return (i * (2 * k - i - 1)) <= 2 * x;
}

void solve()
{
    ll k, x;
    cin >> k >> x;

    ll ans = 0;
    if (k * (k + 1) > 2 * x) // find range of k
    {
        ll low = 1, high = k;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (good1(mid, x))
                ans = mid, low = mid + 1;
            else
                high = mid - 1;
        }

        if (ans * (ans + 1) / 2 < x)
            ans++;
    }

    else // Find range of i
    {
        x -= (k * (k + 1)) / 2;
        int low = 0, high = k - 1;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (good2(mid, x, k))
                ans = mid, low = mid + 1;
            else
                high = mid - 1;
        }
        if (ans * (2 * k - ans - 1)< 2*x)
            ans++;
        ans += k;
    }

    cout << min(ans, 2*k - 1) << "\n";
}

int main()
{
    FIO; 
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}