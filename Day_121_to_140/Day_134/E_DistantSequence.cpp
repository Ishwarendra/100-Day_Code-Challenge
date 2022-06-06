#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

constexpr int MOD = 998244353;

// assume -MOD <= x < 2*MOD
int norm(int x)
{
	if (x < 0)
		x += MOD;

	if (x >= MOD)
		x -= MOD;

	return x;
}
template<class T>
T power(T a, int b)
{
	T res = 1;
	for (; b; b /= 2, a *= a) {
		if (b % 2) {
			res *= a;
		}
	}
	return res;
}
struct Z
{
	int x;
	Z(int x = 0) : x(norm(x)) {}
	int val() const {
		return x;
	}
	Z operator-() const {
		return Z(norm(MOD - x));
	}
	Z inv() const {
		assert(x != 0);
		return power(*this, MOD - 2);
	}
	Z &operator*=(const Z &rhs) {
		x = (long long)(x) * rhs.x % MOD;
		return *this;
	}
	Z &operator+=(const Z &rhs) {
		x = norm(x + rhs.x);
		return *this;
	}
	Z &operator-=(const Z &rhs) {
		x = norm(x - rhs.x);
		return *this;
	}
	Z &operator/=(const Z &rhs) {
		return *this *= rhs.inv();
	}
	friend Z operator*(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res *= rhs;
		return res;
	}
	friend Z operator+(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res += rhs;
		return res;
	}
	friend Z operator-(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res -= rhs;
		return res;
	}
	friend Z operator/(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res /= rhs;
		return res;
	}
	friend std::istream &operator>>(std::istream &is, Z &a) {
		int v;
		is >> v;
		a = Z(v);
		return is;
	}
	friend std::ostream &operator<<(std::ostream &os, const Z &a) {
		return os << a.val();
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, k;
	std::cin >> n >> m >> k;

	if (k == 0)
	{
		std::cout << power(Z(m), n) << "\n";
		return 0;
	}

	std::vector<std::vector<Z>> dp(n, std::vector<Z>(m + 1, 0));
	std::vector<Z> pref(m + 1, 0), suff(m + 1, 0);

	for (int j = 1; j <= m; j++)
		dp[0][j] = 1;

	for (int i = 1; i <= m; i++)
		pref[i] += pref[i - 1] + dp[0][i];

	suff[m] = dp[0][m];
	for (int i = m - 1; i > 0; i--)
		suff[i] += suff[i + 1] + dp[0][i];

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			Z &cur = dp[i][j];

			if (j - k > 0)
				cur += pref[j - k];
			if (j + k <= m)
				cur += suff[j + k];
		}

		for (int id = 1; id <= m; id++)
			pref[id] = pref[id - 1] + dp[i][id];

		suff[m] = dp[i][m];
		for (int id = m - 1; id > 0; id--)
			suff[id] = suff[id + 1] + dp[i][id];
	}

	Z ans = 0;

	std::cout << std::accumulate(dp[n - 1].begin(), dp[n - 1].end(), Z(0)) << "\n";

	return 0;
}