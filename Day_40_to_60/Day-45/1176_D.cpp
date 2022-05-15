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

const int PRIME_SIZE = 2750133;
int prime[PRIME_SIZE];
int _prime[PRIME_SIZE];
void seive()
{
     std::memset(_prime, 1, sizeof _prime);
     _prime[0] = 0, _prime[1] = 0;
     for(int i = 2; i*i <= PRIME_SIZE; i++){
          if (_prime[i]){
               for(int j = i*i; j <= PRIME_SIZE; j += i)
                    _prime[j] = 0;
          }
     }
     
     int pos = 0;
     for(int i = 0; i < PRIME_SIZE; i++)
          if (_prime[i])
               prime[pos++] = i;
} 

int greatest_div(int x)
{
     for(int i = 2; i*i <= x; i++)
          if (x % i == 0)
               return x/i;
}


int main()
{
     FIO;
     seive();
     int n; cin >> n;
     
     multiset<int> b;
     // vi b_(2*n), vis(2*n);
     for(int i = 0; i < 2*n; i++)
     {
          int x; cin >> x;
          // b_[i] = x;
          b.insert(x);
     }
     
     while(!b.empty()){
          auto itr = ;
     }
     
     
     return 0;
}