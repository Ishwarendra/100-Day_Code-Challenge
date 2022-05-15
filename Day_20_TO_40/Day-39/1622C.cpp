#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)                \
      for (int _i = (start); _i < (end); _i++) \
            cout << (v[_i]) << " ";            \
      cout << "\n";
#define log(v)                                                  \
      for (auto __i = ((v).begin()); __i != ((v).end()); __i++) \
            cout << *(__i) << " ";                              \
      cout << "\n";
#define print(args...)                               \
      {                                              \
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

void make_prefix(vll &prefix, const vll arr)
{
      prefix[0] = arr[0];
      for (int i = 1; i < arr.size(); i++)
            prefix[i] = arr[i] + prefix[i - 1];
}

void solve()
{
      ll n, k;
      cin >> n >> k;
      vll a(n), prefix(n);

      for (int i = 0; i < n; i++)
            cin >> a[i];

      sort(all(a));
      make_prefix(prefix, a);

      ll ans = 1e17;
      // y = set op
      for(int y = 0; y < n; y++)
      {
            ll sum = prefix[n - y - 1] + a[0]*y - k;
            ll cur_op = y;
            if (sum > 0)
            {
                  ll num = sum, den = y + 1;
                  cur_op += (sum + y)/(y + 1);
            }

            ans = min(ans, cur_op);
      }

      cout << ans << "\n";
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