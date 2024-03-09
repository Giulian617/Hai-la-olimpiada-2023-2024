// Ilie Dumitru
#include<fstream>
#include<string>
#include<map>

std::string s;
std::map<std::string, int> mp;

int main()
{
	std::ifstream f("reteta.in");
	std::ofstream g("reteta.out");
	int i, x;
	std::string aux = "";

	getline(f, s);
	for(i = 0;i < (int)s.size();++i)
	{
		if(s[i] == ')')
			aux = ")";
		else if(s[i] >= '0' && s[i] <='9')
		{
			x = 0;
			while(i < (int)s.size() && s[i] >= '0' && s[i] <= '9')
				x = x * 10 + s[i++] - '0';
			--i;
			mp[aux] += x;
			aux = "";
		}
		else if(s[i] != '(' && s[i] != ' ')
			aux += s[i];
	}

	g << mp[")"] << '\n';
	mp.erase(mp.find(")"));
	for(std::pair<const std::string, int> p : mp)
		g << p.first << ' ' << p.second << '\n';

	return 0;
}