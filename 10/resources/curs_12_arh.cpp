// Ilie Dumitru
#include<fstream>
#include<string>
const int NMAX = 260;

int N;
std::string s;

std::string deArh(int& i)
{
	std::string ans = "";

	while(i < (int)s.size() && s[i] != ')' && s[i] != ']' && s[i] != '*')
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			int x = 0;

			while(s[i] >= '0' && s[i] <= '9')
			{
				x = x * 10 + s[i] - '0';
				++i;
			}

			++i;
			std::string rep = deArh(i);
			++i;

			while(x--)
				ans += rep;
		}
		else if(s[i] == '[')
		{
			++i;
			if(s[i] == '*')
			{
				++i;
				std::string aux = deArh(i);
				ans += aux;
				for(int j = aux.size() - 1;j > -1;--j)
					ans += aux[j];
			}
			else
			{
				std::string aux = deArh(i);
				ans += aux;
				for(int j = aux.size() - 2;j > -1;--j)
					ans += aux[j];
				++i;
			}
			++i;
		}
		else
			ans += s[i++];
	}

	return ans;
}

int main()
{
	std::ifstream f("arh.in");
	std::ofstream g("arh.out");
	int i, cnt = 0;

	getline(f, s);
	for(i = 0;i < (int)s.size();++i)
		cnt += (s[i] == '(' || s[i] == '[');
	i = 0;
	g << cnt << '\n' << deArh(i) << '\n';

	return 0;
}