#include<bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

using i64 = long long; 

template<class T>
T power(T a, int b, int mod) {
    T res = 1;
    for (; b; b /= 2, a = (a * a) % mod) {
        if (b % 2) {
            res = (res % mod) * (a % mod) % mod;
        }
    }
    return (res % mod);
} 

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	
	i64 ans = power(2LL, m, MOD) - 1;
	ans = power(ans, n, MOD);
	
	std::cout << ans << "\n";
	
	return 0;
}