#include <bits/stdc++.h>
using namespace std;

int number_of_wins(vector<int> &bessie, vector<int> &elsie,
	function<bool(int, int)> cmp)
{
	int n = size(bessie);
	assert(size(bessie) == size(elsie));

	sort(begin(bessie), end(bessie), cmp);
	sort(begin(elsie), end(elsie), cmp);

	int bpos = 0;  // keep track of index of card which bessie uses in current move
	int wins = 0;

	for (int i = 0; i < n; i++)
	{
		// Check if Bessie can win. If she can't, she'll just use her worst card.
		if (cmp(bessie[bpos], elsie[i]))
		{
			wins++;
			bpos++;
		}
	}

	return wins;
}

int main()
{
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);

	int n;
	cin >> n;

	map<int, int> elsie_has;

	// First and second half are independent of each other. 
	vector<int> bessie_first, bessie_second;
	vector<int> elsie_first(n / 2), elsie_second(n / 2);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		elsie_has[x] = 1;

		if (i < n / 2) 
		{
			elsie_first[i] = x;
		}
		else
		{
			elsie_second[i - n / 2] = x;
		}
	}

	for (int i = 2 * n; i > 0; i--)
	{
		if (elsie_has.find(i) == elsie_has.end())  // elsie does not have this card
		{
			if (size(bessie_first) < n / 2)  // bigger card must be used in first half
			{
				bessie_first.push_back(i);
			}
			else
		    {
				bessie_second.push_back(i);
			}
		}
	}

	int ans = 0;

	// First half person with card of larger value wins
	ans += number_of_wins(bessie_first, elsie_first, 
		[](int a, int b) { return a > b; });

	// In second half of game person with card of smaller value win
	ans += number_of_wins(bessie_second, elsie_second, 
		[](int a, int b) { return a < b; });

	cout << ans << endl; 
}