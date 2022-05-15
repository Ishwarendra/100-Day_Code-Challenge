#include <bits/stdc++.h>
using namespace std;

template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
  		int n = points.size();
  		
  		auto length = [&](int i, int j)
  		{
  			return abs(points[i][0] - points[j][0])
  				+ abs(points[i][1] - points[j][1]);	
  		};
  		
  		minheap<pair<int, int>> pq;
  		
  		pq.push({0, 0});
  		
  		int mst_cost = 0;
  		vector<bool> vis(n);
  		
  		while (!pq.empty())
  		{
  			auto best = pq.top();
  			pq.pop();
  			
  			int to = best.second;
  			int wt = best.first;
  			
  			if (vis[to])
  				continue;
  			
  			mst_cost += wt;
  			vis[to] = true;
  			
  			for (int i = 0; i < n; i++)	
  			{
  				if (not vis[i])
  					pq.push({length(i, to), i});
  			}
  		}
	  		
  		return mst_cost;
    }
}; 


int main()
{
	Solution a;
	int n; cin >> n;
	vector<vector<int>> points(n, vector<int>(2));
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 2; j++)
			cin >> points[i][j];
	
	cout << a.minCostConnectPoints(points);	
	
	return 0;
}






