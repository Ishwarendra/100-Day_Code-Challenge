#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

vector<string> two;

void make_power_vector()
{
    two.push_back("1");
    ll x = 1;
    while(x < 1e18)
    {
        x = (x << 1);
        string tmp = to_string(x);
        two.push_back(tmp);
    }
}

ll operation_cnt(const string &a, const string &b)
{
    int n = a.length(), m = b.length(); // convert a to b
    ll cnt = 0;
    
    int i = 0, j = 0;
    while(i < n and j < m)
    {
        if (a[i] == b[j])
            i++, j++;
        else
            cnt++, i++;
    }

    if(i == n and j != m) // a exhausetd b unexhausted so insert some
        cnt += (m - j);
    else // b exhausted so delete some from a
        cnt += (n - i); 

    return cnt;
}

void solve()
{
    ll n; cin >> n;
    string s = to_string(n);   

    ll ans = 1e10;
    for(int i = 0; i < two.size(); i++)
    {
        ll op = operation_cnt(s, two[i]);
        ans = min(ans, op);
    }

    cout << ans << "\n";
}

int main()
{
    FIO
    // int x = operation_cnt("1224565", "1024");
    // cout << x;
    make_power_vector();
    // for(int i = 0; i < 10; i++)
    // {
    //     cout << two[i] << " ";
    // }
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}