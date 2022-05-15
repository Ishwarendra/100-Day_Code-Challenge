#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

ll inf = 1e18;

string hellfire(ll x, ll y)
{
	cout << "1 " << x << " " << y << endl;
	string status; cin >> status;
	return status;
}

string ringoffire(ll x1, ll y1, ll x2, ll y2)
{
	cout << "2 " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	string status; cin >> status;
	return status; 
}

void perform_op(ll &start, ll &end, char status, ll d)
{
	ll mid = (start + end)/2;
	switch (status)
	{
		case 'P': // we are bigger go low
			start -= d;
			end = mid - 1 + d;
			break;
			
		case 'N': // we are smaller go high
			start = mid + 1 - d;
			end += d; 
			break;
			
		default:
			start = mid - d; 
			end = mid + d;
	}
}

void solve(ll d)
{
	ll sx = -inf, ex = inf, sy = -inf, ey = inf;
	while(ex - sx + 1 > 4 or ey - sy + 1 > 4 or d == 0)
	{
		ll midx = (sx + ex) / 2;
		ll midy = (sy + ey) / 2;
		
		string status = hellfire(midx, midy);
		
		if (status == "O")
			return;
		
		perform_op(sx, ex, status[0], d);
		perform_op(sy, ey, status[1], d);
	}
	
	// Convert given range to form 4 * 4 grid
	if (ey - sy + 1 < 4)
		ey++;
	if (ex - sx + 1 < 4)
		ex++;
	
	
	// Now we have 4*4 grid
	
	// 1st operation ring of fire 
	string status = ringoffire(sx, sy, ex - 1, ey);
	
	if (status == "O")
		return;
	
	ll h, k;
	if (status == "IN")
		h = sx + 1;

	else
		h = ex;

	status = ringoffire(h - 1, sy, h + 1, ey - 1);
	if (status == "O")
		return;

	if (status == "IN")
		k = sy + 1;

	else
		k = ey;

	status = ringoffire(h - 1, k - 1, h + 1, k + 1);
	
	assert(status == "O");
}

int main()
{
    ll t, q, d;
    cin >> t >> q >> d;
    while(t--)
        solve(d);
    return 0;
}