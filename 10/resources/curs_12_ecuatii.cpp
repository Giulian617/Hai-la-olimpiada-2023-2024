// Ilie Dumitru
#include<fstream>
#include<string>
#include<iomanip>
const int NMAX = 260;

int N;
std::string s;

void solve(std::ofstream& g)
{
	int a = 0, b = 0, i, x, egal = 1;
	char semn;

	for(i = 0;i < N;)
	{
		if(s[i] == '=')
		{
			egal = -1;
			++i;
		}

		semn = 1;

		if(s[i] == '+')
			++i;
		else if(s[i] == '-')
		{
			semn = -1;
			++i;
		}

		if(s[i] == 'x')
			x = 1;
		else
			for(x = 0;i < N && s[i] >= '0' && s[i] <= '9';++i)
				x = x * 10 + s[i] - '0';

		if(s[i] == 'x')
		{
			++i;
			a += egal * semn * x;
		}
		else
			b += egal * semn * x;
	}

	if(a == 0)
		if(b == 0)
			g << "infinit\n";
		else
			g << "imposibil\n";
	else
		g << std::setprecision(4) << std::fixed << -b / (double)a << '\n';
}

int main()
{
	std::ifstream f("ecuatii.in");
	std::ofstream g("ecuatii.out");
	int _;

	f >> _;
	getline(f, s);
	do
	{
		getline(f, s);
		N = s.size();
		if(s[N - 1] == '\n')
			s[--N] = 0;

		solve(g);
	}while(--_);

	return 0;
}