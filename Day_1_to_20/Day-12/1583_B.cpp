#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<bool> present(n + 1);

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        present[b] = true;
    }
    
    int can_be_in_path = 1;
    for(int i = 1; i <= n; i++)
    {
        if (present[i] == false)
        {
            can_be_in_path = i;
            break;
        }
    }

    int node = 1;
    while(node <= n)
    {
        if (node == can_be_in_path)
        {
            node++;
            continue;
        }
        cout << can_be_in_path << " " << node << "\n";
        node++;
    }
}

int main()
{
    FIO
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}