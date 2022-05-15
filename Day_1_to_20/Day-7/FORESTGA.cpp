#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ull = long long;

bool good(ull mid, vector<pair<ull, ull>> &v, ull w, ull l)
{
    ull wood = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if (mid >= ceil(l - v[i].first)/v[i].second)
        {
            wood += (v[i].first + mid*v[i].second);
            if (wood >= w) // to check overflow or not
                return true;
        }
    }

    return (wood >= w);
}

void solve()
{
    ull n, w, l;
    cin >> n >> w >> l;

    vector<pair<ull, ull>> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    ull left = 0, right = 1e18, ans  = -1;
    while(left <= right)
    {
        ull mid = left + (right - left)/2;
        if (good(mid, v, w, l))
        {
            right = mid - 1;
            ans = mid;
        }
        else
            left = mid + 1;
    }   

    cout << ans << "\n";
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