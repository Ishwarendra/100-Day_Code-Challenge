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

// less or eq
bool lessthaneq(const string &a, const string &b)
{
	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++)
			if (a[i] != b[i])
				return a[i] < b[i];
			
		return true;
	}
	
	return a.length() < b.length();
}

bool all_9(string &s, int start = 0)
{
	for (int i = start; i < s.length(); i++)
		if (s[i] != '9')
			return false;
		
	return true;
}

void perform_op(string &a, string &b, int &cnt)
{
	// first point of diff
	int st = 0;
	
	if (a.length() == b.length())
		a += '0', cnt++;
	else
	{
		int n = a.size(), m = b.size();
		int fpod = n;
		
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				fpod = i;
				break;
			}
		} 
		
		if (fpod == n) //  a is prefix of b
		{
			if (all_9(b, fpod))
			{
				while (a.length() <= b.length())
					a += '0', cnt++;
			}
			else
			{
				int pos = fpod;
				int msbChanged = 0;
				
				while (a.length() < b.length())
				{
					if (msbChanged)
						a += '0', cnt++;
					else if (b[pos] - '0' < 9)
						a += b[pos] + 1, cnt++, msbChanged = 1;
					else
						a += '0', cnt++;
				}
			}
		}	
		else
		{
			if (a[fpod] > b[fpod])
			{
				while (a.length() < b.length())
					a += '0', cnt++; 
			}
			else
			{
				while (a.length() <= b.length())
					a += '0', cnt++;
			}
		}
		
	}	
}

void solve()
{
	int n; cin >> n;
	int cnt = 0;
		
	vector<string> a(n);
	
	int tmp = 0;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		
		if (i > 0 and lessthaneq(a[i], a[i - 1]))
		{
			perform_op(a[i], a[i - 1], cnt);				
		}
	}
	
	cout << cnt << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	std::cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		std::cout << "Case #" << i << ": ";
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