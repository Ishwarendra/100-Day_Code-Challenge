#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0);

signed main()
{
    IOS
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int ans=0;
    vector<int> store(n);
    int p=1;
    for(int i=0;i<n/2 and p < n;i++)
    {
        store[p]=a[i];
        p+=2;
    }
    p=0;
    for(int i=n/2;i<n;i++)
    {
        store[p]=a[i];
        p+=2;
    }
    for(int i=1;i<n-1;i++)
    {
        if(store[i]<store[i-1] and store[i]<store[i+1])
        {
            ans++;
        }
    }
    cout << ans << '\n';
    for(auto i:store)
    {
        cout << i << ' ';
    }

    return 0;
}