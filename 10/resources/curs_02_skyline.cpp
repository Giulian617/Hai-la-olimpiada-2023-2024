//Ilie Dumitru
#include<fstream>
#include<iostream>
#include<stack>
const int NMAX=40005;

int N;
int l[NMAX], h[NMAX];
long long sumPart[NMAX];

long long sumaInterval(int st, int dr)
{
	return sumPart[dr+1]-sumPart[st];
}

void calcSumPart()
{
	int i;

	for(i=0;i<N;++i)
		sumPart[i+1]=sumPart[i]+l[i];
}

int left[NMAX], right[NMAX];

void skyline()
{
	int i;
	std::stack<int> stiva;

	for(i=0;i<N;++i)
	{
		while(!stiva.empty() && h[stiva.top()]>=h[i])
			stiva.pop();

		if(stiva.empty())
			left[i]=-1;
		else
			left[i]=stiva.top();

		stiva.push(i);
	}

	while(!stiva.empty())
		stiva.pop();

	for(i=N-1;i>-1;--i)
	{
		while(!stiva.empty() && h[stiva.top()]>=h[i])
			stiva.pop();

		if(stiva.empty())
			right[i]=N;
		else
			right[i]=stiva.top();

		stiva.push(i);
	}
}

long long solve_fast()
{
	int i;
	long long ans=0, curr;

	calcSumPart();
	skyline();

	for(i=0;i<N;++i)
	{
		curr=h[i]*sumaInterval(left[i]+1, right[i]-1);
		if(curr>ans)
			ans=curr;
	}

	return ans;
}

long long solve_slow()
{
	int i, j;
	long long ans=0, curr, minH, len;

	for(i=0;i<N;++i)
	{
		minH=h[i];
		len=l[i];

		curr=minH*len;
		if(curr>ans)
			ans=curr;

		for(j=i+1;j<N;++j)
		{
			if(h[j]<minH)
				minH=h[j];
			len+=l[j];

			curr=minH*len;
			if(curr>ans)
				ans=curr;
		}
	}

	return ans;
}

int main()
{
	int i;
	std::ifstream f("skyline.in");
	std::ofstream g("skyline.out");

	f>>N;
	for(i=0;i<N;++i)
		f>>h[i]>>l[i];

	g<<solve_fast();
	return 0;
}