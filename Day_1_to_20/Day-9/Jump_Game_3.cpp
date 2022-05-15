#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

bool within_bounds(int x, int u)
{
    return (x < u and x >= 0);
}

bool canReach(vector<int> &arr, int start)
{
    int n = arr.size();

    queue<int> q; // keep indices here
    vector<bool> vis(n, false); 

    q.push(start);
    while(!q.empty())
    {
        int cur_node = q.front(), cur_size = q.size();
        vis[cur_node] = true;
        q.pop();

        for(int i = 0; i < cur_size; i++)
        {
            int state1 = cur_node + arr[cur_node];
            int state2 = cur_node - arr[cur_node];

            if (within_bounds(state1, n) and not vis[state1])
            {
                if (arr[state1] == 0)
                    return true;
                else
                    q.push(state1);
            }

            if (within_bounds(state2, n) and not vis[state2])
            {
                if (arr[state2] == 0)
                    return true;
                else
                    q.push(state2);
            }
        }
        return false;
    }
}

int main()
{
    FIO int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}