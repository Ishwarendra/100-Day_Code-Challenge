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
void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

int f(char c1, char c2)
{
	if (c1 == '1' and c2 == '0')
		return 0;
	else if (c1 == '0' and c2 == '1')
		return 1;
	else if (c1 == '1' and c2 == '1')
		return 2;

	return 3;
}

vvi pos(4);

void print_ans(int c, int a, int ca, int n)
{
	for (int i = 0; i < c; i++)
		cout << pos[0][i] + 1 << " ";

	for (int i = 0; i < a; i++)
		cout << pos[1][i] + 1 << " ";

	for (int i = 0; i < ca; i++)
		cout << pos[2][i] + 1 << " ";

	for (int i = 0; i < n; i++)
		cout << pos[3][i] + 1 << " ";

	cout << "\n";
}

void solve()
{
	int n; string clown, acro;
	cin >> n >> clown >> acro;

	for (auto &i : pos)
		i.clear();

	for (int i = 0; i < n; i++)
		pos[f(clown[i], acro[i])].push_back(i);

	int t1 = pos[0].size(), t2 = pos[1].size(),
	    t3 = pos[2].size(), t4 = pos[3].size();
	    
	// print(t1, t2, t3, t4);
	    
	for (int a = 0; a <= pos[1].size(); a++)
	{
		for (int c = 0; c <= pos[0].size(); c++)
		{
			int rhs = t2 + t3 - a - c;

			if (rhs % 2 == 0)
			{
				int ca = rhs / 2;
				int nil = (n / 2) - a - ca - c;

				if (nil >= 0 and nil <= t4 and ca >= 0 and ca <= t3)
				{
					print_ans(c, a, ca, nil);
					return;
				}
			}
		}
	}

	cout << "-1\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	for (int i = 1; i <= t; i++)
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