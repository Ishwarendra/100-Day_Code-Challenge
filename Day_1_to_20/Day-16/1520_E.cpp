#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int i = (start); i < (end); i++) cout << (v[i]) << " ";cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    vector<int> id, s_pos;
    for(int i = 0; i < n; i++)
    {
        if (s[i] == '*')
            id.push_back(i);
    }
    
    for(int i = 0; i < id.size(); i++)
    {
        s_pos.push_back(id[i] - i);
    }

    printarr(id, 0, id.size())
    printarr(s_pos, 0, s_pos.size());
    if (s_pos.size() == 0)
        cout << "0\n";
    else
    {
        ll ans = 0;
        int mid = s_pos[s_pos.size()/2];

        for(int i : s_pos)
        {
            ans += abs(mid - i);
            print(i, " = ", mid - i);
        }
        cout << ans << "\n";
    }
    


}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}