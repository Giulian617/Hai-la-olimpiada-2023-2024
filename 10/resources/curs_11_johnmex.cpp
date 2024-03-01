// Ilie Dumitru
#include<fstream>
#include<algorithm>
const int NMAX = 1024;

int N, M;
int minL[NMAX * NMAX], minC[NMAX * NMAX];
int maxL[NMAX * NMAX], maxC[NMAX * NMAX];
int lin[NMAX * NMAX], col[NMAX * NMAX];

int main()
{
	std::ifstream f("mex.in");
	std::ofstream g("mex.out");
	int i, j, x, _, l0, l1, c0, c1, l, r, mid;

	f >> N >> M;
	for(i = 0;i < N;++i)
		for(j = 0;j < M;++j)
		{
			f >> x;
			lin[x] = i;
			col[x] = j;
		}

	minL[0] = N;
	maxL[0] = -1;
	minC[0] = M;
	maxC[0] = -1;

	for(i = 1;i <= N * M;++i)
	{
		minL[i] = std::min(minL[i - 1], lin[i]);
		minC[i] = std::min(minC[i - 1], col[i]);
		maxL[i] = std::max(maxL[i - 1], lin[i]);
		maxC[i] = std::max(maxC[i - 1], col[i]);
	}

	f >> _;
	for(i = 0;i < _;++i)
	{
		f >> l0 >> c0 >> l1 >> c1;
		--l0;
		--l1;
		--c0;
		--c1;
		l = 0;
		r = N * M + 1;
		do
		{
			mid = l + ((r - l) >> 1);
			if(minL[mid] < l0 || minC[mid] < c0 || maxL[mid] > l1 || maxC[mid] > c1)
				r = mid;
			else
				l = mid;
		}while(r - l > 1);

		g << r << '\n';
	}

	return 0;
}