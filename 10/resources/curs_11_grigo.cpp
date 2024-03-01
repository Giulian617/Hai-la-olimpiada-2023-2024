// Ilie Dumitru
#include<fstream>
#include<algorithm>
const int NMAX = 100005;
const int MOD = 1000003;

int N, M;
int v[NMAX];

int main()
{
	std::ifstream f("grigo.in");
	std::ofstream g("grigo.out");
	int i, j, ways = 1;

	f >> N >> M;
	for(i = 0;i < M;++i)
		f >> v[i];
	std::sort(v, v + M);

	for(j = i = 0;i < N;++i)
	{
		if(j < M && i + 1 == v[j])
			++j;
		else
			ways = ways * (long long)i % MOD;
	}

	g << ways;

	return 0;
}