#include <bits/stdc++.h>
using namespace std;

class Solution {
	void print(vector<int> &a)
	{
		for (int i : a)
			cout << i << " "; cout << "\n";
	}
	
	void print(vector<vector<int>> &a)
	{
		for (auto i : a)
		{
			for (auto j : i)
				cout << j << " "; cout << "\n";
		}
	}
	
	void dfs(int cur, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &comp)
	{
		comp.push_back(cur);
		vis[cur] = true;
		
		for (int nb : adj[cur])
		{
			if (!vis[nb])
				dfs(nb, adj, vis, comp);
		}
	}
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    	int n = s.length();
    	
  		vector<vector<int>> adj(n);
  		
  		for (auto &p : pairs)
  		{
  			int u = p[0], v = p[1];
  			adj[u].push_back(v);
  			adj[v].push_back(u);
  		}	    
  		
  		vector<vector<int>> options;
  		vector<bool> vis(n);
  		
  		int start = -1;
  		
  		for (int i = 0; i < n; i++)
  		{
  			vector<int> comp;
			if (not vis[i])
			{
				dfs(i, adj, vis, comp);
				
				sort(comp.begin(), comp.end(), [&](int x, int y)
				{
					return s[x] < s[y];
				});
				
				options.push_back(comp);
				
				if (i == 0)
					start = comp[0];
			}
  		}
  		
  		string ans(n, '#');
  		
  		for (int i = 0; i < options.size(); i++)
  		{
  			if (options[i][0] == start)
  			{
  				vector<int> index = options[i];
  				sort(index.begin(), index.end());
  				
  				for (int id = 0; id < index.size(); id++)
  				{
  					ans[index[id]] = s[options[i][id]];
  				}
  			}
  		}
  		
  		for (int i = 0; i < options.size(); i++)
  		{
  			if (options[i][0] != start)
  			{
  				vector<int> index = options[i];
  				sort(index.begin(), index.end());
  				
  				for (int id = 0; id < index.size(); id++)
  				{
  					ans[index[id]] = s[options[i][id]];
  				}
  			}
  		}
  		
  		return ans;
    }
};

int main()
{
	string s; cin >> s;
	int n; cin >> n;
	vector<vector<int>> pairs(n, vector<int>(2));
	
	for (int i = 0; i < n; i++)
		cin >> pairs[i][0] >> pairs[i][1];
	
	Solution a;
	cout << a.smallestStringWithSwaps(s, pairs);
	
	return 0; 
}    