#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll x, y;
    cin >> x >> y;

    // (n % x == y % n == k)
    if (x > y)
        cout << x + y << "\n";
    else if (x == y or y % x == 0)
        cout << x << "\n";
    else
    {
        // y = xq + r
        ll q = y / x;
        ll r = y % x;
        cout << (x*q + y)/2LL<< "\n";
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}