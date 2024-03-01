//Ilie Dumitru
#include<iostream>
typedef long long ll;
const int NMAX = 2000005;
const ll MOD = 998244353;

ll fastExp(ll a, int b)
{
	if(b == 0)
		return 1;
	if(b == 1)
		return a;

	ll x = fastExp(a, b / 2);
	x = x * x % MOD;
	if(b & 1)
		x = x * a % MOD;
	return x;
}

int v[4];
ll fact[NMAX];
ll ifact[NMAX];

void precalc()
{
	int i;

	fact[0] = fact[1] = 1;
	for(i = 2;i < NMAX;++i)
		fact[i] = fact[i - 1] * i % MOD;

	ifact[NMAX - 1] = fastExp(fact[NMAX - 1], MOD - 2);
	for(i = NMAX - 2; i > -1; --i)
		ifact[i] = ifact[i + 1] * (i + 1) % MOD;
}

ll comb(int N, int K)
{
	if(N < 0 || K < 0 || N < K)
		return 0;
	return fact[N] * ifact[K] % MOD * ifact[N - K] % MOD;
}

void solve()
{
	int i;
	ll ans=0;

	for(i = 0;i < 4;++i)
		std::cin >> v[i];

	if(v[0] == v[1] + 1)
		ans = comb(v[1] + v[3], v[1]) * comb(v[1] + v[2], v[1]) % MOD;
	else if(v[0] + 1 == v[1])
		ans = comb(v[0] + v[3], v[0]) * comb(v[0] + v[2], v[0]) % MOD;
	else if(v[0] == v[1] && v[0])
		ans = (comb(v[1] + v[3], v[1]) * comb(v[1] + v[2] - 1, v[1] - 1) % MOD + comb(v[1] + v[3] - 1, v[1] - 1) * comb(v[1] + v[2], v[1]) % MOD) % MOD;
	else if(v[0] == v[1])
		ans = (!v[2] || !v[3]);

	std::cout << ans << '\n';
}

int main()
{
	int _;

	precalc();
	std::cin >> _;
	do
	{
		solve();
	}while(--_);

	return 0;
}