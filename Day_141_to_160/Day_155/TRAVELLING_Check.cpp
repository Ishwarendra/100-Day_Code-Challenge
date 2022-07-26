#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

void slv(){
    int n, m; cin >> n >> m; 

    vector<vi> g(n + 1);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; 

        g[u].push_back(v);
        g[v].push_back(u);
    }
    set<pii> D;
    
    vi vis(n + 1);

    D.insert({0, 1});

    while(D.empty()==false){
        auto p = *D.begin();

        D.erase(p);

        if(vis[p.ss]) continue;

        vis[p.ss] = 1;

        if(p.ss == n){
                cout << p.ff << endl; return;
        }
        for(auto q : g[p.ss]){
                if(not vis[q])
                        D.insert({p.ff, q});
        }

        D.insert({p.ff + 1, p.ss + 1});
        D.insert({p.ff + 1, p.ss - 1});
    }
}

int32_t main(){
        FIO 

        w(T) slv();

        return 0;
}