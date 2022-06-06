#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

template <typename T, class F = std::function<T(const T&, const T&)>>
class SparseTable 
{
public:
	int n;
	std::vector<std::vector<T>> mat;
	F func;

	SparseTable(const std::vector<T>& a, const F& f) : func(f) 
	{
		n = static_cast<int>(a.size());
		int max_log = 32 - __builtin_clz(n);
		mat.resize(max_log);
		mat[0] = a;
		for (int j = 1; j < max_log; j++) 
		{
			mat[j].resize(n - (1 << j) + 1);
			for (int i = 0; i <= n - (1 << j); i++) 
				mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
			
		}
	}

	T get(int from, int to) const 
	{
		assert(0 <= from && from <= to && to <= n - 1);
		int lg = 32 - __builtin_clz(to - from + 1) - 1;
		return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<long long> a(n);

	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	SparseTable <i64> st(a, [&](i64 i, i64 j) { return std::min(i, j); });

	int q;
	std::cin >> q;

	while (q--)
	{
		int l, r;
		std::cin >> l >> r;

		std::cout << st.get(l, r) << "\n";
	}

	return 0;
}