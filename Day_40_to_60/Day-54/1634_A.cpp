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

bool palindrome(string &s, int st, int end)
{
	if (st >= end)
		return true;
	
	return (s[st] == s[end] and palindrome(s, st + 1, end - 1));
}

bool all_same(string &s)
{
	for(int i = 1; i < s.length(); i++)
		if (s[i] != s[i - 1])
			return false;
		
	return true;
}

void solve()
{
	int n, k; cin >> n >> k;
	string s; cin >> s;
	
	if (k == 0)
		cout << "1\n";
	
	else if (palindrome(s, 0, n - 1))
		cout << "1\n";
	
	else
		cout << "2\n";
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}