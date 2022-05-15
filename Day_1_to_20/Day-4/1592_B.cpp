#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using ull = unsigned long long;

bool check_pos(vll &a, vll &b, int x)
{
    int n = a.size();
    for(int i = n - x; i < x; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void solve()
{
    int n, x; cin >> n >> x;
    vll a(n);

    for(ll &x : a)         
        cin >> x;
    vll b = a;
    sort(all(b));

    if (is_sorted(all(a)))
        cout << "YES\n";
    else if (x <= n/2)
        cout << "YES\n";
    else 
    {
        if (check_pos(a, b, x))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    FIO
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}