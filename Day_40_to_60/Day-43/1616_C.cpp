#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vvi = vector<vector<int>>;
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

void solve()
{
     int n; cin >> n;
     vi a(n);
     for(int i = 0; i < n; i++)
          cin >> a[i];
     
     if (n == 1 or n == 2)
     {
          cout << "0\n";
          return;
     }
     
     int ans = n - 1;
     for(int i = 0; i < n; i++)
     {
          for(int j = i + 1; j < n; j++)
          {
               // Fix i and j try to change others
               int d = a[j] - a[i];
               int x = j - i;
               int cur_ans = 0;
               for(int k = 0; k < n; k++){
                    int y = i - k;
                    if (a[k]*x != a[i]*(x + y) - a[j]*y)
                         cur_ans++;
               }
               ans = min(ans, cur_ans);
          }
     }
     cout << ans << "\n";
}

int main()
{
     // FIO;
     int t = 1;
     cin >> t;
     while(t--)
         solve();
     // cout << t << "\n";
     return 0;
}