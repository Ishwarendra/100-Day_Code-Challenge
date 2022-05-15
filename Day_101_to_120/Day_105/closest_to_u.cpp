#include <bits/stdc++.h>
using namespace std;

#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};
void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

vector<vector<int>> adj;
vector<int> bfs(int src, int n)
{
	vector<int> dist(n + 1, -1);
	queue<int> q;

	dist[src] = 0;
	q.push(src);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nb : adj[cur])
		{
			if (dist[nb] == -1)
			{
				dist[nb] = 1 + dist[cur];
				q.push(nb);
			}
		}
	}

	return dist;
}

vector<int> print_(stack<int> path)
{
	vector<int> nodes;
	while (!path.empty())
	{
		// cout << path.top() << " ";
		nodes.push_back(path.top());
		path.pop();
	}
	// cout << "\n";
	return nodes;
}

void get_path(int src, int dest, vector<bool> &vis, stack<int> &s, vector<int> &a)
{
	s.push(src);
	vis[src] = true;

	if (src == dest)
	{
		a = print_(s);
		return;
	}

	for (int nb : adj[src])
	{
		if (not vis[nb])
			get_path(nb, dest, vis, s, a);
	}

	s.pop();
}

vector<int> solve(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
{
	adj.resize(n + 1);

	for (auto &edge : edges)
	{
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}

	vector<int> ans;

	for (auto q : query)
	{
		// find min distance of all nodes from w
		int u = q[0], v = q[1], w = q[2];
		vector<int> dist = bfs(w, n);
		
		// for (int i : dist)
		// 	cout << i << ' '; cout << "\n";
		
		// find all nodes from u to lca and lca to v
		// get min distance
		stack<int> path;
		vector<bool> vis(n + 1);

		vector<int> nodes;
		get_path(u, v, vis, path, nodes);
		
		// printarr(nodes, 0, nodes.size());
		
		int cur_ans = 1e9;
		int node = u;
		
		for (int i : nodes)
		{
			if (dist[i] < cur_ans)
				cur_ans = dist[i], node = i;
		}
		
		ans.push_back(node);
		// cout << cur_ans << " \n";
	}
	
	return ans;
}

int main()
{
	int n; cin >> n;
	vector<vector<int>> b(n, vector<int>(2));

	for (int i = 0; i < n - 1; i++)
	{
		cin >> b[i][0] >> b[i][1];
	}
	int q; cin >> q;
	vector<vector<int>> c(q, vector<int>(3));

	for (int i = 0; i < q; i++)
	{
		cin >> c[i][0] >> c[i][1] >> c[i][2];
	}

	vector<int> ans = solve(n, b, c);
	
	for (int i : ans)
		cout << i << " ";
}