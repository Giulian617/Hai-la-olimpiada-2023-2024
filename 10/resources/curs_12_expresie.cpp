//Ilie Dumitru
#include<cstdio>
#include<cstring>
const int NMAX=100005;

int N;
char s[NMAX];

// In functiile recursive de mai jos parametrul este mereu primul caracter neprocesat
int expresie(int& i);
int termen(int& i);
int factor(int& i);
int numar(int& i);

int numar(int& i)
{
	int x = 0;

	// Ne oprim cand primul caracter neprocesat nu face parte dintr-un numar
	while(i < N && s[i] >= '0' && s[i] <= '9')
		x = x * 10 + s[i++] - '0';

	return x;
}

int factor(int& i)
{
	if(s[i] == '(')
	{
		// Trecem de (
		++i;

		int x = expresie(i);

		// Trecem de )
		++i;

		return x;
	}
	return numar(i);
}

int termen(int& i)
{
	int x = factor(i);

	while(i < N && (s[i] == '*' || s[i] =='/'))
	{
		char op = s[i];

		++i;

		int y = factor(i);

		if(op == '*')
			x *= y;
		else
			x /= y;
	}

	return x;
}

int expresie(int& i)
{
	int x = termen(i);

	while(i < N && (s[i] == '+' || s[i] == '-'))
	{
		char op = s[i];

		++i;

		int y = termen(i);

		if(op == '+')
			x += y;
		else
			x -= y;
	}

	return x;
}

int main()
{
	FILE* f = fopen("evaluare.in", "r"), *g = fopen("evaluare.out", "w");
	int i = 0;

	// Citire + asigurare ca nu exista \n la sfarsit
	fgets(s, NMAX, f);
	N = strlen(s);
	if(s[N - 1] == '\n')
		s[--N] = 0;

	// Afissare
	fprintf(g, "%d\n", expresie(i));

	fclose(f);
	fclose(g);
	return 0;
}