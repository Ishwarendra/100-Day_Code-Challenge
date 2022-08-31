#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0);

struct unionfind
{
    vector<int> city,power,p;
    unionfind(int n,int m)
    {
        p.resize(n+m+1);
        city.resize(n+m+1,0);
        power.resize(n+m+1,0);
        for(int i=1;i<=n+m;i++)
        {
            p[i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            city[i]=1;
        }
        for(int i=n+1;i<=n+m;i++)
        {
            power[i]=1;
        }
    }
    int find(int x)
    {
        return (p[x]==x?x:p[x]=find(p[x]));
    }
    void merge(int x,int y)
    {
        int a=find(x),b=find(y);
        if(city[a]+power[a]<city[b]+power[b])
        {
            swap(a,b);
        }
        city[a]+=city[b];
        power[a]+=power[b];
        p[b]=a;
    }
    bool connected(int x,int y)
    {
        return find(x)==find(y);
    }
};
signed main()
{
    IOS
    int n,m,x;
    cin >> n >> m >> x;
    vector<pair<int,int>> pa(x+1);
    for(int i=1;i<=x;i++)
    {
        int a,b;
        cin >> a >> b;
        pa[i]={a,b};
    }
    int q;
    cin >> q;
    unionfind dsu(n,m);
    vector<int> queries(q);
    vector<bool> used(x+1,1);
    for(int i=0;i<q;i++)
    {
        cin >> queries[i];
        used[queries[i]]=0;
    }
    for(int i=1;i<=x;i++)
    {
        if(used[i])
        {
            dsu.merge(pa[i].first,pa[i].second);
        }
    }
    vector<int> ans;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(dsu.power[dsu.find(i)]>=1)
        {
            cnt++;
        }
    }
    ans.push_back(cnt);
    for(int i=q-1;i>=1;i--)
    {
        int x=dsu.find(pa[queries[i]].first);
        int y=dsu.find(pa[queries[i]].second);
        if(dsu.power[x]==0 and dsu.power[y]>=1)
        {
            cnt+=dsu.city[x];
        }
        if(dsu.power[y]==0 and dsu.power[x]>=1)
        {
            cnt+=dsu.city[y];
        }
        ans.push_back(cnt);
        dsu.merge(x,y);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << '\n';
    }
    
    return 0;
}