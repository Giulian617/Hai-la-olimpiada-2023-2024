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
	int i;
	long long suma=0;

	f>>N>>K;
	for(i=0;i<N;++i)
		f>>v[i];

	for(i=0;i<K;++i)
	{
		while(!dq.empty() && v[dq.back()]>=v[i])
			dq.pop_back();
		dq.push_back(i);
	}

	suma=v[dq.front()];

	for(;i<N;++i)
	{
		while(!dq.empty() && v[dq.back()]>=v[i])
			dq.pop_back();
		if(!dq.empty() && dq.front()==i-K)
			dq.pop_front();
		dq.push_back(i);

		suma+=v[dq.front()];
	}

	g<<suma<<'\n';

	return 0;
}