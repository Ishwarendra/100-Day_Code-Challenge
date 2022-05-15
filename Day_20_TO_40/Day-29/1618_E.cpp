#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)              \
    for (int _i = (start); _i < (end); _i++) \
        cout << (v[_i]) << " ";              \
    cout << "\n";
#define log(v)                                                \
    for (auto __i = ((v).begin()); __i != ((v).end()); __i++) \
        cout << *(__i) << " ";                                \
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

ll ans(vll &b, ll &sum, int i)
{
    ll num = (b[i - 1] - b[i] + sum);
    ll den = b.size();

    if (num % den != 0)
        return -1;

    return num / den;
}

void solve()
{
    int n;
    cin >> n;
    vll b(n), a(n);
    ll sum = 0;

    for (int i = 0; i < n; i++)
        cin >> b[i], sum += b[i];

    if ((sum % (n * (n + 1) / 2)) != 0)
    {
        cout << "NO\n";
        return;
    }

    sum /= (n*(n + 1))/2;

    for (int i = 1; i < n; i++)
    {
        a[i] = ans(b, sum, i);
        if (a[i] <= 0)
        {
            cout << "NO\n";
            return;
        }
    }

    int coeff = n, idx = 1;
    a[0] = b[0];
    while (coeff != 1)
        a[0] -= coeff * a[idx], coeff--, idx++;

    if (a[0] <= 0)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (ll &ele : a)
        cout << ele << " ";
    cout << "\n";
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}