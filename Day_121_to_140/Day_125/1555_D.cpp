#include <bits/stdc++.h>


#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

template <typename T>
struct Fenwick 
{
	const int n;
	std::vector<T> a;
	
	Fenwick(int n) : n(n), a(n) {}
	Fenwick(const std::vector<int> inp) : n(inp.size()), a(inp.size())
	{
		for (int i = 0; i < n; i++)
			add(i, inp[i]);
	}
	void add(int x, T v) 
	{
		for (int i = x + 1; i <= n; i += i & -i) {
			a[i - 1] += v;
		}
	}
	T sum(int x)  
	{
		T ans = 0;
		x++;
		for (int i = x; i > 0; i -= i & -i) {
			ans += a[i - 1];
		}
		return ans;
	}
	T rangeSum(int l, int r) 
	{
		if (l - 1 < 0)
			return sum(r);
		
		return sum(r) - sum(l - 1);
	}
};

void solve()
{
	int n, m;
	std::cin >> n >> m;
	
	std::string s;
	std::cin >> s;
	
	std::string generator = "abc";
	std::vector<Fenwick<int>> a;
		
	do 
	{
		std::string tmp(n, 'x');
		
		for (int i = 0; i < n; i++)
			tmp[i] = generator[i % 3];
		
		std::vector<int> op(n);
		
		for (int i = 0; i < n; ++i)
			op[i] = s[i] != tmp[i];
		
		a.push_back(Fenwick<int>(op));
		
	} while (std::next_permutation(generator.begin(), generator.end()));
	
	while (m--)
	{
		int l, r;
		std::cin >> l >> r;
		l--, r--;
		
		int ans = 1e9;
		
		for (int i = 0; i < 6; i++)
		{
			Fenwick<int> &ft = a[i];
			ans = std::min(ans, ft.rangeSum(l, r));
		}
		
		std::cout << ans << "\n";
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	// std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}