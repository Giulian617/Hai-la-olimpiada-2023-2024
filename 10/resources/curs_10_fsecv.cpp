// Ilie Dumitru
#include<fstream>
#include<iostream>
#include<algorithm>
const int NMAX=100005, BLKSZ=350;

int blockId(int i)
{
	return i/BLKSZ;
}

struct query
{
	int l, r, k, idx;

	friend bool operator<(query a, query b)
	{
		if(blockId(a.l)==blockId(b.l))
		{
			if(blockId(a.l)%2)
				return blockId(a.r)>blockId(b.r);
			return blockId(a.r)<blockId(b.r);
		}
		return a.l<b.l;
	}
};

int N, Q;
int v[NMAX];
query q[NMAX];
int ans[NMAX];
int frcv[NMAX*2];
int cnt[NMAX];

int main()
{
	std::ifstream f("fsecv.in");
	std::ofstream g("fsecv.out");
	int i, l, r;

	f>>N>>Q;
	for(i=0;i<N;++i)
	{
		f>>v[i];
		v[i]+=NMAX;
	}
	for(i=0;i<Q;++i)
	{
		f>>q[i].l>>q[i].r>>q[i].k;
		--q[i].l;
		--q[i].r;
		q[i].idx=i;
	}

	std::sort(q, q+Q);
	l=r=0;

	for(i=0;i<Q;++i)
	{
		while(l>q[i].l)
		{
			--l;
			int& fr=frcv[v[l]];
			--cnt[fr];
			++fr;
			++cnt[fr];
		}
		while(r<=q[i].r)
		{
			int& fr=frcv[v[r]];
			--cnt[fr];
			++fr;
			++cnt[fr];
			++r;
		}

		while(l<q[i].l)
		{
			int& fr=frcv[v[l]];
			--cnt[fr];
			--fr;
			++cnt[fr];
			++l;
		}
		while(r-1>q[i].r)
		{
			--r;
			int& fr=frcv[v[r]];
			--cnt[fr];
			--fr;
			++cnt[fr];
		}

		ans[q[i].idx]=cnt[q[i].k];
	}

	for(i=0;i<Q;++i)
		g<<ans[i]<<'\n';

	return 0;
}