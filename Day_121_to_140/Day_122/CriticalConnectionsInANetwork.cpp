#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

class Solution {
	vector<int> discover, reachable;
	set<vector<int>> bridges;
	int tme = 1;
	
	void dfs(int cur, int par, vector<vector<int>> &adj)
	{
		discover[cur] = reachable[cur] = tme++;
		
		for (int nb : adj[cur])
		{
			if (not discover[nb])
			{
				dfs(nb, cur, adj);
				
				reachable[cur] = min(reachable[cur], reachable[nb]);
				
				if (reachable[nb] > discover[cur])
					bridges.insert({max(cur, nb), min(cur, nb)});
			}
			
			else if (nb != par)
				reachable[cur] = min(reachable[cur], discover[nb]);
		}
	}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
    	discover.resize(n);
    	reachable.resize(n);
    	
    	vector<vector<int>> adj(n);
    	
    	for (auto edge : connections)
    	{
    		int u = edge[0], v = edge[1];
    		adj[u].push_back(v), adj[v].push_back(u);
    	}
    	
    	dfs(0, -1, adj);
    	
    	
    	return vector<vector<int>> (bridges.begin(), bridges.end());
    }
};

int main()
{
	
	return 0; 
}    