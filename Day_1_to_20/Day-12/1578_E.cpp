#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;

ll max_power_2(ll n)
{
    ll power = 0;
    while((1 << power) <= n)
        power++;
    
    return power - 1;
}

void solve()
{
    ll h, p;
    cin >> h >> p;

    ll time = 0;
    ll finish = max_power_2(p) + 1, to_do = 0;
    time += min(finish, h);

    while (finish < h)
        to_do += pow(2, finish), finish++;

    time += ceil(to_do/(ld)(p));
    // cout << ceil(to_do/(ld)(p)) << "\n";
    cout << time << "\n";
}

int main()
{
    FIO
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    // cout << max_power_2(7) << " " << max_power_2(17);
    return 0;
}