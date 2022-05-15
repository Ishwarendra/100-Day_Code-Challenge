#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

// void prepare_pref_sum(vector<ll> &pref, vector<int> &arr)
// {
//     pref[0] = arr[0];
//     for(int i = 1; i < arr.size(); i++)
//         pref[i] += pref[i - 1]; 
// }  

void solve()
{
    ll n; cin >> n;
    ll maxi = 0, second_max = 0;
    vi width(n), height(n);
    ll width_sum = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> width[i] >> height[i];
        if (height[i] > maxi)
        {
            second_max = maxi;
            maxi = height[i];
        }
        else if (height[i] > second_max)
            second_max = height[i];
        
        width_sum += width[i];
    }

    // vector<ll> prefix_width(n);

    // prepare prefix arrays  
    // prepare_pref_sum(prefix_width, width); 
    // cout << width_sum << " " << maxi << " " << second_max << "\n";
    for(int i = 0; i < n; i++)
    {
        if (height[i] == maxi)
            cout << (width_sum - width[i]) * second_max << " ";
        else 
            cout << (width_sum - width[i]) * maxi << " ";
    }
    cout << "\n";
}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}