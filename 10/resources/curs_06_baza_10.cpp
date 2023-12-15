// Ilie Dumitru
#include<fstream>
#include<iostream>
const int NMAX=205;

struct big
{
	int N;
	int cifre[NMAX];

	big()
	{
		this->N=1;
		for(int i=0;i<NMAX;++i)
			this->cifre[i]=0;
	}

	friend std::istream& operator>>(std::istream& in, big& x)
	{
		in>>x.N;
		for(int i=x.N-1;i>-1;--i)
			in>>x.cifre[i];
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const big& x)
	{
		for(int i=x.N-1;i>-1;--i)
			out<<x.cifre[i];
		return out;
	}

	// a += b
	friend big& operator+=(big& a, int b)
	{
		int i, t;

		for(i=t=0;b || t;++i)
		{
			a.cifre[i]+=b%10+t;
			t=a.cifre[i]/10;
			a.cifre[i]%=10;
			b/=10;
		}

		if(i>a.N)
			a.N=i;

		return a;
	}

	// a -= b
	friend big& operator-=(big& a, int b)
	{
		int i, t=0;

		for(i=0;i<a.N || t;++i)
		{
			a.cifre[i]-=b%10;
			b/=10;
			if(a.cifre[i]<0)
			{
				a.cifre[i]+=10;
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
				a.cifre[i]+=10;
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
			a.cifre[i]=aux%10;
			t=aux/10;
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
			t=a.cifre[i]/10;
			a.cifre[i]%=10;
		}

		if(i>a.N)
			a.N=i;

		return a;
	}

	// a *= b
	friend big& operator*=(big& a, const big& b)
	{
		int i, j;
		big ans;

		ans.N=a.N+b.N-1;
		for(i=0;i<a.N;++i)
			for(j=0;j<b.N;++j)
				ans.cifre[i+j]+=a.cifre[i]*b.cifre[j];

		if(ans.cifre[ans.N-1]==0)
		{
			ans.N=1;
		}
		else
		{
			for(i=j=0;i<ans.N || j;++i)
			{
				ans.cifre[i]+=j;
				j=ans.cifre[i]/10;
				ans.cifre[i]%=10;
			}

			if(i>ans.N)
				ans.N=i;
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

		int i, total;

		for(i=a.N-1, total=0;i>-1;--i)
		{
			total=total*10+a.cifre[i];
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
			total=(total*10+a.cifre[i])%b;
		}

		return total;
	}
};