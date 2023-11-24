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
	int i, j, min;
	long long suma=0;

	f>>N>>K;
	for(i=0;i<N;++i)
		f>>v[i];

	for(i=K-1;i<N;++i)
	{
		for(min=v[i], j=i-K+1;j<i;++j)
			if(min>v[j])
				min=v[j];

		suma+=min;
	}

	g<<suma<<'\n';

	return 0;
}