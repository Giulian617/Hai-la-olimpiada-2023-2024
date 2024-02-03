// Ilie Dumitru
#include<fstream>
#include<algorithm>
const int NMAX=100005, BLKSZ=350;

int blockId(int i)
{
	return i/BLKSZ;
}

int N;
int v[NMAX], max[NMAX/BLKSZ+5];

int main()
{
	std::ifstream f("arbint.in");
	std::ofstream g("arbint.out");
	int i, op, Q, a, b;

	f>>N>>Q;
	for(i=0;i<N;++i)
	{
		f>>v[i];
		max[blockId(i)]=std::max(max[blockId(i)], v[i]);
	}
	for(int _=0;_<Q;++_)
	{
		f>>op>>a>>b;
		if(op)
		{
			--a;
			if(max[blockId(a)]==v[a] && v[a]>b)
			{
				max[blockId(a)]=v[a]=b;
				for(i=blockId(a)*BLKSZ;i<N && i<(blockId(a)+1)*BLKSZ;++i)
					max[blockId(a)]=std::max(max[blockId(a)], v[i]);
			}
			else
			{
				v[a]=b;
				max[blockId(a)]=std::max(max[blockId(a)], b);
			}
		}
		else
		{
			--a;
			--b;
			int ans=v[a];
			for(i=a;i<=b && blockId(i)==blockId(a);++i)
				ans=std::max(ans, v[i]);
			for(i=b;i>=a && blockId(i)==blockId(b);--i)
				ans=std::max(ans, v[i]);
			for(i=blockId(a)+1;i<blockId(b);++i)
				ans=std::max(ans, max[i]);
			g<<ans<<'\n';
		}
	}

	return 0;
}