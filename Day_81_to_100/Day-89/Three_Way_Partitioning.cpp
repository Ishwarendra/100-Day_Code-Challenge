#include <bits/stdc++.h>
using namespace std;

class Solution {
	int partition(vector<int> &a, int pivot_id, int l, int r)
	{
		swap(a[pivot_id], a[r]);
		
		int i = l - 1, j = l;
		while (j < r)
		{
			if (a[j] <= a[r])
			{
				i++;
				swap(a[i], a[j]);
			}
			j++;
		}
		
		i++;
		swap(a[i], a[r]);
		
		return i;
	}
	
	void print(vector<int> &a)
	{
		for (int i : a)
			cout << i << ' ';
		
		cout << "\n";
	}
	
	int closest(vector<int> &a, int x)
	{
		// finds the maximum element less than or equal to x 	
		int min_id = -1, n = a.size();
		
		for (int i = 0; i < n; i++)
		{
			if (a[i] - x < 0)
			{
				min_id = i;
				break;
			}
		}
		
		if (min_id == -1)
			return min_element(a.begin(), a.end()) - a.begin();
		
		for (int i = 0; i < n; i++)
		{
			if (a[i] - x > 0)
				continue;
			
			if (a[i] - x > a[min_id] - x)
				min_id = i;
		}
		
		return min_id;
	}
	
public:
	void threeWayPartition(vector<int> &a, int x, int y)
	{
		int i1 = closest(a, x);
		
		int st = partition(a, i1, 0, a.size() - 1);
		
		int i2 = closest(a, y);
		
		partition(a, i2, st, a.size() - 1);
		
		print(a);
	}
};

int main()
{
	// vector<int> arr {97, 82, 6, 26, 85, 28, 37, 6, 47, 30, 14};
	// int a= 8, b = 32;
	vector<int> arr = {44, 12, 29, 30, 77, 5, 29, 64, 14};
	int a = 39, b = 45;
	Solution ans;
	ans.threeWayPartition(arr, a, b);
	return 0;
}