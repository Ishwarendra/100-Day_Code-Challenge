#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif


i64 merge(std::vector<i64> &a, int l, int mid, int r)
{
	int n = mid - l + 1, m = r - mid;

	vector<i64> temp(n + m);

	i64 inv_count = 0LL;

	int i = l, j = mid + 1, k = 0;

	while (i < mid + 1 and j <= r)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			inv_count += mid + 1 - i;
		}
	}

	while (i < mid + 1)
		temp[k++] = a[i++];

	while (j <= r)
		temp[k++] = a[j++];

	for (int i = 0; i < temp.size(); i++)
		a[l + i] = temp[i];

	return inv_count;
}

i64 inversionCount(std::vector<i64> &arr, int l, int r)
{
	i64 inv_count = 0LL;

	if (l >= r)
		return inv_count;

	int mid = (l + r) / 2;

	inv_count += inversionCount(arr, l, mid);
	inv_count += inversionCount(arr, mid + 1, r);
	inv_count += merge(arr, l, mid, r);

	return inv_count;
}


i64 inversionCount(std::vector<i64> &arr)
{
	i64 n = arr.size();
	return inversionCount(arr, 0, n - 1);
}

void solve()
{
	int n; 
	std::cin >> n;
	
	std::vector<i64> a(n);
	
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	
	i64 ans = inversionCount(a);
	
	std::cout << ans << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t--)
		solve();

	return 0;
} 