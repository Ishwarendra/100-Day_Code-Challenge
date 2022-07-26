#include<bits/stdc++.h>

const int TOTAL = 52;

int main()
{
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	std::string recordings;
	std::cin >> recordings;

	std::vector<int> first_found(26, -1);
	std::set<std::pair<char, char>> crossings;

	for (int i = 0; i < TOTAL; i++)
	{
		if (first_found[recordings[i] - 'A'] == -1)
		{
			// First occurence of this letter
			first_found[recordings[i] - 'A'] = i;
			continue;
		}
		else
		{
			// Make a list of all cows that have an entry/exit point
			// between the entry and exit point of the current cow

			std::set<char> appearances;

			int start = first_found[recordings[i] - 'A'] + 1, end = i;
			for (int j = start; j < end; j++)
			{
				if (appearances.count(recordings[j]))
					appearances.erase(recordings[j]);
				else
					appearances.insert(recordings[j]);
			}

			// Add all pairs to the crossings list if not already in it
			for (int k : appearances)
			{
				if (!crossings.count({recordings[i], k}) && !crossings.count({k, recordings[i]}))
					crossings.insert({recordings[i], k});
			}
		}
	}

	std::cout << crossings.size() << "\n";

	return 0;
}