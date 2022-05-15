#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;
using vpll = vector<pair<int, int>>;
using pii = pair<int, int>;

bool good(int mid, vpll a, vpll b)
{
    return (b[mid].first > a[mid].first);
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n), b(n);

    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x;

    map<int, int> pos;

    for(int i = 0; i < n; i++)
    {
        pos[b[i]/2] = i;
    }

    for(int i = n - 1; i >= 1; i--)
    {
        pos[i] = min(pos[i], pos[i + 1]);
    }

    int ans = 1e8;
    
    for(int i = 0; i < n; i++)
    {
        int just_big = pos[(a[i] + 1)/2];
        ans = min(ans, just_big + i);
    }

    cout << ans << "\n";
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