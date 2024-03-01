// Ilie Dumitru
#include<fstream>
const int NMAX = 100005, LMAX = 10;

int N;
int v[NMAX];
int cnt[LMAX];

int main()
{
	std::ifstream f("xum.in");
	std::ofstream g("xum.out");
	int i, x, j, xum = 0;
	long long sum = 0;

	f >> N;
	for(i = 1;i <= N;++i)
	{
		f >> x;
		xum = x = x ^ xum;
		for(j = 0;j < LMAX;++j)
		{
			if(x & (1 << j))
			{
				sum += (i - cnt[j]) << j;
				++cnt[j];
			}
			else
				sum += cnt[j] << j;
		}
	}

	g << sum;

	return 0;
}