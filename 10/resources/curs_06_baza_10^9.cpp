// Ilie Dumitru
#include<fstream>
#include<iostream>
#include<iomanip>
const int NMAX=1024;
const long long int BAZA=1000000000;

struct big
{
	int N;
	long long int cifre[NMAX];

	big()
	{
		this->N=1;
		for(int i=0;i<NMAX;++i)
			this->cifre[i]=0;
	}

	friend std::istream& operator>>(std::istream& in, big& x)
	{
		std::string s;
		int i, p10, curr;

		in>>s;
		for(i=0;i*2<(int)s.size();++i)
			std::swap(s[i], s[(int)s.size()-1-i]);
		for(i=0, curr=0, p10=1;i<(int)s.size();++i)
		{
			x.cifre[curr]+=p10*(s[i]-'0');
			p10*=10;
			if(p10==BAZA)
			{
				p10=1;
				++curr;
			}
		}

		x.N=curr+1;
		if(x.N>1 && x.cifre[x.N-1]==0)
			--x.N;

		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const big& x)
	{
		out<<x.cifre[x.N-1]<<std::setw(9)<<std::setfill('0');
		for(int i=x.N-2;i>-1;--i)
			out<<x.cifre[i];
		return out;
	}

	// a += b
	friend big& operator+=(big& a, long long int b)
	{
		int i;
		long long int t;

		for(i=t=0;b || t;++i)
		{
			a.cifre[i]+=b%BAZA+t;
			t=a.cifre[i]/BAZA;
			a.cifre[i]%=BAZA;
			b/=BAZA;
		}

		if(i>a.N)
			a.N=i;

		return a;
	}

	// a -= b
	friend big& operator-=(big& a, long long int b)
	{
		int i, t=0;

		for(i=0;i<a.N || t;++i)
		{
			a.cifre[i]-=b%BAZA;
			b/=BAZA;
			if(a.cifre[i]<0)
			{
				a.cifre[i]+=BAZA;
				--a.cifre[i+1];
				t=1;
			}
			else
				t=0;
		}

		while(a.N>1 && a.cifre[a.N-1]==0)
			--a.N;

		return a;
	}

	// a -= b
	friend big& operator-=(big& a, const big& b)
	{
		int i, t=0;

		for(i=0;i<a.N || t;++i)
		{
			a.cifre[i]-=b.cifre[i];
			if(a.cifre[i]<0)
			{
				a.cifre[i]+=BAZA;
				--a.cifre[i+1];
				t=1;
			}
			else
				t=0;
		}

		while(a.N>1 && a.cifre[a.N-1]==0)
			--a.N;

		return a;
	}

	// a *= b
	// b <= 10 ^ 9
	friend big& operator*=(big& a, long long int b)
	{
		if(b==0)
		{
			return a=big();
		}

		int i;
		long long int t, aux;

		for(i=t=0;t || i<a.N;++i)
		{
			aux=a.cifre[i]*b+t;
			a.cifre[i]=aux%BAZA;
			t=aux/BAZA;
		}

		if(i>a.N)
			a.N=i;

		return a;
	}

	// a += b
	friend big& operator+=(big& a, const big& b)
	{
		int i, t;

		for(i=t=0;i<b.N || t;++i)
		{
			a.cifre[i]+=b.cifre[i]+t;
			t=a.cifre[i]/BAZA;
			a.cifre[i]%=BAZA;
		}

		if(i>a.N)
			a.N=i;

		return a;
	}

	// a *= b
	friend big& operator*=(big& a, const big& b)
	{
		int i, j;
		long long int t;
		big ans;

		ans.N=a.N+b.N-1;
		for(i=0;i<a.N;++i)
			for(j=t=0;j<b.N || t;++j)
			{
				t=ans.cifre[i+j]+a.cifre[i]*b.cifre[j]+t;
				ans.cifre[i+j]=t%BAZA;
				t/=BAZA;
				if(ans.N<=i+j)
					ans.N=i+j+1;
			}

		if(ans.cifre[ans.N-1]==0)
		{
			ans.N=1;
		}

		return a=ans;
	}

	// a /= b and return a % b
	friend int operator/=(big& a, int b)
	{
		if(b==0)
		{
			return 0;
		}

		int i;
		long long int total;

		for(i=a.N-1, total=0;i>-1;--i)
		{
			total=total*BAZA+a.cifre[i];
			a.cifre[i]=total/b;
			total%=b;
		}

		while(a.N>1 && a.cifre[a.N-1]==0)
			--a.N;

		return total;
	}

	// a % b
	friend int operator%(const big& a, int b)
	{
		if(b==0)
		{
			return 0;
		}

		int i, total;

		for(i=a.N-1, total=0;i>-1;--i)
		{
			total=(total*BAZA+a.cifre[i])%b;
		}

		return total;
	}
};