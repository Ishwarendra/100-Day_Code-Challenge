#include <bits/stdc++.h>

using i64 = long long;

i64 merge(std::vector<int> &a, int l, int r, int mid)
{	
	i64 inversions = 0LL;
	std::vector<int> c(r - l + 1);
	
	int i = l, j = mid + 1, k = 0;
	
	while (i <= mid and j <= r)
	{
		if (a[i] <= a[j])
			c[k++] = a[i++];
		else
		{
			c[k++] = a[j++];
			inversions += (mid - i + 1);
		}
	}
	
	while (i <= mid)
	{
		assert(k < c.size());
		c[k++] = a[i++];
	}
	
	while (j <= r)
		c[k++] = a[j++];
	
	k = 0;
	for (i = l; i <= r; i++)
		a[i] = c[k++];
	
	return inversions;
}

i64 mergeSort(std::vector<int> &a, int left, int right)
{
	i64 inversions = 0LL;
	
	if (left < right)
	{
		int mid = (left + right) / 2;
		
		inversions += mergeSort(a, left, mid);
		inversions += mergeSort(a, mid + 1, right);
		
		inversions += merge(a, left, right, mid);
	}
	
	return inversions;
}

void solve()
{
	int k, n;
	std::cin >> k >> n;
	
	while(k--)
	{
		std::vector<int> a(n);
		
		for (int i = 0; i < n; i++)	
			std::cin >> a[i];
		
		i64 ans = mergeSort(a, 0, n - 1);	
		
		std::cout << (n - ans) / n << "\n";
	}
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