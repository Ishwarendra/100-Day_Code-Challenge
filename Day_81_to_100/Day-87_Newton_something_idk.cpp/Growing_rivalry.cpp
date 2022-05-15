#include<bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::string s; 
	std::cin >> n >> s;
	
	int nutan = 0, tusla = 0;
	
	for (char &ch : s)
	{
		nutan += (ch == 'N');
		tusla += (ch == 'T');
	}
	
	std::cout << (nutan > tusla ? "Nutan\n" : "Tusla\n");
	
	return 0;
}