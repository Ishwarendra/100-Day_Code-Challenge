#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)               \
     for (int _i = (start); _i < (end); _i++) \
          cout << (v[_i]) << " ";             \
     cout << "\n";
#define log(v)                                                 \
     for (auto __i = ((v).begin()); __i != ((v).end()); __i++) \
          cout << *(__i) << " ";                               \
     cout << "\n";
#define print(args...)                             \
     {                                             \
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
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
     cout << a << " ";
     err(++it, args...);
};

int getBit(int x, int pos)
{
     if (x == 0)
          return x;

     return (x & (1 << pos)) != 0;
}

void solve()
{
     int n;
     cin >> n;
     // vi a(n);
     vi cnt(31);
     for (int i = 0; i < n; i++)
     {
          int x;
          cin >> x;
          for (int pos = 0; pos <= 30; pos++)
          {
               if (getBit(x, pos))
                    cnt[pos]++;
          }
     }

     int g = 0;
     for (int i : cnt)
          g = __gcd(g, i);

     vi ans;
     for (int i = 1; i <= n; i++)
     {
          if (g % i == 0)
               ans.push_back(i);
     }

     log(ans);
}

int main()
{
     FIO;
     int t = 1;
     cin >> t;
     while (t--)
          solve();
     return 0;
}