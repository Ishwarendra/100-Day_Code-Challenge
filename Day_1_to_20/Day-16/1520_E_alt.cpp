#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)           \
    for (int i = (start); i < (end); i++) \
        cout << (v[i]) << " ";            \
    cout << "\n";
#define print(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
        cout << "\n";                            \
    };

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
    int n;
    string s;
    cin >> n >> s;

    vector<int> s_pos;
    for (int i = 0; i < n; i++)
        if (s[i] == '*')
            s_pos.push_back(i);

    int meet_id = s_pos.size() / 2;
    int l = meet_id - 1, r = meet_id + 1, lc = 1, rc = 1;
    long long ans = 0;
    if (s_pos.empty())
        cout << "0\n";
    else
    {
        while (l >= 0 or r < s_pos.size())
        {
            if (l >= 0)
                ans += (s_pos[meet_id] - s_pos[l] - lc), lc++, l--;
            if (r < s_pos.size())
                ans += (s_pos[r] - s_pos[meet_id] - rc), rc++, r++;
        }
        cout << ans << "\n";
    }

}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}