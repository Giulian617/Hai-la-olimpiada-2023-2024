//Ilie Dumitru
#include<fstream>
#include<deque>
const int NMAX=5000005;

int N, K;
int v[NMAX];
std::deque<int> dq;

int main()
{
	std::ifstream f("deque.in");
	std::ofstream g("deque.out");
	int i, j, posmin;
	long long suma=0;

	f>>N>>K;
	for(i=0;i<N;++i)
		f>>v[i];

	posmin=-1;
	for(i=K-1;i<N;++i)
	{
		if(posmin==i-K)
		{
			posmin=i;
			for(j=i-K+1;j<i;++j)
				if(v[j]<v[posmin])
					posmin=j;
		}
		else if(v[i]<v[posmin])
			posmin=i;

		suma+=v[posmin];
	}

	g<<suma<<'\n';

	return 0;
}