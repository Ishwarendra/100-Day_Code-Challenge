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

// void solve()
// {
//     ll n;
//     cin >> n;

//     for (ll a = 2; a < n; a++)
//     {
//         if (__gcd(a, n - 1 - a) == 1)
//         {
//             cout << a << " " << n - 1 - a << " 1\n";
//             return;
//         }
//     }
// }

/*
Randomly Test op
*/
void solve()
{
    mt19937_64 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
    int n; cin >> n;
    while(true)
    {
        ll a = uniform_int_distribution<int>(2, n - 2)(rng);
        ll b = n - 1 - a;
        if (a != b and b != 1 and a != 1 and gcd(a, b) == 1)
        {
            cout << a << " " << b << " 1\n";
            return; 
        }
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