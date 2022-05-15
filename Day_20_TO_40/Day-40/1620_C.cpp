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

vll asterisk_cnt(const string &s)
{
     vll c;
     ll cur_cnt = 0, i = s.length() - 1;
     while (i >= 0)
     {
          if (s[i] == '*')
               cur_cnt++;
          else if (s[i] == 'a' and cur_cnt != 0)
               c.push_back(cur_cnt), cur_cnt = 0;
          i--;
     }

     if (cur_cnt)
          c.push_back(cur_cnt);
     return c;
}

vll to_mixed_base(ll n, vll &bases)
{
     vll dig;
     int id = 0;
     while(n != 0)
     {
          dig.push_back(n % bases[id]);
          n /= bases[id++];
     }
     return dig;
}

string beautify(string s)
{
     string ans;
     bool first_aster = true;
     for(int i = 0; i < s.length(); i++)
     {
          if (s[i] == 'a')
               ans += s[i], first_aster = true;
          else if (s[i] == '*' and first_aster)
               ans += s[i], first_aster = false;
     }
     return ans;
}

void solve()
{
     ll n, k, x;
     cin >> n >> k >> x;
     string s;
     cin >> s; 
     
     vll c = asterisk_cnt(s);
     for(ll &i : c)
          i = (i*k + 1);

     vll dig = to_mixed_base(x - 1, c);
     int dig_sz = dig.size();
     while(dig_sz < c.size())
          dig.push_back(0), dig_sz++;

     s = beautify(s);
     int pos = dig.size() - 1;
     for(int i = 0; i < s.length(); i++)
     {
          if (s[i] == '*')
          {
               for(int j = 0; j < dig[pos]; j++)
                    cout << 'b';
               pos--;
          }
          else
               cout << 'a';
     }

     cout << endl;
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