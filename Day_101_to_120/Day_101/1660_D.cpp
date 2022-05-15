#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(a)      ((a).begin()), ((a).end())
#define log(v)      for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int         long long
#define fps(x, y)   fixed<<setprecision((y))<<(x)

#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using maxheap  =    priority_queue<T>;
template<typename T>
using minheap  =    priority_queue<T, vector<T>, greater<T>>;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.second; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.second; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};


void solve()
{
	int n; cin >> n;
	
	vi a(n);
	
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	vvi answers;
	
	auto add_ans = [&](int st, int en)
	{
		if (en < st)
			return;
		
		if (st == en)
		{
			if (a[st] > 0)
				answers.push_back({abs(a[st]) == 2, st, en});
			else
				return;
		}
		
		int prod = 0;
		int neg = 0;
		int fn = en, ln = st;
		
		for (int i = st; i <= en; i++)
		{
			neg ^= a[i] < 0;
			if (abs(a[i]) == 2)
				prod++;
			
			if (a[i] < 0)
				fn = min(fn, i), ln = max(ln, i);
		}	
		
		if (!neg)
			answers.push_back({prod, st, en});
		else
		{
			int pprod = 0, sprod = 0;
			
			for (int i = fn + 1; i <= en; i++)
				pprod += abs(a[i]) == 2;
			
			for (int i = st; i <= ln - 1; i++)
				sprod += abs(a[i]) == 2;
			
			if (pprod > sprod)
				answers.push_back({pprod, fn + 1, en});
			else
				answers.push_back({sprod, st, ln - 1});
		}
	};
	
	answers.push_back({0, n, n - 1});
	
	vvi options;
	
	int st = 0, en = 0;
	
	for (int i = 0; i < n;)
	{
		if (a[i] == 0)
		{
			i++;
			continue;
		}
		
		st = i;
		while (i < n and a[i] != 0)
			i++;
		en = i - 1;
		
		options.push_back({st, en});
	}
	
	for (auto i : options)
		add_ans(i[0], i[1]);
	
	sort(all(answers), greater<vi>());
	
	print(answers[0][1], n - answers[0][2] - 1);
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	std::cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		// std::cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}
/* credits: harasees_singh :maaf_karo:
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/