//Ilie Dumitru
#include<iostream>
typedef long long ll;
const int NMAX=5005;
const ll MOD=998244353;

int N;
int v[NMAX];

ll solve(int l, int r, bool reml, bool remr)
{
	if(l > r)
		return 1LL;
	if(l == r)
		return 1LL + (int)(reml || remr);

	int minpos = l, i;

	for(i = l + 1;i <= r;++i)
		if(v[minpos] > v[i])
			minpos = i;

	ll keep = solve(l, minpos - 1, reml, 1)*solve(minpos + 1, r, 1, remr)%MOD;
	ll rem=0;

	if(reml && remr)
		rem = MOD - 1;
	if(reml)
		rem = (rem + solve(minpos + 1, r, 1, remr)) % MOD;
	if(remr)
		rem = (rem + solve(l, minpos - 1, reml, 1)) % MOD;

	return (keep + rem)%MOD;
}

int main()
{
	int i;

	std::cin >> N;
	for(i = 0;i < N;++i)
		std::cin >> v[i];

	std::cout << solve(0, N-1, 0, 0);

	return 0;
}