#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

ll get_max_length(string s, int a, int b)
{
    bool a_turn = true;
    ll ans = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] - '0' == a and a_turn)
            ans++, a_turn = false;
        else if (s[i] - '0' == b and not a_turn)
            ans++, a_turn = true;
    }

    if (ans % 2 == 1 and a != b)
        ans--;
    
    return ans;
}

void solve()
{
    string s; cin >> s;

    ll ans = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
            ans = max(ans, get_max_length(s, i, j));
    }    

    cout << s.length() - ans << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}