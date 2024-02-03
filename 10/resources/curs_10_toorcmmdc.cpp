// Ilie Dumitru
#include<fstream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
const int NMAX=100005, BLKSZ=350;

int v[NMAX];
int blk[NMAX/BLKSZ+5], NBLK;
int cmmdc;
std::set<int> avail;
std::map<int, std::vector<int> > where;

int blockId(int i)
{
	return i/BLKSZ;
}

void recalc(int blkId)
{
	int i, end=(blkId+1)*BLKSZ;

	blk[blkId]=0;
	for(i=blkId*BLKSZ;i<end;++i)
		blk[blkId]=std::__gcd(blk[blkId], v[i]);

	for(i=cmmdc=0;i<NBLK;++i)
		cmmdc=std::__gcd(cmmdc, blk[i]);
}

int main()
{
	std::ifstream f("toorcmmdc.in");
	std::ofstream g("toorcmmdc.out");
	int x, _, i;
	std::string s;
	std::set<int>::iterator it;
	std::map<int, std::vector<int> >::iterator it_mp;

	f>>_;
	NBLK=blockId(_-1)+1;
	f.get();
	for(i=0;i<_;++i)
		avail.insert(i);

	while(_--)
	{
		f>>s>>x;
		f.get();

		if(s[0]=='+')
		{
			it=avail.begin();
			i=*it;
			avail.erase(it);
			where[x].push_back(i);
			v[i]=x;
			i=blockId(i);
			blk[i]=std::__gcd(blk[i], x);
			cmmdc=std::__gcd(cmmdc, x);
		}
		else
		{
			it_mp=where.find(x);
			if(it_mp!=where.end() && !it_mp->second.empty())
			{
				i=it_mp->second.back();
				it_mp->second.pop_back();

				v[i]=0;
				recalc(blockId(i));
			}
		}

		if(cmmdc)
			g<<cmmdc<<'\n';
		else
			g<<"1\n";
	}

	return 0;
}