#include <bits/stdc++.h>

// #define LOCAL 1

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick 
{
	const int n;
	std::vector<T> a;
	
	Fenwick(int n) : n(n), a(n) {}
	Fenwick(const std::vector<T> inp) : n(inp.size()), a(inp.size())
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
	i64 n, a, b;
	std::cin >> n >> a >> b;
	
	std::vector<i64> x(n + 1);
	
	for (int i = 1; i <= n; i++)
		std::cin >> x[i];
	
	Fenwick<i64> ft(x);
	
	i64 ans = b * ft.sum(n);
	
	for (int i = 1; i < n; i++)
	{
		i64 cur =  a * x[i] + b * x[i] + b * (ft.rangeSum(i + 1, n) - x[i] * (n - i));
		ans = std::min(ans, cur);
	}
	
	std::cout << ans << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}