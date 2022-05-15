#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi   =  vector<int>;
using vvi  =  vector<vector<int>>;
using vll  =  vector<long long>;
using vvll =  vector<vector<long long>>;
using ll   =  long long;
using ld   =  long double;
using ull  =  unsigned long long;
using pii  =  pair<int, int>;
using pll  =  pair<long long, long long>;

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
	
	vi p(n);
	
	for(auto &x: p)
		cin >> x;
	
	string s; cin >> s;
	
	vi liked, disliked;
	
	for(int i = 0; i < n; i++)	
	{
		if (s[i] == '1')
			liked.push_back(i);
		else
			disliked.push_back(i);
	}
	
	sort(all(liked), [&](const int i, const int j)
	{
		return p[i] > p[j];
	});
	
	sort(all(disliked), [&](const int i, const int j)
	{
		return p[i] > p[j];
	});
	
	vi q(n);
	
	int i, id = 0;
	
	for(i = n; i > n - liked.size(); i--)
		q[liked[id++]] = i;
	
	id = 0;
	
	for(; i > 0; i--)
		q[disliked[id++]] = i;
	
	log(q);
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}