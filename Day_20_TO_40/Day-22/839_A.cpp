#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)           \
    for (int i = (start); i < (end); i++) \
        cout << (v[i]) << " ";            \
    cout << "\n";
#define log(v)                                          \
    for (auto i = ((v).begin()); i != ((v).end()); i++) \
        cout << *(i) << " ";                            \
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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int &x : a)
        cin >> x;

    int day = 1, choc_left = 0, choc = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 8)
            choc_left += a[i] - 8, choc += 8;
        else if (a[i] + choc_left >= 8)
            choc_left -= (8 - a[i]), choc += 8;
        else
            choc += a[i] + choc_left, choc_left = 0;
        // print(day, choc)
        if (choc >= k)
        {
            cout << day << "\n";
            return;
        }
        day++;
    }

    if (day <= n and choc >= 8)
    {
        cout << day << "\n";
    }
    else
        cout << "-1\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}