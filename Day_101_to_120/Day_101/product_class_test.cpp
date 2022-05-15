#include <bits/stdc++.h>
using namespace std;

int SumOfKsubArray(vector<int> &arr, int k)
{
	int n = arr.size();
	int miv = INT_MAX, mi, mav = INT_MIN, ma, cum_sum = 0, i = 0, st = 0;
	while (i < n)
	{
		if (miv < arr[i])
		{
			miv = arr[i];
			mi = i;
		}
		if (mav < arr[i])
		{
			mav = arr[i];
			ma = i;
		}
		if (i - st + 1 == k)
		{
			cum_sum += miv + mav;
			++st;
			if (mi < st)
				miv = INT_MAX;
			if (ma < st)
				mav = INT_MIN;
		}
		++i;
	}
	cout << cum_sum;
}

int main()
{
		vector<int> arr {2, 5, -3, -10};
		int k = 3;
	SumOfKsubArray(arr, k);
	return 0;
}